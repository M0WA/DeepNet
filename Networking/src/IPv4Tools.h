/**
 * @file IPv4Tools.h
 * @author Moritz Wagner
 * @date 10.12.2012
 */

#pragma once

#include <netinet/in.h>
#include <string>

namespace network {

/**
 * @brief implements IPv4 functionality
 */
class IPv4Tools {
private:
	IPv4Tools();
public:
	virtual ~IPv4Tools();

public:
	/**
	 * converts ip to string.
	 * @param ip ip to converted.
	 * @return ip as string.
	 */
	static std::string ToString(const struct in_addr& ip);

	/**
	 * converts ip endpoint to string.
	 * @param ip endpoint
	 * @return endpoint as string.
	 */
	static std::string ToString(const struct sockaddr_in& ip);

	/**
	 * resolves hostname to ip (dns forward lookup).
	 * @param hostname hostname
	 * @param addr output ip.
	 * @return false on error, true on success.
	 */
	static bool ResolveHost(const std::string& hostname, struct in_addr& addr);
};

}
