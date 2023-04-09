# ICS 46: Homework 1

Welcome to ICS 46 Homework 1! For more general instructions, please reference the `main` branch.
This repository will focus on instructions relevant to HW1. In this assignment, you will be modifying:

```bash
main.cpp
String.h
String.cpp
Alloc.h
Alloc.cpp

# If using GTest:
string_gtests.cpp
alloc_gtests.cpp
```

To add this branch to your private repository, follow the instructions under the
[Getting Started](#getting-started) section.

### TLDR Build And Run:

```bash
# Pull updates:
git fetch public

# Checkout hw1:
git checkout hw1

# Push to origin:
git push -u origin hw1

# Run CMake defaults and Build Generator commands
cmake --preset default

# Target Build Command
cmake --build build   # Will build all of the `targets` described in the `CMake` file

# Build only main.cpp:
cmake --build build --target hw

# Build only String tests:
cmake --build build --target string_gtests

# Build only Alloc tests:
cmake --build build --target alloc_gtests

./build/hw              # Runs the 'main' function from src/main.cpp
./build/string_gtests   # Runs the 'string' gtest set of tests
./build/alloc_gtests    # Runs the 'alloc' gtests
```

## Getting Started

If you are using `GitHub`, then it is likely you will have already cloned this repository!
If you have not, or removed the folder for any reason, then you will need to clone your
private repository first:

```bash
# Clone your private repository
git clone <YourPrivateRepositorySSHLink>

# Change Directory into your project folder
cd <PrivateProjectName>
```

Next, you will need to pull any changes and updates, so we are going to run a `fetch` command:

```bash
# Check that you have the `public` remote setup (it should list an `origin` and a `public`):
git remote -v

# If you do not find a `public` option on the above command, you will need to add it:
git remote add public https://github.com/mgdickerson/CS45C_Spring_2023.git

# Once you are sure that you have the remote tracking set up, you can run the fetch command:
git fetch public
```

If you have set up the `remote` repository `public` to track this GitHub project, then you
should now see that `git` has pulled all the necessary changes!

### Checkout

Next, we will checkout the `hw1` branch. In the same terminal as before, you will type:

```bash
git checkout hw1
```

WARNING: It is possible that you already have a copy of the `hw1` branch for any reason. The easiest
way to update to the new instructions is to delete your private repositories' copy of the branch and
then re-checkout `hw1` and follow the rest of the instructions. (So if you see the, `multiple (2) remote
tracking branches` error, this is likely what is happening to you):

```bash
# WARNING: The following commands will delete ALL changes you have made to the hw1 branch. If you have
# important work saved there, be sure to copy it outside of the folder first!
cd ../
mkdir SavedWork
cp <PrivateRepo>/src/* SavedWork/. (This will copy all files in the src folder)

# Delete the hw1 branch locally
git branch -D hw1

# Delete the hw1 branch on your private repository on GitHub
git push origin -d hw1

# After deleting your outdated copy of the hw1 branch, run the checkout command again:
git checkout hw1
```

NOTE: If you are very confident in `git`, you can also simply merge the changes, but there will be
merge conflicts on the `CMakeLists.txt` file, so proceed with caution.

You are now in the `hw1` branch! Now, we will want to add this branch to your private repository
on `GitHub` and add tracking. To do this, we will run the command:

```bash
# Add the `hw1` branch to your private repository on GitHub
git push -u origin hw1
```

The branch will now appear in your private repository on `GitHub.com`! This also sets up the
branch to track with your private repository instead of the public one, so now simple push commands
should send changes to the correct repository:

```bash
# Push changes to private repository
git push
```

NOTE: AFTER you have done all the steps above, if you then clone this repository to a new folder or
computer, it will now have multiple references to each `branch`. It is possible that when you run the
`checkout` command, you will get an error such as: `multiple (2) remote tracking branches`. This happens
because `git` is not sure which repository to pull it from, `origin` or `public`, so we will tell it
which one to pull from, and set it to always prefer `origin` for this `branch`:

```bash
# Set the hw1 branch to track from "origin" (origin is your private repository)
git checkout --track origin/hw1
```

This will checkout the `hw1` branch and set the preference for `origin`.
You can now make changes to your code as shown in the [Coding](#coding)
section below!

## Directory Structure

If you are not using `GitHub`, and want to use our testing framework, you will need to make a folder
named `hw1` with the following structure:

```bash
├── CMakeLists.txt
├── CMakePresets.txt
├── gtest
│   ├── gtestmain.cpp
│   ├── alloc_gtests.cpp
│   └── string_gtests.cpp
└── src
    ├── Alloc.cpp
    ├── Alloc.h
    ├── main.cpp
    ├── String.cpp
    └── String.h
```

You should copy everything from the `CMakeLists.txt` and `CMakePresets.json` files into your own,
as well as the files `gtestmain.cpp` and the individual `gtests`. This will allow you to build and run the
tests for this assignment. If you do not follow this structure, you will not be able to use the
`CMakeLists.txt` file as provided!

## Coding

Starting from `hw1`, the details of the assignment itself will be covered in the homework documents
not on this `GitHub` page. Instead, we will discuss how to test your `String` class with `GTest`.

### String GTest:

The `GTests` for `String` will be located in the file: `gtest/string_gtests.cpp`.
Currently, the file should looks like the following:

```cpp
// ----------------------- Tests File - string_test.cpp --------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>

#include <iostream>
using namespace std;
// Include all of your *.h files you want to unit test:
#include "String.h"

namespace {

TEST(String, IndexOf) {
  String t{ "Test" };
  EXPECT_EQ(1, t.indexOf("s"));
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
```

To add a test, you will need to modify this file.

```bash
vim gtest/string_gtests.cpp

# Or Neovim
nvim gtest/string_gtests.cpp
```

As you can see in the file, it contains your `String.h` file you just made, and has
a test for comparing the index of the letter `e` in the string `Test`. If the `String`
class has been written correctly, that test should succeed,
but just to be sure, lets add another test. This time, we want to test `String` equality.
We will add our test just below where it says `// ADD YOUR TEST HERE:`:

```cpp
TEST(String, Equality) {
  String t{ "Test" };
  String e{ "Test" };
  // Test String equality overload
  EXPECT_TRUE(t == e);
  // Double check each char matches
  for (int i = 0; i < 4; ++i) {
    EXPECT_EQ(t[i], e[i]);
  }
}
```

This will add a test to the `String` set named `Equality` and test that the values of
your function and the number provided are equal. You can either jump to
[Build Instructions](#build-instructions) to test this or read about manual testing.

### String Main:

If you are not using `GTest`, you can instead write your own tests using the `main.cpp` file
we created above. For more information on this, reference the homework document. 

## Build Instructions

If you are not already in a terminal (or ssh with OpenLab) from the above instructions, you will need
to open a terminal and move into your project folder as show below:

```bash
cd <YourProjectPath>    # So if we had the project in a folder named Projects: cd Projects/CS46
```

This time, we are going to go into a little more detail on how `CMake` works. The `CMake` process is
basically comprised of two steps: producing project build files and actually building the project.
To produce the build files for our project we run the first command:

```bash
# Build Generator Command
cmake --preset deafult # Create a folder named `build` and run `CMake` to produce build files there
```

This command needs to be run at least once. Once it has been run, you will not need to run it again
unless you add new files that were not previously added to the project (or if you change the 
`CMakeLists.txt` file). If you add files or change `CMakeLists.txt`, then you can simply re-run
the command above and it will update the `build` files that it produced before. Once you have the
`build` folder and files, you will want to build the actual program. This can be done two ways.
You can either build everything at once:

```bash
# Target Build Command
cmake --build build   # Will build all of the `targets` described in the `CMake` file
```

Or you can pick a specific target to build. For this homework, there are 3 possible `targets`:
`hw` (which is the `main.cpp` file you created above), `string_gtests` (`string_gtests.cpp`), and
`alloc_gtests` (`alloc_gtests.cpp`). These `targets` are defined in the `CMakeLists.txt` file
as `project(<name>)`, so if you want to find the `targets` yourself, you can always check that
file. We will also always give you the available `targets` in this class. Below are the individual
`target` commands you can run:

```bash
# Build only main.cpp:
cmake --build build --target hw

# Build only Alloc tests:
cmake --build build --target alloc_gtests

# Build only String tests:
cmake --build build --target string_gtests
```

NOTE: If you build all targets with the `cmake --build build` command, you DO NOT need to
run the individual commands. The advantage of running the individual build commands is
being able to build only the parts you want to test. Also, unlike the Build Generator 
Command (`cmake --preset default`), you will need to run the Target Build Command 
(`cmake --build build <--target target>`) every time you make changes to your `*.cpp` or `*.h`
files. For example, if you build `string_gtests.cpp`, and find out that your `indexOf` does
not work for `Strings` size 2, you will need to change `string.h`. Once you have
changed it, when you want to test it again, you can run:

```bash
cmake --build build --target string_gtests
```

And it will build just that code with your updated changes! Very handy for testing one task
at a time.

After you have built your intended target, you will have three new executables you can run!
You will have `hw` which will be the code from `main.cpp`, `string_gtests`, and `alloc_gtests`.
You can run each one with the commands shown below:

```bash
./build/hw            # Runs the 'main' function from src/main.cpp
./build/alloc_gtests   # Runs the 'alloc' gtest set of tests
./build/string_gtests  # Runs the 'String' gtests
```

Once you have run the code above and it either produces the output you expected or passes
all provided tests, congratulations! You are now ready to [submit](#submission) your homework!

## Submission

All submissions will be done through [Gradescope](https://www.gradescope.com/). Open the Gradescope page
and select `HW1`. Now if you are using a `GitHub` account, follow the [GitHub Submission](#github-submission)
instructions, otherwise follow the [File Submission](#file-submission) instructions.

### GitHub Submission

First, we need to make sure that we commit all of our changes we made! In a terminal inside your project folder,
run the following command:

```bash
git commit -a -m "Submission commit of HW1."
```

Now that we have committed out changes, we need to push them to `GitHub` so that `Gradescope` can see them.

```bash
git push
```

Now on Gradescope, press the submit button, choose the `GitHub` option, and select your project and branch
as shown below:

![](docs/submit_github.png)

Now the autograder will run and give you a score!

### File Submission

On `Gradescope`, press the `submit` button and it will bring up the following window:

![](docs/submit_files.png)

Then you will drag and drop the `main.cpp`, `String.h`, `String.cpp`, `Alloc.h`, and `Alloc.cpp` files from your `src` folder
(or wherever you have made this file) and press upload. As these are the only files we are changing, they
should be the only files that you upload!
