#ifndef CONTEXT_H_
#define CONTEXT_H_

/**
@file Context.h
*/


#include <map>
#include <string>

#include <gmpxx.h>

#include "ExecutionTree.h"

/**
@class Context
Is a context of execution 
*/


struct Context
{
	ExecutionTree 						execTree;
	std::map<std::string, mpf_class>	varTab;
};



#endif
