/**
 * @file FastCGISocket.h
 * @author Moritz Wagner
 * @date 12.03.2012
 */

#pragma once

#include <string>

namespace fastcgiserver {

/**
 * implements generic file and IP socket for FastCGI server applications
 */
class FastCGISocket {
public:
	/**
	 * creates a FastCGI IP socket
	 * @param port tcp port
	 * @param backlog backlog of socket (0 = unlimited)
	 */
	FastCGISocket(const int port, const int backlog = 0);

	/**
	 * creates a FastCGI file socket
	 * @param filename filename of socket
	 * @param backlog backlog of socket (0 = unlimited)
	 */
	FastCGISocket(const std::string& filename, const int backlog = 0);
	virtual ~FastCGISocket();

public:
	/**
	 * waits max. one second for a successful connection on this
	 * sockets before it returns
	 * @return true if a new request has to handled, false if no connection was made
	 */
	bool WaitForAccept();

public:
	/**
	 * returns socket handle or -1 if socket is invalid
	 * @return socket handle
	 */
	inline int Socket() const { return socket; }

private:
	void SetNonBlocking(bool isNonBlocking = true);

private:
	int socket;
	int backlog;
	int port;
	std::string filename;
};

}
