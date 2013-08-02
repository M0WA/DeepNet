/**
 *
 * @file SocketIP.h
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#pragma once

#include "Socket.h"

#include <netinet/in.h>
#include <MemoryContainer.h>

namespace networking {

class SocketIP: public networking::Socket {
protected:
	SocketIP(const struct in_addr& ip);
	SocketIP(int socket,const struct in_addr& ip);
public:
	virtual ~SocketIP();

private:
	virtual bool OnClose();

protected:
	struct in_addr ip;
};

}