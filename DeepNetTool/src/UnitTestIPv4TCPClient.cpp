/*
 * UnitTestIPv4TCPClient.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: Moritz Wagner
 */

#include "UnitTestIPv4TCPClient.h"

#include <cstring>
#include <cstdlib>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

static const char* htmlGet = "GET / HTTP/1.1\r\n\r\n\r\n";

namespace toolbot {

UnitTestIPv4TCPClient::UnitTestIPv4TCPClient() {
}

UnitTestIPv4TCPClient::~UnitTestIPv4TCPClient() {
}

bool UnitTestIPv4TCPClient::Test(const std::string& ip, const int& port) {

	bool success = true;
	success &= TestLinearConnection(ip, port);
	return success;
}

bool UnitTestIPv4TCPClient::TestLinearConnection(const std::string& ip, const int& port) {

	network::SocketIPv4TCPClient client;

	struct sockaddr_in target;
	target.sin_family = AF_INET;
	inet_aton(ip.c_str(),&target.sin_addr);
	target.sin_port = htons(port);

	if(!client.Connect(target))
		return false;

	if(!client.Write(htmlGet,strlen(htmlGet)))
		return false;

	tools::MemoryContainer<char> buf;
	size_t dataRdy = 0;
	struct timeval timeoutTV;
	timeoutTV.tv_sec = 3;
	timeoutTV.tv_usec = 0;
	if(!client.IsReadable(&timeoutTV))
		return false;

	client.GetPending(dataRdy);
	if(dataRdy == 0)
		return false;

	if(client.Read(buf, 0, dataRdy, &timeoutTV) != dataRdy)
		return false;

	client.Close();
	return true;
}

}
