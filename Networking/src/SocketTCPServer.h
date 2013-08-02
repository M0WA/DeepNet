/**
 *
 * @file SocketTCPServer.h
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#pragma once

#include "SocketTCP.h"

#include <netinet/in.h>

#include <Pointer.h>

namespace networking {

	class SocketTCPClient;

/**
 * @brief implements a TCP server socket which accepts connections on specified ip and port combinations
 */
class SocketTCPServer: protected networking::SocketTCP {
public:
	/**
	 * creates tcp server socket
	 * @param ipendpoint bind address of server (INADDR_ANY for all IPs)
	 * @param backlog backlog for this socket
	 */
	SocketTCPServer(
		const struct sockaddr_in& endpoint,
		const int backlog);

	/**
	 * creates tcp server socket from an existing socket
	 * @param socket socket to create from
	 * @param endpoint bind address of server (INADDR_ANY for all IPs)
	 * @param backlog backlog for this socket
	 */
	SocketTCPServer(
		int socket,
		const struct sockaddr_in& endpoint,
		const int backlog);

	virtual ~SocketTCPServer();

public:
	/**
	 * waits for accept until timeout occures or a successful connection occured.
	 * Accept() still has to be called to retrieve the new connection.
	 * @param timeout timeout to wait for new connection
	 * @return true if new client is available, false if no client has connected
	 */
	bool WaitForAccept(struct timeval& timeout);

	/**
	 * waits max. one second for a successful connection on this
	 * sockets before it returns. Accept() still has to be called to retrieve the new connection.
	 * @return true if a new request has to handled, false if no connection was made
	 */
	bool WaitForAccept();

	bool Accept(tools::Pointer<SocketTCPClient>& newClient,struct timeval& timeout);
	bool Accept(tools::Pointer<SocketTCPClient>& newClient);

private:
	virtual bool OnCreate();

private:
	int backlog;
};

}
