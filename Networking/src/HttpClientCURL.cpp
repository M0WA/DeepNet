/**
 *
 * @file HttpClientCURL.cpp
 * @author Moritz Wagner
 * @date May 15, 2013
 *
 */

#include "HttpClientCURL.h"
#include "HttpUrl.h"
#include "HttpResponse.h"

#include <Logging.h>

#include <curl/curl.h>

namespace network {

HttpClientCURL::HttpClientCURL()
: curlPtr(curl_easy_init())
, errorBuffer(new char[CURL_ERROR_SIZE])
{
	curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, &(HttpClientCURL::WriterCallback));
	curl_easy_setopt(curlPtr, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curlPtr, CURLOPT_AUTOREFERER, 1);
	curl_easy_setopt(curlPtr, CURLOPT_MAXREDIRS, 12);
	curl_easy_setopt(curlPtr, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_setopt(curlPtr, CURLOPT_NOPROGRESS, 1);
	curl_easy_setopt(curlPtr, CURLOPT_NOSIGNAL, 1);
}

HttpClientCURL::~HttpClientCURL()
{
	if(curlPtr) {
		curl_easy_cleanup(curlPtr);
		curlPtr = 0; }
}

bool HttpClientCURL::Get(const HttpUrl& url, HttpResponse& response)
{
	CURLWriterParam param(url,response);

	curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, &param);
	curl_easy_setopt(curlPtr, CURLOPT_URL, url.GetFullUrl().c_str());
	curl_easy_setopt(curlPtr, CURLOPT_USERAGENT, Settings().userAgent.c_str() );
	curl_easy_setopt(curlPtr, CURLOPT_TIMEOUT, Settings().secondsTimeoutConnection);
	curl_easy_setopt(curlPtr, CURLOPT_CONNECTTIMEOUT, Settings().secondsTimeoutConnect);
	curl_easy_setopt(curlPtr, CURLOPT_IPRESOLVE, (Settings().allowIPv6 ? CURL_IPRESOLVE_WHATEVER : CURL_IPRESOLVE_V4) );

	//TODO: take care about ssl
	curl_easy_setopt(curlPtr, CURLOPT_USE_SSL, CURLUSESSL_NONE);
	//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);

	if(Settings().uploadLimitKB){
		curl_off_t bytesUploadLimit = Settings().uploadLimitKB * 1024;
		curl_easy_setopt(curlPtr, CURLOPT_MAX_SEND_SPEED_LARGE, bytesUploadLimit);}
	if(Settings().downloadLimitKB){
		curl_off_t bytesDownloadLimit = Settings().downloadLimitKB * 1024;
		curl_easy_setopt(curlPtr, CURLOPT_MAX_RECV_SPEED_LARGE, bytesDownloadLimit);}

	CURLcode res = curl_easy_perform(curlPtr);
	if(res != CURLE_OK) {
		response.html.Release();//not needed but nice;)
		if (log::Logging::IsLogLevelTrace())
			log::Logging::LogTrace("libcurl error while fetching url " + url.GetFullUrl() + ": " + errorBuffer);
		return false;
	}

	char* redirUrl = 0;
	if( curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &response.httpResponseCode) != CURLE_OK ) response.httpResponseCode=-1;
	if( curl_easy_getinfo(curlPtr, CURLINFO_FILETIME, &response.fileTimestamp)         != CURLE_OK ) response.fileTimestamp=0;
	if( curl_easy_getinfo(curlPtr, CURLINFO_REDIRECT_URL, &redirUrl) == CURLE_OK  && redirUrl != 0 ) response.redirectUrls.push_back(redirUrl);
	if( curl_easy_getinfo(curlPtr, CURLINFO_SPEED_DOWNLOAD, &response.downloadSpeed )  != CURLE_OK ) response.downloadSpeed=0.0;
	if( curl_easy_getinfo(curlPtr, CURLINFO_SPEED_UPLOAD, &response.uploadSpeed )      != CURLE_OK ) response.uploadSpeed=0.0;
	if( curl_easy_getinfo(curlPtr, CURLINFO_TOTAL_TIME, &response.totalTime )          != CURLE_OK ) response.totalTime=0.0;
	response.primaryPort=80; //if( curl_easy_getinfo(curlPtr, CURLINFO_PRIMARY_PORT, &out.primaryPort )      != CURLE_OK ) out.primaryPort=80;
	if( curl_easy_getinfo(curlPtr, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &response.contentLength ) != CURLE_OK ) response.contentLength=response.html.GetCount();

	char* primaryIP = 0;
	curl_easy_getinfo(curlPtr, CURLINFO_PRIMARY_IP, &primaryIP );
	if(primaryIP)
		response.primaryIP = primaryIP;

	char* contentType = 0;
	curl_easy_getinfo(curlPtr, CURLINFO_CONTENT_TYPE, &contentType );
	if(contentType) {
		response.html.SetContentType(contentType);
		bool conversionSuccess = response.html.ConvertToHostCharset();

		/*
		if(log::Logging::IsLogLevelTrace()) {
			log::Logging::LogTraceUnlimited(
				"converted raw html from "+ url.GetFullUrl() +" \n" + response.html.GetBuffer()); }
		*/

		return conversionSuccess;
	}
	else {
		response.html.Release();//not needed but nice;)
		if(log::Logging::IsLogLevelTrace()) {
			log::Logging::LogTrace("could not detect content type for url: " + url.GetFullUrl()); }
		return false;
	}
}

int HttpClientCURL::WriterCallback(char *data, size_t size, size_t nmemb, CURLWriterParam* instance)
{
	size_t totalSize = size * nmemb;
	if(size<=0 || nmemb<=0 || data == 0)
		return totalSize;
	instance->response.html.Append(data, totalSize);
	return totalSize;
}

}
