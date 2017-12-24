/**
 *
 * @file HttpClientCURL.cpp
 * @author Moritz Wagner
 * @date 15.05.2013
 *
 */

#include "HttpClientCURL.h"
#include "HttpUrl.h"
#include "HttpResponse.h"

#include <Logging.h>
#include <TimeTools.h>
#include <StringTools.h>

#include <curl/curl.h>

namespace network {

static void DumpCurlRequest(const char *text, std::ostringstream& ss, unsigned char *ptr, size_t size, char nohex)
{
  size_t i;
  size_t c;

  unsigned int width = 0x10;

  if(nohex)
    /* without the hex output, we can fit more on screen */
    width = 0x40;

  std::string tmp;
  tools::StringTools::FormatString(tmp,"%s, %10.10ld bytes (0x%8.8lx)\n",text, (long)size, (long)size);
  ss << tmp; tmp = "";

  for(i = 0; i<size; i += width) {

	tools::StringTools::FormatString(tmp,"%4.4lx: ", (long)i);
	ss << tmp; tmp = "";

    if(!nohex) {
      /* hex not disabled, show it */
      for(c = 0; c < width; c++)
        if(i + c < size) {
        	tools::StringTools::FormatString(tmp,"%02x ", ptr[i + c]);
        	ss << tmp; tmp = "";
        }
        else {
          ss << "   ";
        }
    }

    for(c = 0; (c < width) && (i + c < size); c++) {
      /* check for 0D0A; if found, skip past and start a new line of output */
      if(nohex && (i + c + 1 < size) && ptr[i + c] == 0x0D &&
         ptr[i + c + 1] == 0x0A) {
        i += (c + 2 - width);
        break;
      }
      tools::StringTools::FormatString(tmp,"%c",(ptr[i + c] >= 0x20) && (ptr[i + c]<0x80)?ptr[i + c]:'.');
      ss << tmp; tmp = "";

      /* check again for 0D0A, to avoid an extra \n if it's at width */
      if(nohex && (i + c + 2 < size) && ptr[i + c + 1] == 0x0D &&
         ptr[i + c + 2] == 0x0A) {
        i += (c + 3 - width);
        break;
      }
    }
    ss << "\n";
  }
}

static int TraceCurlRequest(CURL *handle, curl_infotype type, char *data, size_t size, void *userp) {

	const char *text;
	(void) handle; /* prevent compiler warning */
	(void) userp;

	switch (type) {
	case CURLINFO_TEXT:
		fprintf(stderr, "== Info: %s", data);
	default: /* in case a new one is introduced to shock us */
		return 0;

	case CURLINFO_HEADER_OUT:
		text = "=> Send header";
		break;
	case CURLINFO_DATA_OUT:
		text = "=> Send data";
		break;
	case CURLINFO_SSL_DATA_OUT:
		text = "=> Send SSL data";
		break;
	case CURLINFO_HEADER_IN:
		text = "<= Recv header";
		break;
	case CURLINFO_DATA_IN:
		text = "<= Recv data";
		break;
	case CURLINFO_SSL_DATA_IN:
		text = "<= Recv SSL data";
		break;
	}

	std::ostringstream ss;
	DumpCurlRequest(text, ss, (unsigned char *) data, size, 1);

	log::Logging::LogTraceUnlimited("curl debug:\n%s",ss.str().c_str());
	return 0;
}

HttpClientCURL::HttpClientCURL()
: curlPtr(curl_easy_init())
, errorBuffer(new char[CURL_ERROR_SIZE])
{
	curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, &(HttpClientCURL::WriterCallback));
	curl_easy_setopt(curlPtr, CURLOPT_ERRORBUFFER, errorBuffer);

	//TODO: configurable?
	curl_easy_setopt(curlPtr, CURLOPT_FOLLOWLOCATION, 1);
	curl_easy_setopt(curlPtr, CURLOPT_AUTOREFERER, 1);
	curl_easy_setopt(curlPtr, CURLOPT_MAXREDIRS, 12);
	curl_easy_setopt(curlPtr, CURLOPT_NOPROGRESS, 1);
	curl_easy_setopt(curlPtr, CURLOPT_NOSIGNAL, 1);
	curl_easy_setopt(curlPtr, CURLOPT_FORBID_REUSE, 1);
	curl_easy_setopt(curlPtr, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

	//TODO: how to deal with invalid ssl certificates?
	curl_easy_setopt(curlPtr, CURLOPT_SSL_VERIFYPEER, 0);
}

HttpClientCURL::~HttpClientCURL()
{
	if(curlPtr) {
		curl_easy_cleanup(curlPtr);
		curlPtr = 0; }

	delete [] errorBuffer;
}

bool HttpClientCURL::Get(const HttpUrl& url, HttpResponse& response)
{
	return DoRequest(url, response);
}

int HttpClientCURL::WriterCallback(char *data, size_t size, size_t nmemb, CURLWriterParam* instance)
{
	if(!size || !nmemb)
		return 0;

	size_t totalSize(size * nmemb);
	if(instance->maxSize) {
		if((instance->response.html.GetBufferSize() + totalSize) > instance->maxSize) {
			instance->response.html.Release();
			instance->omitRest = true;
		}
	}
	if(totalSize && !data){
		//
		//TODO: throw exception
		//
		return totalSize;
	}

	if(!instance->omitRest){
		instance->response.html.Append(data, totalSize); }
	return totalSize;
}

bool HttpClientCURL::Post(const HttpUrl& url, const std::string& content, const std::string& contentType, HttpResponse& response)
{
	curl_easy_setopt(curlPtr, CURLOPT_POSTFIELDS, content.c_str());

	struct curl_slist *list(NULL);
	if(!contentType.empty()) {
		std::string type = "Content-Type: " + contentType;
		list = curl_slist_append(list, type.c_str());
	}

	std::ostringstream contentLength;
	contentLength << "Content-Length: " << content.length();
	list = curl_slist_append(list, contentLength.str().c_str());
	curl_easy_setopt(curlPtr, CURLOPT_HTTPHEADER, list);

	bool success(DoRequest(url, response));

	if(list) {
		curl_slist_free_all(list); }

	return success;
}

bool HttpClientCURL::DoRequest(const HttpUrl& url, HttpResponse& response) {

	CURLWriterParam param(url,response, Settings().maxSize);

	if(log::Logging::IsLogLevelTrace()) {
		//enable trace/debug logging for libcurl
		curl_easy_setopt(curlPtr, CURLOPT_DEBUGFUNCTION, TraceCurlRequest);
		curl_easy_setopt(curlPtr, CURLOPT_VERBOSE, 1L);	}

	curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, &param);
	curl_easy_setopt(curlPtr, CURLOPT_URL, url.GetFullUrl().c_str());
	curl_easy_setopt(curlPtr, CURLOPT_USERAGENT, Settings().userAgent.c_str() );
	curl_easy_setopt(curlPtr, CURLOPT_TIMEOUT, Settings().secondsTimeoutConnection);
	curl_easy_setopt(curlPtr, CURLOPT_CONNECTTIMEOUT, Settings().secondsTimeoutConnect);
	curl_easy_setopt(curlPtr, CURLOPT_IPRESOLVE, (Settings().allowIPv6 ? CURL_IPRESOLVE_WHATEVER : CURL_IPRESOLVE_V4) );

	//TODO: take care about ssl
	curl_easy_setopt(curlPtr, CURLOPT_SSL_VERIFYPEER, 0L);
	curl_easy_setopt(curlPtr, CURLOPT_SSL_VERIFYHOST, 0L);

	if(Settings().uploadLimitKB){
		curl_off_t bytesUploadLimit = Settings().uploadLimitKB * 1024;
		curl_easy_setopt(curlPtr, CURLOPT_MAX_SEND_SPEED_LARGE, bytesUploadLimit);}
	if(Settings().downloadLimitKB){
		curl_off_t bytesDownloadLimit = Settings().downloadLimitKB * 1024;
		curl_easy_setopt(curlPtr, CURLOPT_MAX_RECV_SPEED_LARGE, bytesDownloadLimit);}

	CURLcode res(curl_easy_perform(curlPtr));
	if(res != CURLE_OK) {
		response.html.Release();//not needed but nice;)
		if (log::Logging::IsLogLevelTrace())
			log::Logging::LogTrace("libcurl error while fetching url %s: %s",url.GetFullUrl().c_str(), errorBuffer);
		return false;
	}

	char* redirUrl(0);
	if( curl_easy_getinfo(curlPtr, CURLINFO_RESPONSE_CODE, &response.httpResponseCode) != CURLE_OK ) response.httpResponseCode=-1;
	if( curl_easy_getinfo(curlPtr, CURLINFO_REDIRECT_URL, &redirUrl) == CURLE_OK  && redirUrl != 0 ) response.redirectUrls.push_back(redirUrl);
	if( curl_easy_getinfo(curlPtr, CURLINFO_SPEED_DOWNLOAD, &response.downloadSpeed )  != CURLE_OK ) response.downloadSpeed=0.0;
	if( curl_easy_getinfo(curlPtr, CURLINFO_SPEED_UPLOAD, &response.uploadSpeed )      != CURLE_OK ) response.uploadSpeed=0.0;
	if( curl_easy_getinfo(curlPtr, CURLINFO_TOTAL_TIME, &response.totalTime )          != CURLE_OK ) response.totalTime=0.0;
	response.primaryPort=80; //if( curl_easy_getinfo(curlPtr, CURLINFO_PRIMARY_PORT, &out.primaryPort )      != CURLE_OK ) out.primaryPort=80;
	if( curl_easy_getinfo(curlPtr, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &response.contentLength ) != CURLE_OK ) response.contentLength=response.html.GetCount();

	long tmpFileTime(-1);
	if( curl_easy_getinfo(curlPtr, CURLINFO_FILETIME, &tmpFileTime) == CURLE_OK  && tmpFileTime > 0)
		response.fileTimestamp=tools::TimeTools::TimeToTm(tmpFileTime);

	char* primaryIP = 0;
	curl_easy_getinfo(curlPtr, CURLINFO_PRIMARY_IP, &primaryIP );
	if(primaryIP)
		response.primaryIP = primaryIP;

	char* contentType = 0;
	curl_easy_getinfo(curlPtr, CURLINFO_CONTENT_TYPE, &contentType );
	if(contentType) {
		response.html.SetContentType(contentType);
		bool conversionSuccess(response.html.ConvertToHostCharset());

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

}
