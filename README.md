# ICS 46: Homework 9

Welcome to ICS 46 Homework 9! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw9`, then push the `hw9` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Checkout hw9 from the public branch:
git checkout hw9
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw9` with the following structure:

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   └── student_gtests.cpp
└── src
    ├── dijkstras.cpp
    ├── dijkstras.h
    ├── dijkstras_main.cpp
    ├── ladder.cpp
    ├── ladder.h
    ├── ladder_main.cpp
    ├── largest.txt
    ├── large.txt
    ├── medium.txt
    ├── small.txt
    └── words.txt
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`.

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only the dijkstras_main.cpp:
cmake --build build --target dijkstra_main

# Build only the ladder_main.cpp:
cmake --build build --target ladder_main

# Build only the student_gtests.cpp:
cmake --build build --target student_gtests
```

To run the above targets after compiling them:

```bash
./build/dijkstra_main       # Runs the 'main' function from src/dijkstras_main.cpp
./build/ladder_main         # Runs the 'main' function from src/ladder_main.cpp
./build/student_gtests      # Runs the student set of gtests
```

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push`
your changes to your private repository, and then submitting the `hw9` branch to `Gradescope`. Or,
you can upload files directly, namely: `ladder_main.cpp`, `ladder<.h/.cpp>`, `dijkstras_main.cpp`,
and `dijkstras<.h/.cpp>`.
