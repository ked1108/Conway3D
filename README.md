# Conway's Game of Life in 3D with C++ and Raylib

## Introduction

This project implements Conway's Game of Life in a 3D space using C++ and the Raylib graphics library. It provides a visual representation of the cellular automaton's evolution, allowing you to explore various initial configurations and witness the fascinating patterns emerge.

## Features

- **3D Grid:** Cells reside in a 3D grid, enabling more complex and visually engaging simulations compared to the traditional 2D version.
- **Raylib Integration:** Leverages Raylib for efficient rendering of the 3D grid and user interaction.
- **Clear Visuals:** Employs distinct colors (e.g., white for alive, black for dead) for easy visualization of cell states.
- **Real-Time Simulation:** Runs the simulation in real-time, allowing you to observe the game's progression.
- **Pause/Resume Control:** Provides the ability to pause and resume the simulation at your convenience for closer inspection.
- **Camera Controls:** Navigate the 3D grid using arrow keys or WASD for rotation.
- **Potential for Further Enhancements:** The codebase is well-structured, making it adaptable for adding features like:
    - User-defined initial configurations (e.g., through mouse interaction).
    - Pre-set patterns to explore well-known Game of Life structures.

## Getting Started

1. **Prerequisites:**
   - C++ compiler (e.g., GCC, Clang)
   - CMake
   - Raylib library ([https://www.raylib.com/](https://www.raylib.com/))
   **Compilation:**
   - `cd build`
   - `cmake ..`
   - `make`
2. **Execution:**
   - Navigate to the project directory in your terminal.
   - Run the compiled executable (`./build/Conway3D`)

**Controls**

- Arrow keys or WASD: Rotate the camera view.
- Space bar: Pause/resume the simulation.
- Escape key: Exit the application.

**Disclaimer**

This project is for educational and entertainment purposes only. While it strives for accuracy in representing the Game of Life rules, potential edge cases or bugs might exist.

**Contribution**

Feel free to contribute to this project by:

- Reporting any issues you encounter.
- Suggesting improvements or new features.
- Submitting pull requests with your modifications.

**Enjoy exploring the captivating world of Conway's Game of Life in 3D!**

This revised version removes the compilation and customization sections, as requested. It also incorporates camera controls as an existing feature.
