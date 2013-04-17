/*
 * SocketIPv4.h
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <netinet/in.h>
#include <sys/time.h>

#include "Socket.h"

namespace network {

class SocketIPv4 : public Socket {
public:
	SocketIPv4(int sock, int type, int protocol);
	SocketIPv4(int type, int protocol);
	virtual ~SocketIPv4();

public:
	bool GetPeerName(struct sockaddr_in& address);

public:
	virtual void GetPending(size_t& pendingBytes);
	virtual bool IsReadable(const struct timeval* const timeout);
	virtual bool IsWriteable(const struct timeval* const timeout);
};

}
