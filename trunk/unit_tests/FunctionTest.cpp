#include <string>

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>


#include "Function.h"
#include "AbstractNode.h"
#include "VariableNode.h"
#include "ConstantNode.h"
#include "OperatorNode.h"


BOOST_AUTO_TEST_SUITE(FUNCTION_TESTS);



BOOST_AUTO_TEST_CASE(test_1)
{
	Function func;
	ExecutionTree tree;

	boost::shared_ptr<AbstractNode> op1(new VariableNode("b"));
	boost::shared_ptr<AbstractNode> op2(new ConstantNode(2.0));

	boost::shared_ptr<AbstractNode> op3(new OperatorNode(Operator::MUL));
	op3 -> addOperand(op1);
	op3 -> addOperand(op2);

	op1 = boost::shared_ptr<AbstractNode>(new VariableNode("a"));

	op2 = boost::shared_ptr<AbstractNode>(new VariableNode("b"));

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

	func.setExecutionTree(tree);

	func.addParam("a");
	func.addParam("b");

	std::list<mpf_class> lstArgs;
	lstArgs.push_front(5);
	lstArgs.push_front(125);

	Context cntx;
	BOOST_CHECK_NO_THROW(cntx = func.createContext(lstArgs));
	BOOST_CHECK_EQUAL(cntx.varTab["a"], 125);
	BOOST_CHECK_EQUAL(cntx.varTab["b"], 5);


	cntx.execTree.root() -> exec(&cntx.varTab);

	BOOST_CHECK_EQUAL(cntx.varTab["c"], 35);
}



BOOST_AUTO_TEST_SUITE_END();
