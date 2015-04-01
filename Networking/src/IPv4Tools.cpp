/**
 * @file IPv4Tools.cpp
 * @author Moritz Wagner
 * @date 10.12.2012
 */

#include "IPv4Tools.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <cstdlib>

#include <StringTools.h>

namespace network {

IPv4Tools::IPv4Tools() {
}

IPv4Tools::~IPv4Tools() {
}

std::string IPv4Tools::ToString(const struct sockaddr_in& addr) {

	return IPv4Tools::ToString(addr.sin_addr) + ":" + tools::StringTools::TransformString(ntohs(addr.sin_port));
}

std::string IPv4Tools::ToString(const struct in_addr& ip) {

	char* pszIP = inet_ntoa(ip);
	if(pszIP) {

		std::string retString = pszIP;
		free(pszIP);
		return retString;
	}

	return "";
}

bool IPv4Tools::ResolveHost(const std::string& hostname, struct in_addr& addr) {

	struct addrinfo* addrs = NULL;
	if(getaddrinfo(hostname.c_str(), NULL, NULL, &addrs) != 0) {

		if(addrs)
			freeaddrinfo(addrs);
		return false;
	}

	bool success = false;
	struct addrinfo* rp = NULL;
	for (rp = addrs; rp != NULL; rp = rp->ai_next) {

		if( rp->ai_family == AF_INET ) {

			addr = reinterpret_cast<struct sockaddr_in*>(rp->ai_addr)->sin_addr;
			success = true;
			break;
		}
	}

	if(addrs)
		freeaddrinfo(addrs);

	return success;
}

}
