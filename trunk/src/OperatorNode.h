#ifndef OPERATOR_NODE_H_
#define OPERATOR_NODE_H_


/**
@file OperatorNode.h
*/


#include "AbstractNode.h"




namespace Operator
{
/**
@brief enumeration Operator::Type is used to represent elementary operations 
*/

	enum Type
	{
		ADD,
		SUB,
		MUL,
		DIV,
		ASSIGN,
		NONE
	};

}



/**
@class OperatorNode
@brief OperatorNode is a class for representation operators as nodes execution tree
*/

class OperatorNode: public AbstractNode
{
	public:
		OperatorNode();
		OperatorNode(Operator::Type type);
		~OperatorNode();		

		void setOperator(Operator::Type type);
		Operator::Type getOperator() const;

		void exec(std::map<std::string, mpf_class> *);

	private:
		Operator::Type 		m_op;
};


#endif
