# Quadratic equation solver

Written as part of C/C++ programming course at ISP RAS.

## Prerequisites

* cpp
* cmake
* doxygen (optional)

This project was developed in WSL Ubuntu.

## How to build

First of all, execute `cmake -B build` from the project root.

Then `cmake --build build` command will compile application and tests.

### Documentation

If Doxygen is found, `cmake --build build -t docs` compiles HTML documentation.

### Console application

`cmake --build build -t app` compiles main application and places it in `build/src` directory.

You can launch app manually with `build/src/main`.

### Tests

`cmake --build build -t app` compiles test runner and places it in `build/src` directory.

You can launch tests manually with `build/src/tests`.
