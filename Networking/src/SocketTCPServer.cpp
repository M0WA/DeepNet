/**
 *
 * @file SocketTCPServer.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "SocketTCPServer.h"

#include "SocketTCPClient.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>

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

bool SocketTCPServer::WaitForAccept(struct timeval& timeout) {
	return WaitForAccept(&timeout);
}

bool SocketTCPServer::WaitForAccept() {
	return WaitForAccept(0);
}

bool SocketTCPServer::Accept(tools::Pointer<SocketTCPClient>& newClient,struct timeval& timeout) {
	return Accept(newClient,&timeout);
}

bool SocketTCPServer::Accept(tools::Pointer<SocketTCPClient>& newClient){
	return Accept(newClient,0);
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

bool SocketTCPServer::WaitForAccept(struct timeval* timeout) {

	fd_set readFD;
	FD_ZERO(&readFD);
	FD_SET(this->socket, &readFD);

	if(timeout)
		SetNonBlocking();
	else
		SetBlocking();

	int err(select(socket+1,&readFD,NULL,NULL,timeout));

	if(timeout)
		SetBlocking();

	return (err == 1 && FD_ISSET(this->socket,&readFD));

}

bool SocketTCPServer::Accept(tools::Pointer<SocketTCPClient>& newClient,struct timeval* timeout) {

	if(!WaitForAccept(timeout)) {
		return false; }

	struct sockaddr_in target;
	socklen_t len(sizeof(target));
	memset(&target,0,len);
	int newSocket(accept(socket,(struct sockaddr*)&target,&len));
	if( newSocket == -1)
		return false;

	newClient.Set(new SocketTCPClient(newSocket,target),true);
	return true;
}


}
