/**
 *
 * @file SocketTCPClient.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "SocketTCPClient.h"

#include <sys/socket.h>

namespace networking {

SocketTCPClient::SocketTCPClient(const struct sockaddr_in& endpoint)
: SocketTCP(endpoint){
}

SocketTCPClient::SocketTCPClient(int socket,const struct sockaddr_in& endpoint)
: SocketTCP(socket,endpoint){
}

SocketTCPClient::~SocketTCPClient() {
}

bool SocketTCPClient::Connect() {

	if(connect(socket,(struct sockaddr*)&ip,sizeof(ip)) == -1)
		return false;

	return true;

}

}
