cmake_minimum_required(VERSION 3.20)

project(HW5 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROVIDED_SRC_FILES
  src/timer.h
)

set(AVLTREE_SRC_FILES
  src/avltree.h
  src/avltree.cpp
)

set(BST_SRC_FILES
  src/bst.h
  src/bst.cpp
)

set(BSTREE_SRC_FILES
  src/bstree.h
  src/bstree.cpp
)

add_executable(main
  ${PROVIDED_SRC_FILES}
  ${AVLTREE_SRC_FILES}
  ${BST_SRC_FILES}
  ${BSTREE_SRC_FILES}
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
    ${PROVIDED_SRC_FILES}
    ${AVLTREE_SRC_FILES}
    ${BST_SRC_FILES}
    ${BSTREE_SRC_FILES}
  )
  target_include_directories(student_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(student_gtests PRIVATE ${GTEST_LIBRARIES})
endif()

