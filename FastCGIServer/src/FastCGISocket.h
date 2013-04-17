/*
 * FastCGISocket.h
 *
 *  Created on: 12.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace fastcgiserver {

class FastCGISocket {
public:
	FastCGISocket(const int port, const int backlog = 0);
	FastCGISocket(const std::string& filename, const int backlog = 0);
	virtual ~FastCGISocket();

public:
	bool WaitForAccept();

public:
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
