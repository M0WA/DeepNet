/*
 * SocketOptions.h
 *
 *  Created on: Feb 7, 2013
 *      Author: Moritz Wagner
 */

#pragma once

#include <cstddef>

namespace network {

class SocketOptions {
public:
	SocketOptions(int domain, int type, int protocol);
	virtual ~SocketOptions();

public:
	int domain;
	int type;
	int protocol;

public:
	size_t uploadLimit;   //bytes per second
	size_t downloadLimit; //bytes per second
};

}
