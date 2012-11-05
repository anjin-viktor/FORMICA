#include "OperatorNode.h"


OperatorNode::OperatorNode(): m_op(Operator::NONE)
{
}



OperatorNode::OperatorNode(Operator::Type op): m_op(op)
{
}




OperatorNode::~OperatorNode()
{
}



void OperatorNode::setOperator(Operator::Type op)
{
	m_op = op;
}



Operator::Type OperatorNode::getOperator() const
{
	return m_op;
}
