#include "ConstantNode.h"

ConstantNode::ConstantNode()
{
}

ConstantNode::ConstantNode(const std::string &str)
{
	m_value = mpf_class(str, m_value.get_prec());
}


ConstantNode::ConstantNode(double op)
{
	m_value = mpf_class(op, m_value.get_prec());
}



ConstantNode::~ConstantNode()
{
}

