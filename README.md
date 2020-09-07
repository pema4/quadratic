# Quadratic equation solver

Written as part of C/C++ programming course at ISP RAS.

## Prerequisites

* cpp
* doxygen
* make

This project was developed in Ubuntu.

## How to build

### Documentation

`make docs` compiles HTML documentation with Doxygen and places it inside `docs` subdirectory.

### Console application

`make app` compiles solver to file `bin/app`.

You can launch app manually or using `make runApp`, it builds application and launches it for you

### Tests

`make tests` compiles test runner to file `bin/tests`.

Again, you can launch tests manually or using `make runTests`, it builds and launches tests for you.

### Everything

Just `make` will compile application, tests and documentation.