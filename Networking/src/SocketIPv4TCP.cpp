/*
 * SocketIPv4TCP.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#include "SocketIPv4TCP.h"

#include <sys/socket.h>
#include <cstdlib>
#include <unistd.h>
#include <sys/ioctl.h>
#include <netinet/in.h>

#include <TimeTools.h>
#include <PerformanceCounter.h>

namespace network {

SocketIPv4TCP::SocketIPv4TCP()
: SocketIPv4(SOCK_STREAM,IPPROTO_TCP) {
}

SocketIPv4TCP::SocketIPv4TCP(int sock)
: SocketIPv4(sock,SOCK_STREAM,IPPROTO_TCP) {
}

SocketIPv4TCP::~SocketIPv4TCP() {
}

bool SocketIPv4TCP::IsConnected() {

	if(GetSocket() == -1)
		return false;

	struct sockaddr_in target;
	socklen_t sizeTarget = sizeof(target);

	operationLock.Lock();
	int err = getpeername(GetSocket(),(struct sockaddr*)&target,&sizeTarget);
	operationLock.Unlock();

	return (err == 0);
}

size_t SocketIPv4TCP::OnRead(tools::MemoryContainer<char>& buf, const size_t bufPos, const size_t bytes, const struct timeval* const timeout) {

	buf.EnsureSize(bufPos + bytes,true);

	tools::PerformanceCounter counter;
	timeval durationRead;

	size_t bytesRead = 0,
		   curBufPos = bufPos;

	bool restoreNonBlocking = GetNonBlocking();
	SetNonBlocking(true);

	while( bytes > bytesRead ) {

		size_t dataSize = 0;
		durationRead.tv_sec = 0;
		durationRead.tv_usec = 0;

		counter.Start();
		if(IsReadable(timeout)){

			GetPending(dataSize);
			if(dataSize == 0)
				break;

			size_t bytesMissing = bytes - bytesRead;
			size_t bytesToLoad  = dataSize > bytesMissing ? bytesMissing : dataSize;

			ssize_t curReadBytes = RecvWrapper(buf.GetElementAt(curBufPos),bytesToLoad,0);

			if(curReadBytes < 0) {
				break; }

			bytesRead += curReadBytes;
			curBufPos += curReadBytes;
		}
		else {
			break;
		}
		counter.Stop(durationRead);
	}

	SetNonBlocking(restoreNonBlocking);
	return bytesRead;
}

bool SocketIPv4TCP::OnWrite(const char* buf, const size_t& bytes) {

	bool restoreNonBlocking = GetNonBlocking();
	SetNonBlocking(false);

	ssize_t sent = SendWrapper(buf, bytes, 0);

	SetNonBlocking(restoreNonBlocking);
	return ( sent > -1 && (size_t)sent == bytes );
}

}
