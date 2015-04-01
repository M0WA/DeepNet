/**
 *
 * @file HttpClientFactory.cpp
 * @author Moritz Wagner
 * @date 31.05.2013
 *
 */

#include "HttpClientFactory.h"

#include "IHttpClient.h"
#include "HttpClientCURL.h"

namespace network {

bool HttpClientFactory::CreateInstance( const HttpClientType& type, tools::Pointer<IHttpClient>& client ) {

	switch(type)
	{
	case CURL:
		client.Set(new network::HttpClientCURL(),true);
		return true;

	case OWN:
		return false;

	default:
		return false;
	}
}

}
