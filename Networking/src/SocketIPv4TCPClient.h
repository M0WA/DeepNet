/*
 * SocketIPv4TCPClient.h
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "SocketIPv4TCP.h"

#include <Thread.h>

struct sockaddr_in;

namespace threading {
	class Mutex;
}

namespace network {

class SocketIPv4TCPClient : public SocketIPv4TCP {

public:
	SocketIPv4TCPClient();
	SocketIPv4TCPClient(int sock);
	virtual ~SocketIPv4TCPClient();

public:
	bool Connect(const struct sockaddr_in& target);

public:
	virtual bool Connect(const struct sockaddr_in& target, const struct timeval* const timeout);
};

}
