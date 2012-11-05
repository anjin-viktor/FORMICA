#ifndef FUNCTION_H_
#define FUNCTION_H_


/**
@file Function.h
*/

#include <list>
#include <string>
#include <cstdlib>
#include <stdexcept>

#include <gmpxx.h>

#include "ExecutionTree.h"
#include "Context.h"


/**
@class Function
@brief this class representation function. Function is a association of execution tree and parameter names.
*/

class Function
{
	public:
		Function();
		Function(const ExecutionTree &);
		~Function();

		void setExecutionTree(const ExecutionTree &);

/**
Additional parameter name. You must add params from left to right.
*/
		void addParam(const std::string &);
		std::size_t paramQuantity() const;
/**
Creating context of execution along function and the list of arguments
*/
		Context createContext(const std::list<mpf_class> &) const;

	private:
		std::list<std::string>		m_paramNames;
		ExecutionTree				m_execTree;
};



#endif
