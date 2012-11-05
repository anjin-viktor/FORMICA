#include "AbstractNode.h"

AbstractNode::AbstractNode(): m_value(0, 1024)
{
}



AbstractNode::~AbstractNode()
{
}



mpf_class AbstractNode::getValue()
{
	return m_value;
}



void AbstractNode::setValue(const mpf_class &val)
{
	m_value = val;
}




void AbstractNode::addOperand(const boost::shared_ptr<AbstractNode> &operand)
{
	m_operands.push_back(operand);
}



void AbstractNode::setParent(const boost::shared_ptr<AbstractNode> &parent)
{
	m_parent = parent;
}



boost::shared_ptr<AbstractNode> AbstractNode::getParent() const
{
	return m_parent;
}




void AbstractNode::exec()
{
	std::list<boost::shared_ptr<AbstractNode> >::iterator itr = m_operands.begin();

	for(; itr != m_operands.end(); itr++)
		(*itr) -> exec();
}
