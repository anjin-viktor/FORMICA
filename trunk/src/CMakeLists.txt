cmake_minimum_required(VERSION 2.8)



set (LIB_SOURCES
	AbstractNode.cpp
	ConstantNode.cpp
	VariableNode.cpp
	OperatorNode.cpp
	ExecutionTree.cpp
	Function.cpp
	)

set (GMP_LIBS
	gmpxx
)


set (Boost_USE_STATIC_LIBS ON)
include_directories (${Boost_INCLUDE_DIRS})

add_library (${PROJECT_LIB} STATIC ${LIB_SOURCES})
target_link_libraries(${PROJECT_LIB} ${GMP_LIBS})

