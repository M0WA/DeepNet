/*
 * @file SyncServerRequest.h
 * @date Nov 27, 2017
 * @author Moritz Wagner
 */

#pragma once

#include <FastCGIRequest.h>
#include <ThreadManager.h>

namespace syncserver {

/**
 * @brief handles a single request from a client for the SyncServer service
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

public:
	SyncServerRequest(fastcgiserver::FastCGIServerThread* serverThread, const std::string& crawler_sync_pass);
	virtual ~SyncServerRequest();

public:
	/**
	 * gets mode of request
	 * @return mode of request
	 */
	const SyncReqMode& GetMode() const { return mode; }

	/**
	 * gets crawler id
	 * @return crawler id
	 */
	long long GetCrawlerID() const { return crawlerID; }

	/**
	 * checks if client is authenticated
	 * @return true if yes, false if no
	 */
	bool IsAuthenticated() const { return authenticated; }

	/**
	 * get this clients token
	 * @return this clients token
	 */
	std::string GetToken() const { return auth_token; }

	/**
	 * get thread manager
	 * @return thread manager
	 */
	threading::ThreadManager<threading::Thread>& GetThreadManager() { return manager; }

	/**
	 * get thread id
	 * @return thread id
	 */
	const threading::Thread::ThreadID& GetThreadID() const { return threadID; }

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
	bool authenticated;
	std::string auth_token;
    std::string crawler_sync_pass;
	threading::ThreadManager<threading::Thread> manager;
	threading::Thread::ThreadID threadID;
};

}
