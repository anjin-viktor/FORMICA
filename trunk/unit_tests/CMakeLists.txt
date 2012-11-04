set (TEST
	FORMICA_UNIT_TESTS)
 
project (${TEST})

 
set (SOURCES
	AbstractNodeTest.cpp
	UnitTestMain.cpp
	)
 
set (BOOST_COMPONENTS 
		unit_test_framework
	)

set (Boost_USE_STATIC_LIBS ON)


include_directories(../src/)
include_directories(${Boost_INCLUDE_DIRS})


find_package (Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

message(STATUS project_LIB = ${PROJECT_LIB})

add_executable (${TEST} ${SOURCES})

target_link_libraries (${TEST} ${PROJECT_LIB} ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES})

add_test(${TEST} ${TEST})

enable_testing()
