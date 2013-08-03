/**
 *
 * @file SocketTCP.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "SocketTCP.h"

namespace networking {

SocketTCP::SocketTCP(const struct sockaddr_in& endpoint)
: SocketIP(endpoint.sin_addr)
, endpoint(endpoint) {
}

SocketTCP::SocketTCP(int socket,const struct sockaddr_in& endpoint)
: SocketIP(socket,endpoint.sin_addr)
, endpoint(endpoint) {
}

SocketTCP::~SocketTCP() {
}

bool SocketTCP::OnCreate() {
	Close();

	this->socket = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if(this->socket == -1) {
		return false; }

	return true;
}

size_t SocketTCP::OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const struct timeval* timeout){
	return 0;
}

size_t SocketTCP::OnWrite(const unsigned char* data, const size_t& dataSize){
	return 0;
}


}
