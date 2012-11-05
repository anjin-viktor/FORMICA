#include "ExecutionTree.h"


ExecutionTree::ExecutionTree()
{
	m_root = boost::shared_ptr<AbstractNode>(new AbstractNode);
}


ExecutionTree::~ExecutionTree()
{
}




boost::shared_ptr<AbstractNode> ExecutionTree::root()
{
	return m_root;
}
