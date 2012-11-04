#include <iostream>
#include <string>

#include <boost/test/unit_test.hpp>

#include <gmpxx.h>

#include "AbstractNode.h"

BOOST_AUTO_TEST_SUITE(ABSTRACT_NODE_TESTS);



BOOST_AUTO_TEST_CASE(test_1)
{
	AbstractNode node;

	mpf_class val = node.getValue();
	cmp(val, 0);

}


BOOST_AUTO_TEST_SUITE_END();
