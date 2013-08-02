/*
 * FastCGISocket.cpp
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#include "FastCGISocket.h"

#include <sstream>
#include <fcgio.h>
#include <fcgi_config.h>  // HAVE_IOSTREAM_WITHASSIGN_STREAMBUF
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include "FastCGIServerSocketException.h"

#include <Logging.h>

namespace fastcgiserver {

FastCGISocket::FastCGISocket(const int port, const int backlog)
: backlog(backlog)
, port(port)
, filename() {
	std::stringstream ssPortName;
	ssPortName << "127.0.0.1:" << port;
	socket = FCGX_OpenSocket(ssPortName.str().c_str(),backlog);

	if(socket == -1)
		THROW_EXCEPTION(FastCGIServerSocketException,"could not create tcp socket");
}

FastCGISocket::FastCGISocket(const std::string& filename, const int backlog)
: socket(FCGX_OpenSocket(filename.c_str(),backlog))
, backlog(backlog)
, port(-1)
, filename(filename) {

	if(socket == -1)
		THROW_EXCEPTION(FastCGIServerSocketException,"could not create file socket");
}

FastCGISocket::~FastCGISocket() {

	if(socket>=0)
		close(socket);
	socket = -1;
}

void FastCGISocket::SetNonBlocking(bool isNonBlocking) {

	if(socket <= 0)
		return;

	int flags(fcntl(socket, F_GETFL, 0));

	if(isNonBlocking)
		fcntl(socket, F_SETFL, flags | O_NONBLOCK);
	else
		fcntl(socket, F_SETFL, flags & ~O_NONBLOCK);
}

bool FastCGISocket::WaitForAccept() {

	fd_set readFD;
	FD_ZERO(&readFD);
	FD_SET(socket, &readFD);

	struct timeval timeout;
	timeout.tv_usec = 0;
	timeout.tv_sec = 1;

	SetNonBlocking();

	int err(select(socket+1,&readFD,NULL,NULL,&timeout));

	SetNonBlocking(false);

	return (err == 1 && FD_ISSET(socket,&readFD));
}

}
