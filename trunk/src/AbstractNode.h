#ifndef ABSTRACT_NODE_H_
#define ABSTRACT_NODE_H_

/**
@file AbstractNode.h
*/

#include <gmpxx.h>


/**
@class AbstractNode
@brief AbstractNode is a class for representation node in executions tree
*/


class AbstractNode
{
	public:
		AbstractNode();
		virtual ~AbstractNode();

/**
Getting result of execution expression or value of variable or constant
*/
		virtual mpf_class getValue() const;
		virtual void exec();

	private:
		mpf_class		m_value;
};


#endif
