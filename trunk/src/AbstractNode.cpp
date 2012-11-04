#include "AbstractNode.h"

AbstractNode::AbstractNode(): m_value(0, 1024)
{
}



AbstractNode::~AbstractNode()
{
}



mpf_class AbstractNode::getValue() const
{
	return m_value;
}



void AbstractNode::exec()
{
}
