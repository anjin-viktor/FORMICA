#ifndef EXECUTION_TREE_H_
#define EXECUTION_TREE_H_



/**
@file ExecutionTree.h
*/

#include <boost/shared_ptr.hpp>

#include "AbstractNode.h"

/**
@class ExecutionTree
@brief ExecutionTree is the order of calculation and inplementing them 
*/

class ExecutionTree
{
	public:
		ExecutionTree();
		~ExecutionTree();

		boost::shared_ptr<AbstractNode> root();

	private:
		boost::shared_ptr<AbstractNode>		m_root;
};



#endif
