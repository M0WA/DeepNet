/**
 *
 * @file Socket.cpp
 * @author Moritz Wagner
 * @date 02.08.2013
 *
 */

#include "Socket.h"

#include <fcntl.h>

namespace networking {

Socket::Socket()
: socket(-1){
}

Socket::Socket(int socket)
: socket(socket){
}

Socket::~Socket() {
	Close();
}

bool Socket::Create()
{
	return OnCreate();
}

size_t Socket::Read(
	tools::MemoryContainer<unsigned char>& data,
	const size_t& maxRead,
	const size_t& timeoutSec)
{
	return OnRead(data,maxRead,timeoutSec);
}

bool Socket::Close()
{
	if(socket != -1)
		return OnClose();
	else
		return true;
}

size_t Socket::Write(
	const unsigned char* data,
	const size_t& dataSize)
{
	return OnWrite(data,dataSize);
}

void Socket::SetNonBlocking() {

	if(socket <= 0)
		return;

	int flags(fcntl(socket, F_GETFL, 0));
	fcntl(socket, F_SETFL, flags | O_NONBLOCK);
}

void Socket::SetBlocking() {

	if(socket <= 0)
		return;

	int flags(fcntl(socket, F_GETFL, 0));
	fcntl(socket, F_SETFL, flags & ~O_NONBLOCK);
}

}
