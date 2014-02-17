/**
 *
 * @file InvalidOperationException.cpp
 * @author Moritz Wagner
 * @date 17.02.2014
 *
 */

#include "InvalidOperationException.h"

namespace errors {

InvalidOperationException::InvalidOperationException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& module)
: errors::Exception(file,line,function,module,"InvalidOperationException","operation is invalid"){
}

InvalidOperationException::~InvalidOperationException() {
}

}
