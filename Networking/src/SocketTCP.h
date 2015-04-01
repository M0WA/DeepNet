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

/**
 * @brief generic implementation of a TCP socket
 * @see networking::SocketTCPServer
 * @see networking::SocketTCPClient
 */
class SocketTCP : public networking::SocketIP {

protected:
	/**
	 * creates a TCP socket
	 * @param endpoint associated endpoint
	 */
	SocketTCP(const struct sockaddr_in& endpoint);

	/**
	 * creates a TCP socket from an existing socket
	 * @param socket existing socket
	 * @param endpoint associated endpoint
	 */
	SocketTCP(int socket,const struct sockaddr_in& endpoint);

public:
	virtual ~SocketTCP();

protected:
	virtual bool OnCreate();
	virtual size_t OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const struct timeval* timeout);
	virtual size_t OnWrite(const unsigned char* data, const size_t& dataSize);

private:
	bool WaitForRead(const size_t& timeoutSec);

protected:
	/**
	 * endpoint for this socket
	 */
	struct sockaddr_in endpoint;
};

}
