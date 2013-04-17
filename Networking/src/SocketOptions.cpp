/*
 * SocketOptions.cpp
 *
 *  Created on: Feb 7, 2013
 *      Author: Moritz Wagner
 */

#include "SocketOptions.h"

namespace network {

SocketOptions::SocketOptions(int domain, int type, int protocol)
: domain(domain)
, type(type)
, protocol(protocol)
, uploadLimit(0)
, downloadLimit(0) {

}

SocketOptions::~SocketOptions() {
}

}
