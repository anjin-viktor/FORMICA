#ifndef VARIABLE_NODE_H_
#define VARIABLE_NODE_H_

/**
@file ConstantNode.h
*/


#include <string>
#include <map>
#include <gmpxx.h>

#include "AbstractNode.h"



/**
@class VariableNode
@brief VariableNode is a class for representation variable as node of tree execution
*/

class VariableNode: public AbstractNode
{
	public:
		VariableNode();
		VariableNode(const std::string &);
		~VariableNode();

/**
Setting variable name
*/
		void setName(const std::string &);

/**
Getting variable name
*/
		std::string getName() const;

/**
Setting pointer to variable table for this node
*/
		void setVarTablePtr(std::map<std::string, mpf_class> *);

		virtual mpf_class getValue();
		virtual void setValue(const mpf_class &);

	private:
		std::string							m_name;
		std::map<std::string, mpf_class>	*m_pvarTable;
};


#endif
