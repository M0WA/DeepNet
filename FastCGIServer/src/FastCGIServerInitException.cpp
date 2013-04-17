/*
 * FastCGIServerInitException.cpp
 *
 *  Created on: 08.11.2012
 *      Author: Moritz Wagner
 */

#include "FastCGIServerInitException.h"

namespace fastcgiserver {

FastCGIServerInitException::FastCGIServerInitException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& message)
: FastCGIServerException(file,line,function,"FastCGIServerInitException", message){
}

FastCGIServerInitException::~FastCGIServerInitException() {
}

}
