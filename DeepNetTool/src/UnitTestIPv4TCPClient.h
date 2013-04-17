/*
 * UnitTestIPv4TCPClient.h
 *
 *  Created on: Dec 10, 2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <SocketIPv4TCP.h>
#include <SocketIPv4TCPClient.h>
#include <string>

namespace toolbot {

class UnitTestIPv4TCPClient {
private:
	enum TestAsyncState {

		ASYNC_IDLE,
		ASYNC_PENDING,
		ASYNC_ERROR,
		ASYNC_SUCCESS,

	};

public:
	UnitTestIPv4TCPClient();
	virtual ~UnitTestIPv4TCPClient();

public:
	bool Test(const std::string& ip, const int& port);

private:
	bool TestLinearConnection(const std::string& ip, const int& port);
};

}
