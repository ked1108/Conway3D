#include "conway.cpp"
#include "raylib.h"
#include <cmath>
#include <cstdlib>
#include <string>

typedef struct Timer {
  double startTime; // Start time (seconds)
  double lifeTime;  // Lifetime (seconds)
} Timer;

void StartTimer(Timer *timer, double lifetime) {
  timer->startTime = GetTime();
  timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer) {
  return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer) { return GetTime() - timer.startTime; }

int main(void) {
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 1080;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "Conways Game of Life But 3D");

  Camera3D camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
  camera.up =
      (Vector3){0.0f, 1.0f, 0.0f}; // Camera up vector (rotation towards target)
  camera.fovy = 45.0f;             // Camera field-of-view Y
  camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

  const int numOfBlocks = 5;

  Grid conway = Grid(numOfBlocks);

  Timer t;
  StartTimer(&t, 60.0);

  DisableCursor();

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    // Update
    //----------------------------------------------------------------------------------

    UpdateCamera(&camera, CAMERA_FREE);
    if (IsKeyPressed('Z'))
      camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
      conway.nextState();

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(RAYWHITE);
    BeginMode3D(camera);

    // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED)1;
    DrawGrid(100, 1.0f);

    const float scale = 2.0f;

    for (int i = 0; i < numOfBlocks; i++) {
      for (int j = 0; j < numOfBlocks; j++) {
        for (int k = 0; k < numOfBlocks; k++) {
          Pos p = {i, j, k};
          const float blockScale = 2.0;
          Vector3 cubePos = {
              (float)(i - numOfBlocks / 2) * (scale),
              (float)(j - numOfBlocks / 2) * (scale),
              (float)(k - numOfBlocks / 2) * (scale),
          };

          Color alive =
              ColorFromHSV((float)(((i + j + k) * 18) % 360), 0.75f, 0.9f);
          Color dead = WHITE;
          float cubeSize = (2.4f - scale) * blockScale;

          bool state = conway.get_state(p);
          if (state) {
            DrawCube(cubePos, cubeSize, cubeSize, cubeSize, alive);
          } else {
            DrawSphere(cubePos, cubeSize, dead);
          }

          // DrawCubeWires(cubePos, blockScale, blockScale, blockScale,
          // DARKGREEN);
        }
      }
    }

    EndMode3D();

    DrawFPS(10, 10);

    DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines(10, 10, 320, 93, BLUE);

    DrawText("Free camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
    DrawText("- Z to zoom to (0, 0, 0)", 40, 80, 10, DARKGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow(); // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}
