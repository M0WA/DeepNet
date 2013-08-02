/**
 *
 * @file SocketTCPServer.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "SocketTCPServer.h"

#include <sys/socket.h>
#include <netinet/in.h>

namespace networking {

SocketTCPServer::SocketTCPServer(const struct sockaddr_in& endpoint, const int backlog)
: networking::SocketTCP(endpoint)
, backlog(backlog){
}

SocketTCPServer::SocketTCPServer(int socket,const struct sockaddr_in& endpoint, const int backlog)
: networking::SocketTCP(endpoint)
, backlog(backlog){
}

SocketTCPServer::~SocketTCPServer() {
}

bool SocketTCPServer::OnCreate() {

	if(!SocketTCP::OnCreate())
		return false;

	if(bind(this->socket,(struct sockaddr*)&ip,sizeof(ip)) == -1){
		Close();
		return false; }

	if(listen(this->socket,backlog) == -1){
		Close();
		return false; }

	return (socket < -1);
}

bool SocketTCPServer::WaitForAccept(struct timeval& timeout) {

	fd_set readFD;
	FD_ZERO(&readFD);
	FD_SET(this->socket, &readFD);

	SetNonBlocking();

	int err(select(socket+1,&readFD,NULL,NULL,&timeout));

	SetBlocking();

	return (err == 1 && FD_ISSET(this->socket,&readFD));
}

bool SocketTCPServer::WaitForAccept() {

	struct timeval timeout;
	timeout.tv_usec = 0;
	timeout.tv_sec = 1;

	return WaitForAccept(timeout);
}

}
