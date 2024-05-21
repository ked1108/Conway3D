#include <functional>
#include <random>

typedef struct Pos {
  int x;
  int y;
  int z;
} Pos;

class Grid {
  int size;
  bool *grid;

private:
  Pos grid_to_3d(int pos) {
    Pos p;
    p.x = pos % this->size;
    p.y = (pos / this->size) % this->size;
    p.z = pos / (this->size * this->size);

    return p;
  }

  int grid_to_1d(Pos p) {
    int i = p.x + this->size * (p.y + this->size * p.z);
    return i;
  }

public:
  Grid(int size) {
    this->size = size;
    this->grid = new bool[size * size * size];

    std::random_device dev;
    auto gen = std::bind(std::uniform_int_distribution<>(1, 100),
                         std::default_random_engine());

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
          if (gen() % 2 == 0) {
            this->grid[i + size * (j + size * k)] = true;
          } else {
            this->grid[i + size * (j + size * k)] = false;
          }
        }
      }
    }
  }

  ~Grid() { free(this->grid); }

  int getNeighbours(Pos p) {
    int alive = 0;

    for (int a = -1; a < 2; a++) {
      for (int b = -1; b < 2; b++) {
        for (int c = -1; c < 2; c++) {
          Pos n = {p.x + a, p.y + b, p.z + c};
          if (n.x < 0 || n.y < 0 || n.z < 0)
            continue;
          if (n.x >= this->size || n.y >= this->size || n.z >= this->size)
            continue;
          if (a == 0 && b == 0 && c == 0)
            continue;
          if (this->grid[this->grid_to_1d(n)]) {
            alive++;
          }
        }
      }
    }

    return alive;
  }

  void nextState() {
    int dummy[size * size * size];

    for (int i = 0; i < this->size; i++) {
      for (int j = 0; j < this->size; j++) {
        for (int k = 0; k < this->size; k++) {

          Pos p = {i, j, k};
          int alive = getNeighbours(p);

          if (this->grid[this->grid_to_1d(p)]) {
            if (alive < 2) {
              dummy[this->grid_to_1d(p)] = false;
            } else if (alive > 4) {
              dummy[this->grid_to_1d(p)] = false;
            }
          } else {
            if (alive == 3) {
              dummy[this->grid_to_1d(p)] = true;
            } else {
              dummy[this->grid_to_1d(p)] = false;
            }
          }
        }
      }
    }

    for (int i = 0; i < size * size * size; i++) {
      grid[i] = dummy[i];
    }
  }

  bool get_state(Pos p) { return this->grid[grid_to_1d(p)]; }
  void set_state(Pos p) { this->grid[grid_to_1d(p)] = !this->grid_to_1d(p); }
};
