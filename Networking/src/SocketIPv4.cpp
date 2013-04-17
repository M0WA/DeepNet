/*
 * SocketIPv4.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#include "SocketIPv4.h"

#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

#include <TimeTools.h>

namespace network {

SocketIPv4::SocketIPv4(int sock, int type, int protocol)
: Socket(sock, AF_INET, type, protocol) {

	Close();
}

SocketIPv4::SocketIPv4(int type, int protocol)
: Socket(AF_INET, type, protocol) {
}

SocketIPv4::~SocketIPv4() {
}

bool SocketIPv4::GetPeerName(struct sockaddr_in& address) {

	if(GetSocket() == -1)
		return false;

	socklen_t len = sizeof(address);
	operationLock.Lock();
	bool success = (getpeername(GetSocket(), reinterpret_cast<struct sockaddr*>(&address), &len) == 0);
	operationLock.Unlock();
	return success;
}

void SocketIPv4::GetPending(size_t& pendingBytes) {

	int bytesAv = 0;
	pendingBytes = 0;

	operationLock.Lock();
	int retIO = ioctl(GetSocket(),FIONREAD,&bytesAv);
	operationLock.Unlock();

	pendingBytes = (retIO < 0) ? 0 : bytesAv;
}

bool SocketIPv4::IsReadable(const struct timeval* const timeout) {

	if(GetSocket() == -1)
		return false;

	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(GetSocket(),&readfds);

	timeval tmpTimeout;
	if(timeout != NULL)
		tmpTimeout = *timeout;

	operationLock.Lock();
	int err = select(GetSocket()+1,&readfds,NULL,NULL,(timeout != NULL ? &tmpTimeout : NULL));
	operationLock.Unlock();

	if(err <= 0 || !FD_ISSET(GetSocket(),&readfds)) {
		return false;
	}

	return true;
}

bool SocketIPv4::IsWriteable(const struct timeval* const timeout) {

	if(GetSocket() == -1)
		return false;

	fd_set writefds;
	FD_ZERO(&writefds);
	FD_SET(GetSocket(),&writefds);

	timeval tmpTimeout;
	if(timeout != NULL)
		tmpTimeout = *timeout;

	operationLock.Lock();
	int err = select(GetSocket()+1,NULL,&writefds,NULL,(timeout != NULL ? &tmpTimeout : NULL));
	operationLock.Unlock();

	if(err <= 0 || !FD_ISSET(GetSocket(),&writefds)) {
		return false;}

	return true;
}

}
