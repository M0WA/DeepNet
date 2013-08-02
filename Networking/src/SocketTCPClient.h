/**
 *
 * @file SocketTCPClient.h
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#pragma once

#include "SocketTCP.h"

namespace networking {

class SocketTCPClient: public networking::SocketTCP {
public:
	SocketTCPClient(const struct sockaddr_in& endpoint);
	SocketTCPClient(int socket,const struct sockaddr_in& endpoint);
	virtual ~SocketTCPClient();

public:
	bool Connect();
};

}
