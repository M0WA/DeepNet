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

class SocketFile : public networking::Socket {
public:
	SocketFile(const std::string& fileName);
	SocketFile(int socket,const std::string& fileName);
	virtual ~SocketFile();

private:
	virtual bool OnCreate();
	virtual bool OnClose();
	virtual size_t OnRead(tools::MemoryContainer<unsigned char>& data, const size_t& maxRead, const size_t& timeoutSec);
	virtual size_t OnWrite(const unsigned char* data, const size_t& dataSize);

protected:
	std::string fileName;
};

}
