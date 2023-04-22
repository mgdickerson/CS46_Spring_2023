cmake_minimum_required(VERSION 3.20)

project(HW2 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SORTED_LIST_SRC_FILES
  src/Timer.h
  src/sorted_list.h
  src/sorted_list.cpp
)
add_executable(hw ${SORTED_LIST_SRC_FILES} src/main.cpp)

find_package(GTest)
if (GTest_FOUND)
  set(SLIST_TEST_FILES
    gtest/gtestmain.cpp
    gtest/slist_gtests.cpp
  )

  add_executable(slist_gtests ${SLIST_TEST_FILES} ${SORTED_LIST_SRC_FILES})
  target_include_directories(slist_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(slist_gtests PRIVATE ${GTEST_LIBRARIES})
endif()

