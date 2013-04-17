/*
 * SocketIPv4TCPSSLClient.cpp
 *
 *  Created on: Feb 14, 2013
 *      Author: Moritz Wagner
 */

#include "SocketIPv4TCPSSLClient.h"

#include <unistd.h>
#include <openssl/ssl.h>
#include <fcntl.h>

namespace network {

SocketIPv4TCPSSLClient::SocketIPv4TCPSSLClient()
: SocketIPv4TCPClient()
, sslMethod(0)
, sslCtx(0)
, ssl(0){
	CreateSSLContext();
}

SocketIPv4TCPSSLClient::SocketIPv4TCPSSLClient(int sock)
: SocketIPv4TCPClient(sock)
, sslMethod(0)
, sslCtx(0)
, ssl(0) {
	CreateSSLContext();
}

SocketIPv4TCPSSLClient::~SocketIPv4TCPSSLClient() {

	DestroySSL();
	DestroySSLContext();
}

bool SocketIPv4TCPSSLClient::OnCreate(const bool success) {

	bool retSuccess = SocketIPv4TCPClient::OnCreate(success);
	if(retSuccess) {
		CreateSSL();
	}
	return retSuccess;
}

bool SocketIPv4TCPSSLClient::Connect(const struct sockaddr_in& target, const struct timeval* const timeout) {

	if(!SocketIPv4TCPClient::Connect(target,timeout)) {
		return false; }

	int err = 0;
	while(1){

		operationLock.Lock();
		err = SSL_do_handshake(ssl);
		operationLock.Unlock();
		if(err == 1)
			return true;

		switch(SSL_get_error(ssl,err))
		{
		case SSL_ERROR_WANT_READ:
			if(!IsReadableSSL(timeout)) {
				return false; }
			break;
		case SSL_ERROR_WANT_WRITE:
			if(!IsWriteable(timeout)) {
				return false; }
			break;
		default:
			return false;
		}
	}
	return true;
}

void SocketIPv4TCPSSLClient::SetNonBlocking(bool isNonBlocking) {

	int fd, flags;

	operationLock.Lock();
	if( (fd = SSL_get_rfd(ssl)) ) {
		flags = fcntl(fd, F_GETFL);
		if(isNonBlocking)
			flags &= O_NONBLOCK;
		else
			flags |= O_NONBLOCK;
		fcntl(fd, F_SETFL, flags);
	}

	if( (fd = SSL_get_wfd(ssl)) )  {
		flags = fcntl(fd, F_GETFL);
		if(isNonBlocking)
			flags &= O_NONBLOCK;
		else
			flags |= O_NONBLOCK;
		fcntl(fd, F_SETFL, flags);
	}
	operationLock.Unlock();
}

bool SocketIPv4TCPSSLClient::GetNonBlocking() {

	int fd, flags;

	bool success = true;
	operationLock.Lock();
	if( (fd = SSL_get_rfd(ssl)) ) {
		flags = fcntl(fd, F_GETFL);
		success &= flags;
	}

	if( (fd = SSL_get_wfd(ssl)) )  {
		flags = fcntl(fd, F_GETFL);
		success &= flags;
	}
	operationLock.Unlock();
	return success;
}

void SocketIPv4TCPSSLClient::OnClose() {

	DestroySSL();
	SocketIPv4TCPClient::OnClose();
}

ssize_t SocketIPv4TCPSSLClient::RecvWrapper(void *buf, size_t n, int flags) {

	operationLock.Lock();
	ssize_t ret = SSL_read(ssl, buf, n);
	operationLock.Unlock();
	return ret;
}

ssize_t SocketIPv4TCPSSLClient::SendWrapper(const void *buf, size_t n, int flags) {

	operationLock.Lock();
	ssize_t ret = SSL_write(ssl, buf, n);
	operationLock.Unlock();
	return ret;
}

void SocketIPv4TCPSSLClient::CreateSSLContext() {

	DestroySSLContext();

	sslMethod = SSLv23_method();
	sslCtx = SSL_CTX_new(const_cast<SSL_METHOD*>(sslMethod));
}

void SocketIPv4TCPSSLClient::DestroySSLContext() {

	if(sslCtx) {
		SSL_CTX_free(sslCtx);
		sslCtx = 0;
	}
}

void SocketIPv4TCPSSLClient::CreateSSL() {

	DestroySSL();

	operationLock.Lock();

	ssl = SSL_new(sslCtx);
	SSL_set_fd(ssl, GetSocket());
	SSL_set_connect_state(ssl);

	operationLock.Unlock();
}

void SocketIPv4TCPSSLClient::DestroySSL() {

	if(!ssl)
		return;

	if(IsConnected()) {
		bool isNonBlocking = GetNonBlocking();
		SetNonBlocking(false);

		operationLock.Lock();
		int shutdownSSL = SSL_shutdown(ssl);
		operationLock.Unlock();
		if( shutdownSSL == 0 ){
			operationLock.Lock();
			SSL_shutdown(ssl);
			operationLock.Unlock();
		}

		SetNonBlocking(isNonBlocking);
	}

	SSL_free(ssl);
	ssl = 0;
}

bool SocketIPv4TCPSSLClient::IsReadable(const struct timeval* const timeout) {

	if(!IsReadableSSL(timeout))
		return false;

	size_t dataSize;
	while(1) {
		GetPending(dataSize);
		if(dataSize > 0)
			return true;
		if(!IsReadableSSL(timeout))
			return false;
	}
	return true;
}

bool SocketIPv4TCPSSLClient::IsWritable(const struct timeval* const timeout) {

	int fd;
	fd = SSL_get_wfd(ssl);
	if( fd < 0 ) {
		return false;}

	fd_set writefds;
	FD_ZERO(&writefds);
	FD_SET(fd,&writefds);

	timeval tmpTimeout;
	if(timeout != NULL)
		tmpTimeout = *timeout;

	operationLock.Lock();
	int err = select(fd+1,NULL,&writefds,NULL,(timeout != NULL ? &tmpTimeout : NULL));
	operationLock.Unlock();

	if(err <= 0 || !FD_ISSET(fd,&writefds)) {
		return false; }
	return true;
}

bool SocketIPv4TCPSSLClient::IsReadableSSL(const struct timeval* const timeout) {
	int fd;
	fd = SSL_get_rfd(ssl);
	if( fd < 0 ) {
		return false;}

	fd_set readfds;
	FD_ZERO(&readfds);
	FD_SET(fd,&readfds);

	timeval tmpTimeout;
	if(timeout != NULL)
		tmpTimeout = *timeout;

	operationLock.Lock();
	int err = select(fd+1,&readfds,NULL,NULL,(timeout != NULL ? &tmpTimeout : NULL));
	operationLock.Unlock();

	if(err <= 0 || !FD_ISSET(fd,&readfds)) {
		return false; }
	return true;
}

void SocketIPv4TCPSSLClient::GetPending(size_t& dataSize) {

	bool isNonBlocking = GetNonBlocking();
	SetNonBlocking(false);

	operationLock.Lock();
	SSL_peek(ssl,NULL,0);
	int pending = SSL_pending(ssl);
	operationLock.Unlock();

	if(pending<=0){
		dataSize = 0; }
	SetNonBlocking(isNonBlocking);
	dataSize = pending;
}

}
