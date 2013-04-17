/*
 * SocketIPv4TCPServer.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#include "SocketIPv4TCPServer.h"

#include <cerrno>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "SocketIPv4TCPClient.h"

extern int errno;

namespace network {

SocketIPv4TCPServer::SocketIPv4TCPServer()
: acceptThread(0) {
}

SocketIPv4TCPServer::~SocketIPv4TCPServer() {
}

bool SocketIPv4TCPServer::Bind(int port, const socklen_t& backlog) {

	struct sockaddr_in listenIf;
	listenIf.sin_family = GetConstSocketOptions().domain;
	listenIf.sin_addr.s_addr = INADDR_ANY;
	listenIf.sin_port = htons(port);

	return Bind(listenIf, backlog);
}

bool SocketIPv4TCPServer::Bind(const struct sockaddr_in& listenIf, const socklen_t& backlog) {

	if(GetSocket() == -1)
		return false;

	if( bind(GetSocket(), reinterpret_cast<const struct sockaddr*>(&listenIf), sizeof(listenIf)) != 0 )
		return false;

	if( listen(GetSocket(), backlog) != 0 )
		return false;

	return true;
}

bool SocketIPv4TCPServer::AcceptAsync(OnAcceptCallback callback, void* userParam) {

	if(GetSocket() == -1)
		return false;

	EndAcceptAsync();

	acceptThread = new ServerAcceptThread(this,callback,userParam);
	return true;
}

void SocketIPv4TCPServer::Close() {

	EndAcceptAsync();
	SocketIPv4TCP::Close();
}

void SocketIPv4TCPServer::EndAcceptAsync() {

	if(acceptThread) {
		acceptThread->SetShallEnd(true);
		acceptThread->WaitForThread();
		delete acceptThread;
		acceptThread = 0;
	}
}

void* SocketIPv4TCPServer::ServerAcceptThread::AcceptFunc(threading::Thread::THREAD_PARAM* param) {

	ServerAcceptThread*  threadInstance = dynamic_cast<ServerAcceptThread*>(param->instance);
	SocketIPv4TCPServer* serverInstance = threadInstance->server;

	bool recoverBlocking = serverInstance->GetNonBlocking();

	while(!threadInstance->ShallEnd()) {

		serverInstance->SetNonBlocking();

		int acc = accept(serverInstance->GetSocket(), 0, 0);
		if(acc < 0 && errno != EWOULDBLOCK && errno != EAGAIN) {
			//error
			serverInstance->SetNonBlocking(recoverBlocking);
			break;
		}
		else if (acc < 0) {
			//no clients
			usleep(1000 * 1000);
		}
		else {
			threadInstance->callback(AcceptEventParam(new SocketIPv4TCPClient(acc),threadInstance->userParam));
		}

		serverInstance->SetNonBlocking(recoverBlocking);
	}

	return 0;
}

}
