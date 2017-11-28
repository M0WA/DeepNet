/*
 * @file SyncServerRequest.h
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <FastCGIRequest.h>

namespace syncserver {

/**
 * @brief handles a single request from a client for the SyncServer service
 * @details
 * example "auth" request
 *
 *     <xml>
 *       <request>
 *   	    <crawlerid>1</crawlerid>
 *   	    <mode>auth</mode>
 *   	    <pass>password</pass>
 *       </request>
 *     </xml>
 *
 * example "get_url_ids" request
 *
 * secondleveldomain section is optional and contains secondlevel domain id
 *
 *     <xml>
 *       <request>
 *   	    <mode>get_url_ids</mode>
 *   	    <crawlerid>1</crawlerid>
 *   	    <token>mytoken</token>
 *   	    <secondleveldomain>3572</secondleveldomain>
 *   	    <count>2</count>
 *       </request>
 *     </xml>
 *
 * example "release_crawler_id" request
 *
 *     <xml>
 *       <request>
 *   	    <mode>release_crawler_id</mode>
 *   	    <crawlerid>1</crawlerid>
 *   	    <token>mytoken</token>
 *       </request>
 *     </xml>
 */
class SyncServerRequest: public fastcgiserver::FastCGIRequest {
public:
	typedef enum _SyncReqMode {
		SYNC_REQ_MODE_MIN = -1,

		SYNC_REQ_MODE_AUTH,
		SYNC_REQ_MODE_GET_URLS,
		SYNC_REQ_MODE_RELEASE,

		SYNC_REQ_MODE_MAX
	} SyncReqMode;

	/*
	typedef struct _SyncAuthReq {
		long long crawlerId;
		std::string password;
	} SyncAuthReq;

	typedef struct _SyncGetUrlsReq {
		long long crawlerId;
		std::string token;
		long long count;
	} SyncGetUrlsReq;

	typedef struct _SyncReleaseReq {
		long long crawlerId;
		std::string token;
		long long count;
	} SyncReleaseReq;
*/

public:
	SyncServerRequest(fastcgiserver::FastCGIServerThread* serverThread);
	virtual ~SyncServerRequest();

public:
	const SyncReqMode& GetMode() const { return mode; }
	long long GetCrawlerID() const { return crawlerID; }
	bool IsAuthenticated() const { return authenticated; }
	std::string GetToken() const { return auth_token; }
	std::string GetUrlCount() const { return urlCount; }

public:
	virtual void OnHandle(FCGX_Request& request);

private:
	bool Authenticate();
	bool CheckToken();
	bool SetCrawlerID();
	bool GetUrls();
	bool ReleaseCrawlerId();

private:
	SyncReqMode mode;
	long long crawlerID;
	long long urlCount;
	bool authenticated;
	std::string auth_token;
};

}
