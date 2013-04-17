/*
 * SocketIPv4TCP.h
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <sys/time.h>

#include <Thread.h>
#include <MemoryContainer.h>

#include "SocketIPv4.h"

namespace network {

class SocketIPv4TCP : public SocketIPv4 {

	friend class SocketIPv4TCPServer;

public:
	SocketIPv4TCP();
	SocketIPv4TCP(int sock);
	virtual ~SocketIPv4TCP();

public:
	bool IsConnected();

protected:
	virtual size_t OnRead(tools::MemoryContainer<char>& buf, const size_t bufPos, const size_t bytesToRead, const struct timeval* const timeout);
	virtual bool   OnWrite(const char* buf, const size_t& bytes);
};

}
