/**
 *
 * @file NotImplementedException.cpp
 * @author Moritz Wagner
 * @date 15.08.2012
 *
 */

#include "NotImplementedException.h"

namespace errors {

NotImplementedException::NotImplementedException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& module)
: Exception(file,line,function,module,"NotImplementedException","functionality is not implemented"){
}

NotImplementedException::~NotImplementedException() {
}

}
