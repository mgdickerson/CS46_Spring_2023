// ----------------------- Tests File - uolist_gtests.cpp ------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

#include <gtest/gtest.h>
#include <gtest/internal/gtest-internal.h>

#include <algorithm>
#include <string>
#include <ctime>
#include <iostream>
using namespace std;
// Include all of your *.h files you want to unit test:
#include "sorted_list.h"

namespace {

TEST(SortedArrayList, Constructor) {
  SortedArrayList SAL(1);
  EXPECT_TRUE(true);
}

TEST(SortedArrayList, Insert) {
  SortedArrayList SAL(1);
  std::string s = "test";
  SAL.insert(s);
  EXPECT_TRUE(true);
}

TEST(SortedArrayList, Find) {
  SortedArrayList SAL(1);
  std::string s = "test";
  SAL.insert(s);
  EXPECT_TRUE(SAL.find(s));
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
