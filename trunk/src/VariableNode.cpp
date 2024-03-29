#include "VariableNode.h"


VariableNode::VariableNode(): m_pvarTable(NULL)
{
}




VariableNode::VariableNode(const std::string &name): m_pvarTable(NULL), m_name(name)
{
}




VariableNode::~VariableNode()
{
}




void VariableNode::setName(const std::string &name)
{
	m_name = name;
}




std::string VariableNode::getName() const
{
	return m_name;
}




void VariableNode::setVarTablePtr(std::map<std::string, mpf_class> *p)
{
	m_pvarTable = p;
}




mpf_class VariableNode::getValue()
{
	std::map<std::string, mpf_class>::iterator itr = m_pvarTable -> find(m_name);
	if(itr == m_pvarTable -> end())
	{
		m_pvarTable -> insert(std::pair<std::string, mpf_class> (m_name, mpf_class(0, 1024)));
		m_value = m_pvarTable -> find(m_name) -> second;
	}
	else
		m_value = itr -> second;

	return m_value;
}




void VariableNode::setValue(const mpf_class &val)
{
	AbstractNode::setValue(val);
	m_pvarTable -> operator[](m_name) = val;
}




void VariableNode::exec(std::map<std::string, mpf_class> *varTab)
{
	setVarTablePtr(varTab);
	AbstractNode::exec(varTab);
}

