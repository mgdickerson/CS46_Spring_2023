# ICS 46: Homework 3

Welcome to ICS 46 Homework 3! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw3`, then push the `hw3` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Checkout hw3 from the public branch:
git checkout hw3
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw3` with the following structure:

```bash
.
├── CMakeLists.txt
├── CMakePresets.json
├── README.md
├── gtest
│   ├── gtestmain.cpp
│   └── slist_gtests.cpp
└── src
    ├── Timer.h
    ├── main.cpp
    ├── random.txt
    ├── sorted_list.cpp
    ├── sorted_list.h
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

# Build only the main.cpp:
cmake --build build --target hw

# Build only the slist_gtests.cpp:
cmake --build build --target slist_gtests
```

To run the above targets after compiling them:

```bash
./build/hw                  # Runs the 'main' function from src/main.cpp
./build/slist_gtests        # Runs the sorted_list set of gtests
```

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push`
your changes to your private repository, and then submitting the `hw3` branch to `Gradescope`. Or,
you can upload files directly, namely: `main.cpp`, `Timer.h`, `sorted_list.cpp`, and `sorted_list.h`.
