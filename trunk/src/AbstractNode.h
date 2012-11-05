#ifndef ABSTRACT_NODE_H_
#define ABSTRACT_NODE_H_

/**
@file AbstractNode.h
*/

#include <list>

#include <boost/shared_ptr.hpp>

#include <gmpxx.h>


/**
@class AbstractNode
@brief AbstractNode is a class for representation node in execution tree
*/


class AbstractNode
{
	public:
		AbstractNode();
		virtual ~AbstractNode();


/**
Getting result of execution expression or value of variable or constant
*/
		virtual mpf_class getValue();
		virtual void setValue(const mpf_class &);

/**
Addition operand for Node
*/
		void addOperand(const boost::shared_ptr<AbstractNode> &);

/**
Seting pointer to parent for this node
*/

		void setParent(const boost::shared_ptr<AbstractNode> &);

/**
Getting pointer to parent for this node
*/
		boost::shared_ptr<AbstractNode> getParent() const;


		virtual void exec();

	protected:
		mpf_class										m_value;
		std::list<boost::shared_ptr<AbstractNode> >		m_operands;
		boost::shared_ptr<AbstractNode>					m_parent;
};


#endif
