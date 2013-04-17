/*
 * SocketIPv4TCPSSLClient.h
 *
 *  Created on: Feb 14, 2013
 *      Author: Moritz Wagner
 */

#pragma once

#include <sys/time.h>
#include <openssl/ssl.h>

#include "SocketIPv4TCPClient.h"

namespace network {

class SocketIPv4TCPSSLClient: public network::SocketIPv4TCPClient {

public:
	SocketIPv4TCPSSLClient();
	SocketIPv4TCPSSLClient(int sock);
	virtual ~SocketIPv4TCPSSLClient();

public:
	virtual bool Connect(const struct sockaddr_in& target, const struct timeval* const timeout);
	virtual void SetNonBlocking(bool isNonBlocking);
	virtual bool GetNonBlocking();

protected:
	virtual bool OnCreate(const bool success);
	virtual void OnClose();

protected:
	virtual void GetPending(size_t& pendingBytes);
	virtual bool IsReadable(const struct timeval* const timeout);
	virtual bool IsWritable(const struct timeval* const timeout);
	virtual ssize_t RecvWrapper(void *buf, size_t n, int flags);
	virtual ssize_t SendWrapper(const void *buf, size_t n, int flags);

private:
	void CreateSSLContext();
	void DestroySSLContext();

	void CreateSSL();
	void DestroySSL();

	bool IsReadableSSL(const struct timeval* const timeout);

private:
	const SSL_METHOD* sslMethod;
	SSL_CTX* sslCtx;
	SSL* ssl;
};

}
