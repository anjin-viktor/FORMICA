cmake_minimum_required(VERSION 2.8)

set (PROJECT 
	formica)

set (SRC_BUILD_DIR build/src/)
set (UNIT_TESTS_BUILD_DIR build/unit_tests/)

project (${PROJECT})
set (PROJECT_LIB ${PROJECT}_lib)

add_subdirectory(./src/ ${SRC_BUILD_DIR})
add_subdirectory(./unit_tests/ ${UNIT_TESTS_BUILD_DIR})

enable_testing()
