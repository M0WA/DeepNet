/**
 *
 * @file SocketFile.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "SocketFile.h"

namespace networking {

SocketFile::SocketFile(const std::string& fileName)
: networking::Socket()
, fileName(fileName){
}

SocketFile::SocketFile(int socket,const std::string& fileName)
: networking::Socket(socket)
, fileName(fileName){
}

SocketFile::~SocketFile() {
}

bool SocketFile::OnCreate() {
	return false;
}

bool SocketFile::OnClose() {
	return false;
}

}
