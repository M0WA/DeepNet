/*
 * UnitTestIPv4TCPServer.h
 *
 *  Created on: Dec 10, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <cstdlib>
#include <cstring>

#include <Thread.h>
#include <MemoryContainer.h>

#include "SocketIPv4TCPServer.h"

static const char* serverResponse = "HTTP/1.1 400 Bad Request\r\n\r\n\r\n";

namespace toolbot {

class UnitTestIPv4TCPServer {
private:
	class UnitTestIPv4TCPServerClientThread : threading::Thread {
	public:
		struct UnitTestIPv4TCPServerClientThreadParam {
			network::SocketIPv4TCPClient* client;
		};

	public:
		UnitTestIPv4TCPServerClientThread()
		: Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&UnitTestIPv4TCPServerClientThreadFunction),false) {
		}

	public:
		static void* UnitTestIPv4TCPServerClientThreadFunction(threading::Thread::THREAD_PARAM* params) {

			UnitTestIPv4TCPServerClientThreadParam* threadParams = reinterpret_cast<UnitTestIPv4TCPServerClientThreadParam*>(params->pParam);

			tools::MemoryContainer<char> buf;
			size_t size = 0;
			size_t curPos = 0;
			struct timeval timeout;
			timeout.tv_sec = 0;
			timeout.tv_usec = 0;
			while( threadParams->client->Read(buf,curPos,size,&timeout) ) {
				curPos += size;
			}
			buf.Release();

			threadParams->client->Write(serverResponse,strlen(serverResponse));

			threadParams->client->Close();
			delete threadParams->client;
			return 0;
		}
	};

private:
	enum TestAsyncState {

		ASYNC_IDLE,
		ASYNC_PENDING,
		ASYNC_ERROR,
		ASYNC_SUCCESS,

	};

public:
	UnitTestIPv4TCPServer();
	virtual ~UnitTestIPv4TCPServer();

public:
	bool Test(const std::string& ip, const int& port);

private:
	static void OnAcceptCallback(const network::SocketIPv4TCPServer::AcceptEventParam& e);

private:
	network::SocketIPv4TCPServer server;
	volatile TestAsyncState state;
};

}
