/*
 * SocketIPv4TCPServer.h
 *
 *  Created on: Dec 9, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "SocketIPv4TCP.h"
#include "SocketIPv4TCPClient.h"

#include <sys/socket.h>

#include <Thread.h>

struct sockaddr_in;

namespace network {

class SocketIPv4TCPServer : public SocketIPv4TCP {
public:
	struct AcceptEventParam {
		AcceptEventParam(SocketIPv4TCPClient* newClient, void* userParam)
		: newClient(newClient)
		, userParam(userParam)
		{ }

		SocketIPv4TCPClient* newClient;
		void* userParam;
	};

	typedef void (*OnAcceptCallback)(const AcceptEventParam& e);

public:
	class ServerAcceptThread : public threading::Thread {
	public:
		ServerAcceptThread(SocketIPv4TCPServer* server, OnAcceptCallback callback, void* userParam)
		: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&AcceptFunc),false)
		, server(server)
		, callback(callback)
		, userParam(userParam)
		{ StartThread(); }

	private:
		static void* AcceptFunc(threading::Thread::THREAD_PARAM* param);

	private:
		SocketIPv4TCPServer* server;
		OnAcceptCallback callback;
		void* userParam;
	};

public:
	SocketIPv4TCPServer();
	virtual ~SocketIPv4TCPServer();

public:
	virtual void Close();
	virtual bool Bind(int port, const socklen_t& backlog);
	virtual bool Bind(const struct sockaddr_in& listenIf, const socklen_t& backlog);
	virtual bool AcceptAsync(OnAcceptCallback callback, void* userParam);
	virtual void EndAcceptAsync();

private:
	ServerAcceptThread* acceptThread;
};

}
