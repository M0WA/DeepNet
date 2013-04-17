/*
 * UnitTestIPv4TCPServer.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: Moritz Wagner
 */

#include "UnitTestIPv4TCPServer.h"

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

namespace toolbot {

UnitTestIPv4TCPServer::UnitTestIPv4TCPServer()
: state(ASYNC_IDLE){
}

UnitTestIPv4TCPServer::~UnitTestIPv4TCPServer() {
}

bool UnitTestIPv4TCPServer::Test(const std::string& ip, const int& port) {

	struct sockaddr_in target;
	target.sin_family = AF_INET;
	inet_aton(ip.c_str(),&target.sin_addr);
	target.sin_port = htons(port);

	if(!server.Bind(target,3))
		return false;

	if(!server.AcceptAsync(&OnAcceptCallback,this))
		return false;

	state = ASYNC_PENDING;

	network::SocketIPv4TCPClient client;
	if(!client.Connect(target)){
		server.EndAcceptAsync();
		state = ASYNC_ERROR;
	}
	client.Close();

	while(state == ASYNC_PENDING) {
		usleep(1000*1000); }
	server.EndAcceptAsync();

	return (state == ASYNC_SUCCESS);
}

void UnitTestIPv4TCPServer::OnAcceptCallback(const network::SocketIPv4TCPServer::AcceptEventParam& e) {

	UnitTestIPv4TCPServer* server = reinterpret_cast<UnitTestIPv4TCPServer*>(e.userParam);
	server->state = (e.newClient ? ASYNC_SUCCESS : ASYNC_ERROR );
	delete e.newClient;
}

}
