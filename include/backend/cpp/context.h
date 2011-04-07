

#ifndef __BACKEDN_CONTEXT_H__
#define __BACKEDN_CONTEXT_H__

#include <as/ast/expression.h>
#include <as/ast/call.h>
#include <fstream>

namespace tw { namespace maple { namespace backend { namespace cpp {


struct Context
{
	std::ofstream ofs_stream;
};

} } } }

#endif 
