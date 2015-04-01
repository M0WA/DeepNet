/**
 *
 * @file SocketIP.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "SocketIP.h"

#include <sys/socket.h>

namespace networking {

SocketIP::SocketIP(const struct in_addr& ip)
: Socket()
, ip(ip){
}

SocketIP::SocketIP(int socket,const struct in_addr& ip)
: Socket(socket)
, ip(ip){
}

SocketIP::~SocketIP() {
}

bool SocketIP::OnClose() {
	if(socket > -1) {
		shutdown(socket,2);
		socket = -1; }
	return true;
}

}
