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
class SocketTCPServer: public networking::SocketTCP {
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
	 * accepts new client on this socket, blocks until new connection has arrived or timeout occurs.
	 * @param newClient new client if successful
	 * @param timeout timeout to wait for new connection
	 * @return true if new client is available, false if no client has connected
	 */
	bool Accept(tools::Pointer<SocketTCPClient>& newClient,struct timeval& timeout);

	/**
	 * accepts new client on this socket, blocks until new connection has arrived
	 * @param newClient new client if successful
	 * @return true if new client is available, false if no client has connected
	 */
	bool Accept(tools::Pointer<SocketTCPClient>& newClient);

	/**
	 * waits for accept until timeout occures or a successful connection occured.
	 * Accept() still has to be called to retrieve the new connection.
	 * @param timeout timeout to wait for new connection
	 * @return true if new client is available, false if no client has connected
	 */
	bool WaitForAccept(struct timeval& timeout);

	/**
	 * waits blocking for a successful connection on this sockets before it returns.
	 * Accept() still has to be called to retrieve the new connection.
	 * @return true if a new request has to handled, false if no connection was made
	 */
	bool WaitForAccept();

protected:
	virtual bool OnCreate();

private:
	bool WaitForAccept(struct timeval* timeout);
	bool Accept(tools::Pointer<SocketTCPClient>& newClient,struct timeval* timeout);

private:
	int backlog;
};

}
