/**
 *
 * @file SocketFile.h
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#pragma once

#include <string>

#include <MemoryContainer.h>

#include "Socket.h"

namespace networking {

/**
 * @brief implements a generic file socket
 */
class SocketFile : public networking::Socket {
public:
	/**
	 * creates file socket
	 * @param fileName filename of this socket
	 */
	SocketFile(const std::string& fileName);

	/**
	 * creates file socket from an existing handle
	 * @param socket existing file socket handle
	 * @param fileName filename of this socket
	 */
	SocketFile(int socket,const std::string& fileName);
	virtual ~SocketFile();

protected:
	virtual bool OnCreate();
	virtual bool OnClose();
	virtual size_t OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const size_t& timeoutSec);
	virtual size_t OnWrite(const unsigned char* data, const size_t& dataSize);

protected:
	/**
	 * filename of this socket
	 */
	std::string fileName;
};

}
