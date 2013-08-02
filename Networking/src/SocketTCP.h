/**
 *
 * @file SocketTCP.h
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#pragma once

#include "SocketIP.h"

namespace networking {

class SocketTCP : public networking::SocketIP {

protected:
	SocketTCP(const struct sockaddr_in& endpoint);
	SocketTCP(int socket,const struct sockaddr_in& endpoint);

public:
	virtual ~SocketTCP();

protected:
	virtual bool OnCreate();
	virtual size_t OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const size_t& timeoutSec);
	virtual size_t OnWrite(const unsigned char* data, const size_t& dataSize);

protected:
	struct sockaddr_in endpoint;
};

}
