# ICS 46: Homework 7

Welcome to ICS 46 Homework 7! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw7`, then push the `hw7` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Checkout hw7 from the public branch:
git checkout hw7
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw7` with the following structure:

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   └── student_gtests.cpp
└── src
    ├── main.cpp
    ├── random.txt
    ├── shortrandom.txt
    ├── shortsorted.txt
    ├── sorted.txt
    ├── sorter.cpp
    ├── sorter.h
    └── timer.h
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`.

## Build Instructions

```bash
# Produce the `build` folder with the presets provided for the homework:
cmake --preset default

# Build all targets at once:
cmake --build build

# Build only the main.cpp:
cmake --build build --target main

# Build only the student_gtests.cpp:
cmake --build build --target student_gtests
```

To run the above targets after compiling them:

```bash
./build/main                # Runs the 'main' function from src/main.cpp
./build/student_gtests      # Runs the student set of gtests
```

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push`
your changes to your private repository, and then submitting the `hw7` branch to `Gradescope`. Or,
you can upload files directly, namely: `main.cpp`, `timer.h`, and `sorter<.h/.cpp>`.
