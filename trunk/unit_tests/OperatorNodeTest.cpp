#include <iostream>

#include <boost/test/unit_test.hpp>


#include "OperatorNode.h"

BOOST_AUTO_TEST_SUITE(OPERATOR_NODE_TESTS);



BOOST_AUTO_TEST_CASE(test_1)
{
	OperatorNode node1(Operator::ADD), node2;
	node2.setOperator(Operator::ADD);

	BOOST_CHECK_EQUAL(node1.getOperator(), node2.getOperator());
	BOOST_CHECK_EQUAL(node1.getOperator(), Operator::ADD);	
}



BOOST_AUTO_TEST_SUITE_END();
