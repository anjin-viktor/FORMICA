#include "Function.h"

Function::Function()
{
}




Function::Function(const ExecutionTree &execTree)
{
	m_execTree = execTree;
}




Function::~Function()
{
}




void Function::addParam(const std::string &name)
{
	m_paramNames.push_back(name);	
}




std::size_t Function::paramQuantity() const
{
	return m_paramNames.size();
}




Context Function::createContext(const std::list<mpf_class> &lst) const
{
	if(lst.size() != m_paramNames.size())
		throw std::invalid_argument("size of list values in Function::createContext not equal function parameters quantity");

	Context cntx;
	cntx.execTree = m_execTree;

	std::list<std::string>::const_iterator itrNames = m_paramNames.begin();
	std::list<mpf_class>::const_iterator itrValues = lst.begin();

	for(;itrNames != m_paramNames.end(); itrNames++, itrValues++)
		cntx.varTab[*itrNames] = *itrValues;

	return cntx;
}




void Function::setExecutionTree(const ExecutionTree &execTree)
{
	m_execTree = execTree;
}
