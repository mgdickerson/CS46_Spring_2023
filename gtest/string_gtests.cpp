// ----------------------- Tests File - string_test.cpp --------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

// Include all of your *.h files you want to unit test:
#include "string.h"

#include <gtest/gtest.h>

namespace {

TEST(String, IndexOf) {
  String t{ "Test" };
  EXPECT_EQ(1, t.indexOf("e"));
}

// ADD YOUR TESTS HERE:


} // anonymous namespace

