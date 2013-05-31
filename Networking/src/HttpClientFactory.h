/**
 *
 * @file HttpClientFactory.h
 * @author Moritz Wagner
 * @date May 31, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <Pointer.h>

namespace network
{

class IHttpClient;
class HttpClientFactory
{
private:
	HttpClientFactory() {}

public:
	typedef enum {
		CURL,
		OWN_IMPLEMENTATION,
	} HTTP_CLIENT_TYPE;

	static bool CreateInstance( const HTTP_CLIENT_TYPE& type, tools::Pointer<IHttpClient>& client );
};

}
