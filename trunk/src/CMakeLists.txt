cmake_minimum_required(VERSION 2.8)

set (PROJECT 
	formica)

set (TEST_DIR ../unit_tests/)

set (PROJECT_LIB ${PROJECT}_lib)

project (${PROJECT})

set (LIB_SOURCES
	FormicaLexer.cpp
	)


set (Boost_USE_STATIC_LIBS ON)

add_library (${PROJECT_LIB} STATIC ${LIB_SOURCES})

include_directories(${Boost_INCLUDE_DIRS})

enable_testing()

add_subdirectory(${TEST_DIR} ${TEST_DIR})
