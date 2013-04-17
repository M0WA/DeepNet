/*
 * Socket.h
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <sys/time.h>

#include "SocketOptions.h"

#include <Mutex.h>
#include <MemoryContainer.h>
#include <TokenBucket.h>

namespace network {

class Socket {

public:
	Socket(int domain, int type, int protocol);
	Socket(int sock, int domain, int type, int protocol);
	virtual ~Socket();

public:
	virtual bool Create();
	virtual void Close();

public:
	void SetNonBlocking() { SetNonBlocking(true); }
	virtual void SetNonBlocking(bool isNonBlocking);
	virtual bool GetNonBlocking();

public:
	SocketOptions& GetSocketOptions() { return socketOptions; }
	const SocketOptions& GetConstSocketOptions() const { return socketOptions; }

public:
	size_t Read(tools::MemoryContainer<char>& buf, const size_t bufPos, const size_t bytesToRead, const struct timeval* const timeout);
	bool   Write(const char* buf, const size_t& bytes);

protected:
	int GetSocket() const { return sock; }

protected:
	virtual ssize_t RecvWrapper(void *buf, size_t n, int flags);
	virtual ssize_t SendWrapper(const void *buf, size_t n, int flags);

protected:
	virtual size_t OnRead(tools::MemoryContainer<char>& buf, const size_t bufPos, const size_t bytesToRead, const struct timeval* const timeout)=0;
	virtual bool   OnWrite(const char* buf, const size_t& bytes)=0;
	virtual bool   OnCreate(const bool success);
	virtual void   OnClose();

protected:
	threading::Mutex operationLock;

private:
	int sock;

	tools::TokenBucket shapingUpload;
	tools::TokenBucket shapingDownload;

	SocketOptions socketOptions;
};

}
