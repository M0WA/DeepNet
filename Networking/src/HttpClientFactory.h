/**
 *
 * @file HttpClientFactory.h
 * @author Moritz Wagner
 * @date May 31, 2013
 *
 */

#pragma once

#include <Pointer.h>

namespace network
{

class IHttpClient;

/**
 * @brief factory class for http clients
 */
class HttpClientFactory
{
private:
	HttpClientFactory() {}

public:
	/**
	 * @enum HttpClientType
	 * type of http client
	 */
	typedef enum {
		/**
		 * use curl based http client
		 */
		CURL,

		/**
		 * use own implementation of a http client
		 */
		OWN,
	} HttpClientType;

public:
	/**
	 * creates an instance of a http client of the specified type
	 * @param type type of http client
	 * @param client create client instance
	 * @return true if successful, false if unsuccesful
	 */
	static bool CreateInstance( const HttpClientType& type, tools::Pointer<IHttpClient>& client );
};

}
