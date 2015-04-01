/*
 * FastCGIServerSocketException.cpp
 *
 *  Created on: 08.11.2012
 *      Author: Moritz Wagner
 */

#include "FastCGIServerSocketException.h"

namespace fastcgiserver {

FastCGIServerSocketException::FastCGIServerSocketException(
		const std::string& file,
		const int line,
		const std::string& function,
		const std::string& message)
: FastCGIServerException(file,line,function,"FastCGIServerSocketException", message){
}

FastCGIServerSocketException::~FastCGIServerSocketException() {
}

}
