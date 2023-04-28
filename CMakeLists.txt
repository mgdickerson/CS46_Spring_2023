cmake_minimum_required(VERSION 3.20)

project(HW4 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HOLDER_SRC_FILES
  src/Timer.h
  src/holder.h
  src/holder.cpp
)
add_executable(main ${HOLDER_SRC_FILES} src/main.cpp)

set(IS_BALANCED_SRC_FILES
  src/is_balanced.h
  src/is_balanced.cpp
)
add_executable(is_balanced ${IS_BALANCED_SRC_FILES} src/is_balanced_main.cpp)

find_package(GTest)
if (GTest_FOUND)
  set(STUDENT_TEST_FILES
    gtest/gtestmain.cpp
    gtest/student_gtests.cpp
  )

add_executable(student_gtests ${STUDENT_TEST_FILES} ${SORTED_LIST_SRC_FILES} ${IS_BALANCED_SRC_FILES})
  target_include_directories(student_gtests PRIVATE src ${GTEST_INCLUDE_DIRS})
  target_link_libraries(student_gtests PRIVATE ${GTEST_LIBRARIES})
endif()

