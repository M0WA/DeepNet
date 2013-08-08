/**
 * @file UrlFetcherThread.cpp
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#include "UrlFetcherThread.h"

#include "UrlFetcherThreadParam.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <CacheDatabaseUrl.h>
#include <CacheHtml.h>
#include <CacheParsed.h>
#include <CacheRobotsTxt.h>
#include <TLD.h>

#include <TableColumn.h>
#include <TableColumnDefinition.h>
#include <TableDefinition.h>
#include <WhereConditionTableColumn.h>
#include <WhereConditionTableColumnCreateParam.h>

#include <HashTools.h>
#include <TimeTools.h>
#include <Pointer.h>
#include <Logging.h>
#include <PerformanceCounter.h>
#include <HtmlData.h>

#include <HttpResponse.h>
#include <HttpClientSettings.h>
#include <IHttpClient.h>
#include <HttpClientFactory.h>

using namespace database;

namespace crawler
{

UrlFetcherThread::UrlFetcherThread()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&(UrlFetcherThread::UrlFetcherThreadFunction)))
, crawlerSessionID(-1)
, oldCrawlerSessionID(-1)
{
}

UrlFetcherThread::~UrlFetcherThread()
{
}

void* UrlFetcherThread::UrlFetcherThreadFunction(THREAD_PARAM* threadParam)
{
	log::Logging::RegisterThreadID("UrlFetcherThread");

	UrlFetcherThread* instance(dynamic_cast<UrlFetcherThread*>(threadParam->instance));
	instance->fetcherThreadParam = reinterpret_cast<UrlFetcherThreadParam*>(threadParam->pParam);

	if(instance->fetcherThreadParam->minAge < 10) {
		log::Logging::LogWarn("setting crawler_minAge to 10 days for crawling");
		instance->fetcherThreadParam->minAge = 10; }

	PERFORMANCE_LOG_START;
	bool connectedDB(instance->DB().CreateConnection(instance->fetcherThreadParam->databaseConfig)!= 0);
	PERFORMANCE_LOG_STOP("crawler: connect to database");

	if(	connectedDB )
	{
		instance->crawlerSessionID = -1;
		if(instance->GetNextCrawlerSessionID() && instance->crawlerSessionID != -1){
			while( !instance->ShallEnd() ) {

				PERFORMANCE_LOG_RESTART;

				std::map<long long,htmlparser::DatabaseUrl> urls;
				if(	instance->FetchUrls(urls) && !urls.empty())
				{
					std::vector<UrlFetchParam> fetchParameters;
					instance->FetchHtmlCode(urls,fetchParameters);
					instance->CommitPages(fetchParameters);
				}

				PERFORMANCE_LOG_STOP("crawler run");
			}
		}

		instance->OnExit();

		//remove all reservations
		instance->RemoveCrawlerReservation();
		instance->RemoveCrawlerSessionID();

		PERFORMANCE_LOG_RESTART;
		instance->DB().DestroyConnection();
		PERFORMANCE_LOG_STOP("disconnect to databases");
	}
	else {
		log::Logging::LogError("could not start crawler. check database configuration."); }

	return 0;
}

bool UrlFetcherThread::FetchUrls(std::map<long long,htmlparser::DatabaseUrl>& urls)
{
	bool bSuccess(true);
	std::vector<long long> urlIDs;
	if(bSuccess && !ReserveNextUrls(urlIDs))
		bSuccess = false;

	if (bSuccess && !GetUrlsFromDatabase(urlIDs, urls))
		bSuccess = false;

	return bSuccess;
}

bool UrlFetcherThread::FetchHtmlCode(const std::map<long long,htmlparser::DatabaseUrl>& urls, std::vector<UrlFetchParam>& fetchParameters)
{
	std::map<long long,htmlparser::DatabaseUrl>::const_iterator iterUrls(urls.begin());
	for(; iterUrls != urls.end(); ++iterUrls){

		UrlFetchParam fetchParameter(iterUrls->second);
		fetchParameter.urlID = iterUrls->first;

		if( fetcherThreadParam->respectRobotsTxt &&
			!caching::CacheRobotsTxt::IsUrlAllowed(DB().Connection(), iterUrls->second, fetcherThreadParam->userAgent)) {
			continue; }

		if( !GetHtmlCodeFromUrl(fetchParameter.urlID, fetchParameter.url, fetchParameter.html, fetchParameter.responseCode, fetchParameter.urlStageID) ) {
			continue; }

		fetchParameters.push_back(fetchParameter);
	}

	return true;
}

bool UrlFetcherThread::CommitPages(const std::vector<UrlFetchParam>& fetchParameters)
{
	std::vector<UrlFetchParam>::const_iterator iterParam(fetchParameters.begin());
	for(;iterParam != fetchParameters.end();++iterParam) {

		switch(iterParam->responseCode)
		{
		case 200:
			caching::CacheHtml::Add(iterParam->urlID, iterParam->url, iterParam->html, iterParam->urlStageID);
			break;

		case 404:
		case 403:
		case 500:
		default:
			if(log::Logging::IsLogLevelTrace())	{
				log::Logging::LogTrace("download of %s failed with http response code: %d", iterParam->url.GetFullUrl().c_str(), iterParam->responseCode ); }
			break;
		}
	}
	return true;
}

bool UrlFetcherThread::GetNextCrawlerSessionID()
{
	database::crawlersessionsTableBase crawlerSession;

	crawlerSessionID = oldCrawlerSessionID = -1;
	PERFORMANCE_LOG_START;
	crawlerSession.Insert(DB().Connection());
	if(!DB().Connection()->LastInsertID(crawlerSessionID)){
		log::Logging::LogError("could not request crawler_session_id, this is bad...");
		crawlerSessionID = -1;
		return false; }
	PERFORMANCE_LOG_STOP("requesting session id");
	oldCrawlerSessionID = crawlerSessionID;
	return true;
}

bool UrlFetcherThread::GetUrlsFromDatabase(const std::vector<long long>& urlIDs, std::map<long long,htmlparser::DatabaseUrl>& urls)
{
	PERFORMANCE_LOG_START;
	caching::CacheDatabaseUrl::GetByUrlID(DB().Connection(),urlIDs,urls);
	PERFORMANCE_LOG_STOP("getting urls from cache for crawler");
	return true;
}

void UrlFetcherThread::RemoveCrawlerReservation()
{
	if(crawlerSessionID == -1) {
		return;	}

	database::TableBaseUpdateParam remParam;
	remParam.limit = -1;

	database::syncurlsTableBase::GetWhereColumnsFor_CRAWLERSESSION_ID(
	    database::WhereConditionTableColumnCreateParam(database::WhereCondition::Equals(),  database::WhereCondition::InitialComp()),
	    crawlerSessionID,
	    remParam.whereCols );

	database::syncurlsTableBase syncUrl;
	syncUrl.Set_CRAWLERSESSION_ID(0);
	syncUrl.Set_schedule(tools::TimeTools::NowUTC());

	PERFORMANCE_LOG_START;
	syncUrl.Update(DB().Connection(),remParam);
	PERFORMANCE_LOG_STOP("removing crawler reservations");
}

void UrlFetcherThread::RemoveCrawlerSessionID()
{
	if(crawlerSessionID == -1) {
		return;	}

	std::vector<database::WhereConditionTableColumn*> where;
	database::crawlersessionsTableBase::GetWhereColumnsFor_ID(
		database::WhereConditionTableColumnCreateParam(
			database::WhereCondition::Equals(),
			database::WhereCondition::InitialComp()	),
		crawlerSessionID,
		where
	);

	database::DeleteStatement deleteSession(database::crawlersessionsTableBase::CreateTableDefinition());
	deleteSession.Where().AddColumns(where);

	PERFORMANCE_LOG_START;
	DB().Connection()->Delete(deleteSession);
	PERFORMANCE_LOG_STOP("removing crawler session");

	crawlerSessionID = 0;
}

void UrlFetcherThread::OnIdle()
{
	for(int i(0); i < fetcherThreadParam->waitOnIdle && !ShallEnd(); i++){
		sleep(1);}
}

bool UrlFetcherThread::GetHtmlCodeFromUrl(const long long urlID, const htmlparser::DatabaseUrl& url, network::HtmlData& htmlCode, long& httpCode, long long& urlStageID)
{
	PERFORMANCE_LOG_START;
	if(log::Logging::IsLogLevelTrace())
		log::Logging::LogTrace("downloading url: " + url.GetFullUrl());

	tools::Pointer<network::IHttpClient> client;
	network::HttpClientFactory::CreateInstance(fetcherThreadParam->clientType,client);

	network::HttpClientSettings& settings(client.Get()->Settings());
	settings.userAgent = fetcherThreadParam->userAgent;
	settings.secondsTimeoutConnect = fetcherThreadParam->connectTimeout;
	settings.secondsTimeoutConnection = fetcherThreadParam->connectionTimeout;
	settings.allowIPv6 = fetcherThreadParam->useIPv6;
	settings.downloadLimitKB = settings.uploadLimitKB = fetcherThreadParam->speedLimitKB;
	settings.maxSize = fetcherThreadParam->maxDownloadSize;

	network::HttpResponse result;
	PERFORMANCE_LOG_RESTART;
	bool success(client.Get()->Get(url,result));
	PERFORMANCE_LOG_STOP("downloaded " + url.GetFullUrl());

	httpCode = result.httpResponseCode;
	if(!success) {
		htmlCode.Release();
		if (log::Logging::IsLogLevelTrace())
			log::Logging::LogTrace("could not connect to/fetch %s ", url.GetFullUrl().c_str());
	}
	else {
		htmlCode.Swap(result.html);
	}

	database::urlstagesTableBase urlStageTbl;
	urlStageTbl.Set_URL_ID(urlID);
	urlStageTbl.Set_response_code(httpCode);
	urlStageTbl.Set_redirect_count(result.redirectUrls.size());
	urlStageTbl.Set_download_time( (result.totalTime > 0.0 ? static_cast<long long>(result.totalTime * 1000.0) : -1) );
	urlStageTbl.Set_download_speed( (result.downloadSpeed > 0.0 ? static_cast<long long>(result.downloadSpeed * 1024) : -1) );
	urlStageTbl.Set_upload_speed( (result.uploadSpeed > 0.0 ? static_cast<long long>(result.uploadSpeed * 1024) : -1) );
	urlStageTbl.Set_content_length((result.contentLength > 0.0 ? static_cast<long long>(result.contentLength) : -1));
	urlStageTbl.Set_content_type(result.html.GetContentType());
	urlStageTbl.Set_last_change(result.fileTimestamp);
	urlStageTbl.Set_primary_ip(inet_addr(result.primaryIP.c_str()));
	urlStageTbl.Set_primary_port(result.primaryPort);
	urlStageTbl.Set_found_date(tools::TimeTools::NowUTC());

	if(htmlCode.GetBuffer()) {
		urlStageTbl.Set_content_md5(tools::HashTools::GetMD5(htmlCode.GetBuffer(),htmlCode.GetBufferSize())); }
	else {
		urlStageTbl.Set_content_md5(""); }

	/*
#ifdef _USE_HTTPCLIENT_EX

	network::HttpClientEx client;

	network::HttpClientSettings& settings = client.GetSettings();
	settings.SetCompression(true);
	settings.SetUserAgent(fetcherThreadParam->userAgent);
	settings.SetConnectTimeout(tools::TimeTools::MilliSecondsToTimeval(fetcherThreadParam->connectTimeout*1000));
	settings.SetReadTimeout(tools::TimeTools::MilliSecondsToTimeval(fetcherThreadParam->connectionTimeout*1000));
	settings.SetKeepAlive(false);
	settings.SetUploadLimit(fetcherThreadParam->speedLimitKB);
	settings.SetDownloadLimit(fetcherThreadParam->speedLimitKB);

	PERFORMANCE_LOG_RESTART;
	network::HttpRequestResult result;
	client.Get(url,result);
	PERFORMANCE_LOG_STOP("downloading html code");

	if(!result.success){
		httpCode = result.httpStatusCode;
		htmlCode.Release();
		if (log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"could not connect to/fetch %s ", url.GetFullUrl().c_str());
		return false;
	}
	else {
		httpCode = result.httpStatusCode;
		htmlCode.Swap(result.htmlData);
	}

	struct tm lastchange;
	tools::TimeTools::InitTm(lastchange);
	if(!tools::TimeTools::IsZero(result.lastModified)){
		time_t lastModTime = mktime(&result.lastModified);
		localtime_r( &lastModTime, &lastchange);
	}

	database::urlstagesTableBase urlStageTbl;
	urlStageTbl.Set_URL_ID(urlID);
	urlStageTbl.Set_response_code(httpCode);

	if(htmlCode.GetBuffer()) { urlStageTbl.Set_content_md5(tools::HashTools::GetMD5(htmlCode.GetBuffer())); }
	else                     { urlStageTbl.Set_content_md5(""); }

	//TODO: do something with result.effectiveUrl when there was some redirection
	urlStageTbl.Set_redirect_count(result.redirectedCount);

	size_t readMilliSeconds = tools::TimeTools::IsZero(result.readTime) ? 0 : tools::TimeTools::TimevalToMilliSeconds(result.readTime);
	urlStageTbl.Set_download_time(readMilliSeconds);
	urlStageTbl.Set_download_speed( (readMilliSeconds > 0) ? (htmlCode.GetBufferSize()/readMilliSeconds) : 0 );

	size_t writeMilliSeconds = tools::TimeTools::IsZero(result.writeTime) ? 0 : tools::TimeTools::TimevalToMilliSeconds(result.writeTime);
	urlStageTbl.Set_upload_speed( (writeMilliSeconds > 0) ? (result.writtenBytes/writeMilliSeconds) : 0 );

	urlStageTbl.Set_content_length(htmlCode.GetBufferSize());
	urlStageTbl.Set_content_type(htmlCode.GetContentType());
	urlStageTbl.Set_last_change(lastchange);
	urlStageTbl.Set_primary_ip(result.effectiveHost.sin_addr.s_addr);
	urlStageTbl.Set_primary_port(ntohs(result.effectiveHost.sin_port));
	urlStageTbl.Set_found_date(tools::TimeTools::NowUTC());

	bool success = result.success;

#else

	network::HttpConnection::HttpConnectionParam inParam;
	inParam.url       = url.GetFullUrl();
	inParam.userAgent = fetcherThreadParam->userAgent;
	inParam.secondsTimeoutConnect    = fetcherThreadParam->connectTimeout;
	inParam.secondsTimeoutConnection = fetcherThreadParam->connectionTimeout;
	inParam.allowIPv6       = fetcherThreadParam->useIPv6;
	inParam.uploadLimitKB   = fetcherThreadParam->speedLimitKB;
	inParam.downloadLimitKB = fetcherThreadParam->speedLimitKB;

	network::HttpConnection::HttpConnectionResult connectionResult;
	network::HttpConnection server;
	bool fetchSuccess = server.FetchUrl(inParam,connectionResult);
	PERFORMANCE_LOG_STOP("downloading html code");
	if(!fetchSuccess) {
		httpCode = -1;
		htmlCode = connectionResult.htmlCode;
		std::string errorString;
		server.GetLastErrorString(errorString);
		if (log::Logging::IsLogLevelTrace()) log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"could not connect to/fetch " + url.GetFullUrl() + ": " + errorString);
		return false;
	}
	else {
		httpCode = connectionResult.httpResponseCode;
		htmlCode = connectionResult.htmlCode;
	}

	struct tm lastchange;
	localtime_r( &connectionResult.fileTimestamp, &lastchange);

	database::urlstagesTableBase urlStageTbl;
	urlStageTbl.Set_URL_ID(urlID);
	urlStageTbl.Set_response_code(httpCode);
	if(htmlCode.GetBuffer()) { urlStageTbl.Set_content_md5(tools::HashTools::GetMD5(htmlCode.GetBuffer())); }
	else                     { urlStageTbl.Set_content_md5(""); }
	urlStageTbl.Set_redirect_count(connectionResult.redirectCount);
	urlStageTbl.Set_download_time( (connectionResult.totalTime > 0.0 ? static_cast<long long>(connectionResult.totalTime * 1000.0) : -1) );
	urlStageTbl.Set_download_speed( (connectionResult.downloadSpeed > 0.0 ? static_cast<long long>(connectionResult.downloadSpeed * 1024) : -1) );
	urlStageTbl.Set_upload_speed( (connectionResult.uploadSpeed > 0.0 ? static_cast<long long>(connectionResult.uploadSpeed * 1024) : -1) );
	urlStageTbl.Set_content_length((connectionResult.contentLength > 0.0 ? static_cast<long long>(connectionResult.contentLength) : -1));
	urlStageTbl.Set_content_type(connectionResult.contentType);
	urlStageTbl.Set_last_change(lastchange);

	urlStageTbl.Set_primary_ip(inet_addr(connectionResult.primaryIP.c_str()));
	urlStageTbl.Set_primary_port(connectionResult.primaryPort);

	urlStageTbl.Set_found_date(tools::TimeTools::NowUTC());

	bool success = true;

#endif
	*/

	const char* pszBuffer(htmlCode.GetBuffer());

	PERFORMANCE_LOG_RESTART;
	urlStageTbl.Insert(DB().Connection());
	PERFORMANCE_LOG_STOP("inserting url stage data");

	urlStageID = -1;
	DB().Connection()->LastInsertID(urlStageID);

	database::latesturlstagesTableBase lastUrlStage;
	lastUrlStage.Set_URL_ID(urlID);
	lastUrlStage.Set_URLSTAGE_ID(urlStageID);

	PERFORMANCE_LOG_RESTART;
	lastUrlStage.InsertOrUpdate(DB().Connection());
	PERFORMANCE_LOG_STOP("inserting into latest url stage table");

	database::documentcodeTableBase documentCodeTbl;
	documentCodeTbl.Set_URLSTAGE_ID(urlStageID);
	documentCodeTbl.Set_code(pszBuffer);

	PERFORMANCE_LOG_RESTART;
	documentCodeTbl.Insert(DB().Connection());
	PERFORMANCE_LOG_STOP("inserting html code into database");

	return success;
}

long long UrlFetcherThread::GetOldCrawlerSessionID() const {
	return oldCrawlerSessionID;
}

}
