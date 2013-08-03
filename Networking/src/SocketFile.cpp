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

size_t SocketFile::OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const struct timeval* timeout) {
	return 0;
}

size_t SocketFile::OnWrite(const unsigned char* data, const size_t& dataSize) {
	return 0;
}

}
