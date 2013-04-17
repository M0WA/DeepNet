/*
 * SocketIPv4TCPClient.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#include "SocketIPv4TCPClient.h"

#include <netinet/in.h>
#include <cerrno>
extern int errno;

#include <Logging.h>

namespace network {

SocketIPv4TCPClient::SocketIPv4TCPClient()
: SocketIPv4TCP() {
}

SocketIPv4TCPClient::SocketIPv4TCPClient(int sock)
: SocketIPv4TCP(sock) {
}

SocketIPv4TCPClient::~SocketIPv4TCPClient() {
}

bool SocketIPv4TCPClient::Connect(const struct sockaddr_in& target) {

	return Connect(target, NULL);
}

bool SocketIPv4TCPClient::Connect(const struct sockaddr_in& target, const struct timeval* const timeout) {

	bool restoreBlocking = GetNonBlocking();
	SetNonBlocking((timeout != NULL));

	operationLock.Lock();
	int err = connect(GetSocket(),reinterpret_cast<const struct sockaddr*>(&target),sizeof(target));
	operationLock.Unlock();

	SetNonBlocking(restoreBlocking);

	if(err >= 0) {
		return true; }
	else if ((err < 0) && (errno == EINPROGRESS)){
		return IsWriteable(timeout); }
	else {
		return false; }
}

}
