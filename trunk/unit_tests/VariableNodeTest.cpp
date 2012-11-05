#include <iostream>
#include <string>
#include <map>

#include <boost/test/unit_test.hpp>

#include <gmpxx.h>

#include "VariableNode.h"

BOOST_AUTO_TEST_SUITE(VARIABLE_NODE_TESTS);



BOOST_AUTO_TEST_CASE(test_1)
{
	VariableNode node1("name");
	VariableNode node2;
	node2.setName("name");

	BOOST_CHECK_EQUAL(node1.getName(), node2.getName());
	BOOST_CHECK_EQUAL(node1.getName(), "name");
}



BOOST_AUTO_TEST_CASE(test_2)
{
	std::map<std::string, mpf_class> varTable;
	varTable["a"] = "125.5";

	VariableNode node1("a");
	node1.setVarTablePtr(&varTable);

	BOOST_CHECK_EQUAL(node1.getValue(), 125.5);
	node1.setName("b");
	BOOST_CHECK_EQUAL(node1.getValue(), 0);

	node1.setValue(125.0);
	BOOST_CHECK_EQUAL(varTable["b"], 125.0);

	node1.setName("c");
	node1.setValue(300.0);
	BOOST_CHECK_EQUAL(varTable["c"], 300.0);
}

BOOST_AUTO_TEST_SUITE_END();
