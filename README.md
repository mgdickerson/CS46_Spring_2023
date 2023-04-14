# ICS 46: Homework 2

Welcome to ICS 46 Homework 2! Instructions from this point on will assume the use of `GitHub`.
If you are working without github, then copy the [Directory Structure](#directory-structure).

## Getting Started

To get started with this homework, first you will need to `fetch` changes to your personal repository,
checkout `hw2`, then push the `hw2` branch to your remote repository.

```bash
# Move into your personal private repository folder:
cd <PrivateRepositoryFolder>

# Fetch updates:
git fetch public

# Checkout hw2 from the public branch:
git checkout hw2

# Push the newly checked out branch to your private repository:
git push -u origin hw2
```

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw2` with the following structure:

```bash
├── CMakeLists.txt
├── CMakePresets.json
├── gtest
│   ├── gtestmain.cpp
│   └── uolist_gtests.cpp
└── src
    ├── main.cpp
    ├── random.txt
    ├── sort.txt
    ├── Timer.h
    ├── unordered_list.cpp
    ├── unordered_list.h
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

# Build only the uolist_gtests.cpp:
cmake --build build --target uolist_gtests
```

To run the above targets after compiling them:

```bash
./build/hw                  # Runs the 'main' function from src/main.cpp
./build/uolist_gtests       # Runs the unordered_list set of gtests
```

## Submission

As with previous submissions, you can either submit via `GitHub` by `git commit` and `git push`
your changes to your private repository, and then submitting the `hw2` branch to `Gradescope`. Or,
you can upload files directly, namely: `main.cpp`, `Timer.h`, `unordered_list.cpp`, and `unordered_list.h`.
