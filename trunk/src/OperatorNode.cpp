#include "OperatorNode.h"


OperatorNode::OperatorNode(): m_op(Operator::NONE)
{
}



OperatorNode::OperatorNode(Operator::Type op): m_op(op)
{
}




OperatorNode::~OperatorNode()
{
}



void OperatorNode::setOperator(Operator::Type op)
{
	m_op = op;
}



Operator::Type OperatorNode::getOperator() const
{
	return m_op;
}


#include <iostream>


void OperatorNode::exec()
{
	AbstractNode::exec();

	switch(m_op)
	{
		case Operator::ADD:
		{
			if(m_operands.size() != 2)
				throw std::runtime_error("operator Operator::ADD has incorrect operands quantity");

			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrFirst = m_operands.begin();
			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrSecond = ++(m_operands.begin());

			setValue((*itrFirst) -> getValue() + (*itrSecond) -> getValue());
			break;
		}


		case Operator::SUB:
		{
			if(m_operands.size() != 2)
				throw std::runtime_error("operator Operator::SUB has incorrect operands quantity");

			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrFirst = m_operands.begin();
			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrSecond = ++(m_operands.begin());

			setValue((*itrFirst) -> getValue() - (*itrSecond) -> getValue());
			break;
		}


		case Operator::MUL:
		{
			if(m_operands.size() != 2)
			{
				throw std::runtime_error("operator Operator::MUL has incorrect operands quantity");
			}

			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrFirst = m_operands.begin();
			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrSecond = ++(m_operands.begin());

			setValue((*itrFirst) -> getValue() * (*itrSecond) -> getValue());
			break;
		}



		case Operator::DIV:
		{
			if(m_operands.size() != 2)
				throw std::runtime_error("operator Operator::MUL has incorrect operands quantity");

			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrFirst = m_operands.begin();
			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrSecond = ++(m_operands.begin());
			setValue((*itrFirst) -> getValue() / (*itrSecond) -> getValue());
			break;
		}



		case Operator::ASSIGN:
		{
			if(m_operands.size() != 2)
				throw std::runtime_error("operator Operator::MUL has incorrect operands quantity");

			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrFirst = m_operands.begin();
			std::list<boost::shared_ptr<AbstractNode> >::const_iterator itrSecond = ++(m_operands.begin());

			(*itrFirst) -> setValue((*itrSecond) -> getValue());

			setValue((*itrFirst) -> getValue());
			break;
		}




		case Operator::NONE:
			break;
	}

}
