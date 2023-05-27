cmake_minimum_required(VERSION 3.20)

project(HW8 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GRAPH_SRC_FILES
  src/graph.h
  src/graph.cpp
)

add_executable(main
  ${GRAPH_SRC_FILES}
  src/main.cpp
)

find_package(GTest)
if (GTest_FOUND)
  set(STUDENT_TEST_FILES
    gtest/gtestmain.cpp
    gtest/student_gtests.cpp
  )

  add_executable(student_gtests 
    ${STUDENT_TEST_FILES}
    ${GRAPH_SRC_FILES}
  )
  target_include_directories(student_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(student_gtests PRIVATE ${GTEST_LIBRARIES})
endif()

