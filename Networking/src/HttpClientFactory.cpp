/**
 *
 * @file HttpClientFactory.cpp
 * @author Moritz Wagner
 * @date May 31, 2013
 *
 * TODO: description for this file
 *
 */

#include "HttpClientFactory.h"

#include "IHttpClient.h"
#include "HttpClientCURL.h"

namespace network {

bool HttpClientFactory::CreateInstance( const HTTP_CLIENT_TYPE& type, tools::Pointer<IHttpClient>& client ) {

	switch(type)
	{
	case CURL:
		client.Set(new network::HttpClientCURL(),true);
		break;

	case OWN_IMPLEMENTATION:
		return false;

	default:
		return false;
	}

	return true;
}

}
