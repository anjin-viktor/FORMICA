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
