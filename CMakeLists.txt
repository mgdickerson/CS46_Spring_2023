cmake_minimum_required(VERSION 3.20)

project(HW2 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(UNORDERED_LIST_SRC_FILES
  src/Timer.h
  src/unordered_list.h
  src/unordered_list.cpp
)
add_executable(hw ${UNORDERED_LIST_SRC_FILES} src/main.cpp)

find_package(GTest)
if (GTest_FOUND)
  set(UOLIST_TEST_FILES
    gtest/gtestmain.cpp
    gtest/uolist_gtests.cpp
  )

  add_executable(uolist_gtests ${UOLIST_TEST_FILES} ${UNORDERED_LIST_SRC_FILES})
  target_include_directories(uolist_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(uolist_gtests PRIVATE ${GTEST_LIBRARIES})
endif()

