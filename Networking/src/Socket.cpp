/*
 * Socket.cpp
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#include "Socket.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <TimeTools.h>

namespace network {

Socket::Socket(int domain, int type, int protocol)
: sock(-1)
, socketOptions(domain, type, protocol) {

	Create();
}

Socket::Socket(int sock, int domain, int type, int protocol)
: sock(sock)
, socketOptions(domain, type, protocol) {
}

Socket::~Socket() {

	Close();
}

bool Socket::Create() {

	Close();

	if(socketOptions.uploadLimit > 0)
		shapingUpload.Start(socketOptions.uploadLimit,socketOptions.uploadLimit);

	if(socketOptions.downloadLimit > 0)
		shapingDownload.Start(socketOptions.downloadLimit,socketOptions.downloadLimit);

	operationLock.Lock();
	sock = socket(socketOptions.domain,socketOptions.type,socketOptions.protocol);
	operationLock.Unlock();
	return OnCreate(sock > -1);
}

bool Socket::OnCreate(const bool success) {
	return success;
}

void Socket::Close() {

	if(sock != -1) {
		OnClose();

		operationLock.Lock();
		shutdown(sock,SHUT_RDWR);
		operationLock.Unlock();
		sock = -1;
	}

	shapingUpload.Stop();
	shapingDownload.Stop();
}

void Socket::OnClose() {
}

void Socket::SetNonBlocking(bool isNonBlocking) {

	if(sock != -1) {

		operationLock.Lock();
		int flags = fcntl(sock, F_GETFL);
		if(isNonBlocking) {
			flags |= O_NONBLOCK; }
		else {
			flags &= ~O_NONBLOCK; }

		fcntl(sock, F_SETFL, flags);
		operationLock.Unlock();
	}
}

bool Socket::GetNonBlocking() {

	if(sock != -1) {

		operationLock.Lock();
		int flags = fcntl(sock, F_GETFL);
		operationLock.Unlock();
		flags &= O_NONBLOCK;
		return flags;
	}

	return false;
}

size_t Socket::Read(tools::MemoryContainer<char>& buf, const size_t bufPos, const size_t bytesToRead, const struct timeval* const timeout) {

	if(sock == -1)
		return 0;

	size_t bytesRead = OnRead(buf,bufPos,bytesToRead,timeout);

	if(socketOptions.downloadLimit > 0) {
		operationLock.Lock();
		shapingDownload.RemoveTokens(bytesToRead);
		operationLock.Unlock();
	}

	return bytesRead;
}

bool Socket::Write(const char* buf, const size_t& bytes) {

	if(sock == -1)
		return 0;

	bool success = OnWrite(buf,bytes);

	if(socketOptions.uploadLimit > 0) {
		operationLock.Lock();
		shapingUpload.RemoveTokens(bytes);
		operationLock.Unlock();
	}

	return success;
}

ssize_t Socket::RecvWrapper(void *buf, size_t n, int flags) {

	if(sock == -1)
		return -1;

	operationLock.Lock();
	ssize_t received = recv(sock,buf,n,flags);
	operationLock.Unlock();
	return received;
}

ssize_t Socket::SendWrapper(const void *buf, size_t n, int flags){

	if(sock == -1)
		return -1;

	operationLock.Lock();
	ssize_t sent = send(GetSocket(), buf, n, flags);
	operationLock.Unlock();
	return sent;
}

}
