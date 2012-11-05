#include <iostream>
#include <string>
#include <map>

#include <boost/shared_ptr.hpp>
#include <boost/test/unit_test.hpp>

#include <gmpxx.h>

#include "AbstractNode.h"
#include "OperatorNode.h"
#include "ConstantNode.h"
#include "VariableNode.h"
#include "ExecutionTree.h"

BOOST_AUTO_TEST_SUITE(EXECUTION_TREE_TESTS);

/*
					+
			*				/
		b  		2		a 		b
*/


BOOST_AUTO_TEST_CASE(test_1)
{
	ExecutionTree tree;

	std::map<std::string, mpf_class> varTable;
	varTable["a"] = 125;
	varTable["b"] = 5;


	VariableNode *pvar = new VariableNode("b");
	pvar -> setVarTablePtr(&varTable);

	boost::shared_ptr<AbstractNode> op1(pvar);
	boost::shared_ptr<AbstractNode> op2(new ConstantNode(2.0));

	boost::shared_ptr<AbstractNode> op3(new OperatorNode(Operator::MUL));
	op3 -> addOperand(op1);
	op3 -> addOperand(op2);

	pvar = new VariableNode("a");
	pvar -> setVarTablePtr(&varTable);
	op1 = boost::shared_ptr<AbstractNode>(pvar);

	pvar = new VariableNode("b");
	pvar -> setVarTablePtr(&varTable);
	op2 = boost::shared_ptr<AbstractNode>(pvar);

	boost::shared_ptr<AbstractNode> op4(new OperatorNode(Operator::DIV));
	op4 -> addOperand(op1);
	op4 -> addOperand(op2);


	op1 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::ADD));
	op1 -> addOperand(op3);
	op1 -> addOperand(op4);

	tree.root() -> addOperand(op1);
	tree.root() -> exec(&varTable);

	BOOST_CHECK_EQUAL(op3 -> getValue(), 10);
	BOOST_CHECK_EQUAL(op4 -> getValue(), 25);
	BOOST_CHECK_EQUAL(op1 -> getValue(), 35);
}





BOOST_AUTO_TEST_CASE(test_2)
{
	ExecutionTree tree;

	std::map<std::string, mpf_class> varTable;
	varTable["b"] = 1.25;

	VariableNode *pvar = new VariableNode("b");
	pvar -> setVarTablePtr(&varTable);

	boost::shared_ptr<AbstractNode> op1(pvar);
	boost::shared_ptr<AbstractNode> op2(new ConstantNode(15.3));

	boost::shared_ptr<AbstractNode> op3(new OperatorNode(Operator::SUB));
	op3 -> addOperand(op1);
	op3 -> addOperand(op2);

	pvar = new VariableNode("d");
	pvar -> setVarTablePtr(&varTable);
	op1 = boost::shared_ptr<AbstractNode>(pvar);


	op2 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::ASSIGN));
	op2 -> addOperand(op1);
	op2 -> addOperand(op3);



	tree.root() -> addOperand(op2);
	tree.root() -> exec(&varTable);

	BOOST_CHECK_EQUAL(op3 -> getValue(), -14.05);
	BOOST_CHECK_EQUAL(varTable["d"], -14.05);
}






BOOST_AUTO_TEST_CASE(test_3)
{
	ExecutionTree tree;

	std::map<std::string, mpf_class> varTable;


	boost::shared_ptr<AbstractNode> op1(new ConstantNode(1));
	boost::shared_ptr<AbstractNode> op2(new ConstantNode(2));

	boost::shared_ptr<AbstractNode> op3(new OperatorNode(Operator::ADD));
	op3 -> addOperand(op1);
	op3 -> addOperand(op2);

	op1 = boost::shared_ptr<AbstractNode>(new VariableNode("b"));
	op2 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::ASSIGN));
	op2 -> addOperand(op1);
	op2 -> addOperand(op3);
	tree.root() -> addOperand(op2);



	op1 = boost::shared_ptr<AbstractNode>(new ConstantNode(1));
	op2 = boost::shared_ptr<AbstractNode>(new ConstantNode(2));

	op3 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::MUL));
	op3 -> addOperand(op1);
	op3 -> addOperand(op2);

	op1 = boost::shared_ptr<AbstractNode>(new VariableNode("c"));
	op2 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::ASSIGN));
	op2 -> addOperand(op1);
	op2 -> addOperand(op3);
	tree.root() -> addOperand(op2);

	tree.root() -> exec(&varTable);

	BOOST_CHECK_EQUAL(varTable["b"], 3);
	BOOST_CHECK_EQUAL(varTable["c"], 2);

}





BOOST_AUTO_TEST_CASE(test_4)
{
	ExecutionTree tree;

	std::map<std::string, mpf_class> varTable;
	varTable["a"] = 125;
	varTable["b"] = 5;


	VariableNode *pvar = new VariableNode("b");
	pvar -> setVarTablePtr(&varTable);

	boost::shared_ptr<AbstractNode> op1(pvar);
	boost::shared_ptr<AbstractNode> op2(new ConstantNode(2.0));

	boost::shared_ptr<AbstractNode> op3(new OperatorNode(Operator::MUL));
	op3 -> addOperand(op1);
	op3 -> addOperand(op2);

	pvar = new VariableNode("a");
	pvar -> setVarTablePtr(&varTable);
	op1 = boost::shared_ptr<AbstractNode>(pvar);

	pvar = new VariableNode("b");
	pvar -> setVarTablePtr(&varTable);
	op2 = boost::shared_ptr<AbstractNode>(pvar);

	boost::shared_ptr<AbstractNode> op4(new OperatorNode(Operator::DIV));
	op4 -> addOperand(op1);
	op4 -> addOperand(op2);


	op1 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::ADD));
	op1 -> addOperand(op3);
	op1 -> addOperand(op4);

	op4 = boost::shared_ptr<AbstractNode>(new VariableNode("c"));
	op3 = boost::shared_ptr<AbstractNode>(new OperatorNode(Operator::ASSIGN));
	op3 -> addOperand(op4);
	op3 -> addOperand(op1);

	tree.root() -> addOperand(op3);
	tree.root() -> exec(&varTable);

	BOOST_CHECK_EQUAL(varTable["c"], 35);
}




BOOST_AUTO_TEST_SUITE_END();
