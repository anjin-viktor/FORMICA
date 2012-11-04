#ifndef CONSTANT_NODE_H_
#define CONSTANT_NODE_H_

/**
@file ConstantNode.h
*/


#include <string>

#include "AbstractNode.h"



/**
@class ConstantNode
@brief ConstantNode is a class for representation constant as node of tree execution
*/

class ConstantNode: public AbstractNode
{
	public:
		ConstantNode();
		ConstantNode(const std::string &);
		ConstantNode(double);
		~ConstantNode();
};





#endif
