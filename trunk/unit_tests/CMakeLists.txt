cmake_minimum_required(VERSION 2.8)

set (TEST
	FORMICA_UNIT_TESTS)
 
project (${TEST})


set (SOURCES
	AbstractNodeTest.cpp
	ConstantNodeTest.cpp
	VariableNodeTest.cpp
	OperatorNodeTest.cpp
	ExecutionTreeTest.cpp
	FunctionTest.cpp
	UnitTestMain.cpp
	)
 
set (BOOST_COMPONENTS 
		unit_test_framework
	)

set (Boost_USE_STATIC_LIBS ON)


include_directories(../src/)
include_directories(${Boost_INCLUDE_DIRS})


find_package (Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

add_executable (${TEST} ${SOURCES})

target_link_libraries (${TEST} ${PROJECT_LIB} ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

add_test(${TEST} ${TEST})
