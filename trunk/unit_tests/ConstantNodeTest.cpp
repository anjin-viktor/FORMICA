#include <iostream>
#include <string>

#include <boost/test/unit_test.hpp>

#include <gmpxx.h>

#include "ConstantNode.h"

BOOST_AUTO_TEST_SUITE(CONSTANT_NODE_TESTS);



BOOST_AUTO_TEST_CASE(test_1)
{
	ConstantNode cnode, cnode1("1000.25"), cnode2(1000.25);
	AbstractNode node;


	BOOST_CHECK_EQUAL(node.getValue().get_prec(), cnode1.getValue().get_prec());
	BOOST_CHECK_EQUAL(node.getValue().get_prec(), cnode2.getValue().get_prec());
	BOOST_CHECK_EQUAL(node.getValue().get_prec(), cnode.getValue().get_prec());

	BOOST_CHECK_EQUAL(cnode1.getValue(), cnode2.getValue());
	BOOST_CHECK_EQUAL(cnode1.getValue(), 1000.25);
}


BOOST_AUTO_TEST_SUITE_END();
