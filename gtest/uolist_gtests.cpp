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
#include "unordered_list.h"

namespace {

TEST(UOArrayList, Constructor) {
  UnorderedArrayList UAL(1);
  EXPECT_TRUE(true);
}

TEST(UOArrayList, Insert) {
  UnorderedArrayList UAL(1);
  std::string s = "test";
  UAL.insert(s);
  EXPECT_TRUE(true);
}

TEST(UOArrayList, Find) {
  UnorderedArrayList UAL(1);
  std::string s = "test";
  UAL.insert(s);
  EXPECT_TRUE(UAL.find(s));
}

TEST(UOLinkedList, Constructor) {
  UnorderedLinkedList ULL;
  EXPECT_TRUE(true);
}

TEST(UOLinkedList, Insert) {
  UnorderedLinkedList ULL;
  std::string s = "test";
  ULL.insert(s);
  EXPECT_TRUE(true);
}

TEST(UOLinkedList, Find) {
  UnorderedLinkedList ULL;
  std::string s = "test";
  ULL.insert(s);
  EXPECT_TRUE(ULL.find(s));
}

// ADD YOUR TESTS HERE:


} // anonymous namespace
