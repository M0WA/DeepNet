/*
 * HttpClientEx.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: Moritz Wagner
 */

#include "HttpClientEx.h"

#include <cstring>
#include <stdint.h>
#include <netinet/in.h>

#include <Logging.h>
#include <StringTools.h>
#include <MimeType.h>
#include <CompressionTools.h>
#include <CharsetEncoder.h>
#include <PerformanceCounter.h>
#include <TimeTools.h>

#include <NotImplementedException.h>

#include "IPv4Tools.h"
#include "HttpUrl.h"
#include "HttpHeader.h"
#include "HttpUrlParser.h"
#include "HttpGetRequest.h"
#include "HttpPostRequest.h"

#include "SocketIPv4TCPClient.h"
#include "SocketIPv4TCPSSLClient.h"

namespace network {

HttpClientEx::HttpClientEx()
: pClient(0){
	memset(&host,0,sizeof(host));
}

HttpClientEx::~HttpClientEx() {

	Disconnect();
	if(pClient)
		delete pClient;
	pClient = 0;
}

bool HttpClientEx::Connect(const HttpUrl& url) {

	Disconnect();

	short connectPort = 80;
	tools::StringTools::TransformString(url.GetPort(),connectPort);
	if(url.GetScheme().compare("http") == 0) {
		pClient = new SocketIPv4TCPClient();
	}
	else if (url.GetScheme().compare("https") == 0) {
		pClient = new SocketIPv4TCPSSLClient();
	}
	else {
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"invalid scheme in url: %s",url.GetFullUrl().c_str());
		return false;}

	pClient->GetSocketOptions().uploadLimit = clientSettings.GetUploadLimit();
	pClient->GetSocketOptions().downloadLimit = clientSettings.GetDownloadLimit();
	pClient->Create();

	hostname = url.GetFullDomain();
	if(!network::IPv4Tools::ResolveHost(hostname,host.sin_addr)) {
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"could not resolve host: %s",hostname.c_str());
		memset(&host,0,sizeof(host));
		return false; }
	host.sin_family = AF_INET;
	host.sin_port = htons(connectPort);
	this->hostname = hostname;

	return pClient->Connect(host,&GetSettings().GetConnectTimeout());
}

void HttpClientEx::Disconnect() {

	if(pClient) {
		pClient->Close();
		delete pClient;
		pClient = 0;
	}

	memset(&host,0,sizeof(host));
	hostname.clear();
}

void HttpClientEx::Get(const HttpUrl& url, HttpRequestResult& result) {

	result.htmlData.Release();
	tools::PerformanceCounter measure;

	//connect to http-server
	measure.Start();
	result.success = Connect(url);
	measure.Stop(result.connectTime);
	if(!result.success) {
		Disconnect();
		return;
	}

	HttpGetRequest request(url);
	InitRequestFromSettings(request);

	//sending request to server
	result.success = SendRequest(request,result);
	if(!result.success) {
		Disconnect();
		return;
	}

	tools::MemoryContainer<char> containerHeader;
	size_t headerEnd = 0;

	//reading response from server
	timeval readTimeTmp;
	measure.Start();
	result.success = ReadHeader(&GetSettings().GetReadTimeout(), containerHeader, headerEnd, result.htmlData);
	measure.Stop(readTimeTmp);
	if ( !result.success ) {
		Disconnect();
		return;
	}

	//processing http-header from response
	HttpHeader header;
	result.success = header.Init(containerHeader, headerEnd);
	if ( !result.success ) {
		Disconnect();
		return;
	}
	containerHeader.Release();

	//reading the rest of the request's content
	measure.Start();
	result.success = ReadContent(header, request, &GetSettings().GetReadTimeout(), result);
	measure.Stop(result.readTime);
	tools::TimeTools::TimevalAddition(result.readTime,readTimeTmp,result.readTime);
	if ( !result.success ) {
		Disconnect();
		return;
	}

	//process redirection, connection keep-alive, etc...
	result.success = ProcessAfterRequest(header, request, result);
	if ( !result.success ) {
		Disconnect();
		return;
	}
}

void HttpClientEx::Post(const HttpUrl& url, HttpRequestResult& result) {

	THROW_EXCEPTION(errors::NotImplementedException,"HTTP method POST not implemented");

	//TODO: implement post request
}

bool HttpClientEx::ReadHeader(const struct timeval* const timeout, tools::MemoryContainer<char>& container, size_t& headerEnd, HtmlData& containerContent) {
	headerEnd = 0;
	size_t curPos = 0;
	while(headerEnd == 0) {

		size_t dataSize = 0;
		if(!pClient->IsReadable(timeout)){
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"could not receive http header,socket not readable");
			return false; }

		pClient->GetPending(dataSize);
		if(dataSize == 0) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"could not receive http header, no data available");
			return false; }

		ssize_t readBytes = pClient->Read(container,curPos, dataSize, &GetSettings().GetReadTimeout());
		if( readBytes == 0) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while reading http header, no data read");
			return false;
		}
		curPos += readBytes;
		headerEnd = HttpHeader::FindEndOfHeader(container.GetConstElementAt(0), container.GetCount());
	}

	if(headerEnd < curPos) {
		containerContent.Append(0,container, headerEnd, curPos - headerEnd); }

	if(log::Logging::IsLogLevelTrace()) {
		container.GetElements()[headerEnd-1]=0;
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"received complete http header:\n%s",container.GetConstElements());
	}

	return true;
}

bool HttpClientEx::ReadContent(const HttpHeader& header, const HttpRequest& request, const struct timeval* const timeout, HttpRequestResult& result) {

	// transfer encoding
	if(!ProcessTransferEncoding(header, result.htmlData)) {
		return false; }

	// content encoding
	if(!ProcessContentEncoding(header, result.htmlData)) {
		return false; }

	//content type
	if(!ProcessContentType(header, result.htmlData)) {
		return false; }

	return true;
}

bool HttpClientEx::ProcessTransferEncoding(const HttpHeader& header, HtmlData& container) {

	std::string transferEncoding = "", contentLength = "";
	if(header.GetProperty("transfer-encoding",transferEncoding)) {
		tools::StringTools::ToLowerIP(transferEncoding);

		if(transferEncoding.compare("chunked") == 0) {

			return LoadChunkedContent(container);
		}
		else {
			if(log::Logging::IsLogLevelTrace())
				log::Logging::LogTrace("invalid transfer-encoding specified: " + transferEncoding);
			return false;
		}
	}
	else if(header.GetProperty("content-length",contentLength)) {
		return LoadContentLength(container, contentLength);
	}
	else {
		if(log::Logging::IsLogLevelTrace())
			log::Logging::LogTrace("neither content-length nor transfer encoding specified");
		return true;
	}
}

bool HttpClientEx::ProcessContentEncoding(const HttpHeader& header, HtmlData& containerContent) {

	// compression
	std::string contentEncoding;
	if( header.GetProperty("content-encoding",contentEncoding) ) {
		tools::StringTools::ToLowerIP(contentEncoding);
		if(contentEncoding.compare("gzip") == 0) {
			char* uncompressedContent = 0;
			size_t uncompressedSize = 0;
			if( !tools::CompressionTools::GUnzip(containerContent.GetBuffer(),containerContent.GetBufferSize(),&uncompressedContent,uncompressedSize)  ) {
				return false; }

			if(uncompressedContent) {
				containerContent.Release();
				containerContent.Append(uncompressedContent,uncompressedSize);
				free(uncompressedContent);
			}
		}
		else if(contentEncoding.compare("deflate") == 0) {

			char* uncompressedContent = 0;
			size_t uncompressedSize = 0;
			if( !tools::CompressionTools::Inflate(containerContent.GetBuffer(),containerContent.GetBufferSize(),&uncompressedContent,uncompressedSize)  ) {
				return false; }

			if(uncompressedContent) {
				containerContent.Release();
				containerContent.Append(uncompressedContent,uncompressedSize);
				free(uncompressedContent);
			}
		}
		else {
			if(log::Logging::IsLogLevelTrace())
				log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"invalid content-encoding specified: %s",contentEncoding.c_str());
			return false;
		}
	}
	return true;
}

bool HttpClientEx::ProcessContentType(const HttpHeader& header, HtmlData& containerContent) {

	if(containerContent.GetCount() == 0)
		return true;

	char zero = 0;
	containerContent.Append(&zero,1);

	std::string mimeType,mimeEncoding,charsetHint;
	std::string contentType = "";
	if( header.GetProperty("content-type",contentType) ) {

		tools::StringTools::ToLowerIP(contentType);
		if(!tools::MimeType::ParseMimeString(contentType,mimeType,mimeEncoding) ) {

			//guess mime type and encoding
			tools::MimeType mime;
			mimeType     = mime.GetMimeType(containerContent.GetBuffer(),containerContent.GetBufferSize());
			mimeEncoding = mime.GetMimeEncoding(containerContent.GetBuffer(),containerContent.GetBufferSize());
		}

		//checking encoding specified in mime type string
		if( mimeEncoding.empty() || !tools::CharsetEncoder::IsValidEncodingName(mimeEncoding) )	{
			//no or invalid encoding found in mime type string
			charsetHint = "";
		} else {
			charsetHint = mimeEncoding;
		}
	}

	// process content charset and mime type
	//TODO: accept more content types
	bool encodeHtml = mimeType.compare("text/html") == 0;
	bool successMimeType = encodeHtml;
	successMimeType |= mimeType.compare("text/plain") == 0;
	if(!successMimeType) {
		return false; }
	containerContent.SetContentType(mimeType);

	//detect charset encoding
	std::string charsetName;
	bool validHint = false;
	int encodingConfidence = -1;
	if(!containerContent.DetectCharset( charsetHint,encodingConfidence,mimeEncoding,validHint)) {
		return false;
	}

	//minimum confidence of 10 is has special meaning
	//for more information:
	//see documentation of ucsdet_getConfidence(const UCharsetMatch *ucsm, UErrorCode *status)
	//http://icu-project.org/apiref/icu4c/ucsdet_8h.html#aa1dd7ce8c727d855697aac1f35df71ed)
	int minConfidence = 10;

	//convert to host charset encoding if a valid encoding was found
	if( validHint || encodingConfidence >= minConfidence  ) {
		if(!containerContent.ConvertToHostCharset(mimeEncoding))
			return false;
		if(encodeHtml && !containerContent.EncodeHtml())
			return false;
		return true;
	}
	// wrong encoding specified or broken encoding in document
	else {
		return false;
	}
}

bool HttpClientEx::LoadChunkSize(HtmlData& chunkedContent, const size_t curChunkedPos, size_t& chunkSize, size_t& endChunkSize) {

	while( (chunkedContent.GetCount() - curChunkedPos) < 2 ||
          (endChunkSize = HttpHeader::FindEndOfLine(
        		chunkedContent.GetConstElementAt(curChunkedPos),
				chunkedContent.GetCount() - curChunkedPos )
          ) == 0
	) {
		size_t read = 1;
		if (pClient->Read(chunkedContent,chunkedContent.GetCount(),read, &GetSettings().GetReadTimeout()) != 1) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while reading chunk");
			return false;
		}
	}

	std::string chunkSizeString;
	chunkSizeString.append(chunkedContent.GetConstElementAt(curChunkedPos),endChunkSize);

	if(!tools::StringTools::TransformHexString(chunkSizeString.c_str(),chunkSize)) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while converting chunk size: %s",chunkSizeString.c_str());
		return false;
	}
	if(chunkSize == 0 && chunkSizeString.compare("0\r\n") != 0) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"received zero chunk size: %s",chunkSizeString.c_str());
		return false;
	}

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"next chunk size: %zu",chunkSize); }

	endChunkSize += curChunkedPos;
	return true;
}

bool HttpClientEx::LoadChunkedContent(HtmlData& contentBuf) {

	HtmlData chunkedContent;
	if(contentBuf.GetCount()) {
		chunkedContent.Append(0,contentBuf);
		contentBuf.Release();
	}

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"loading chunked content"); }

	size_t curChunkedPos = 0;
	while(1) {

		size_t endChunkSize = 0, chunkSize = 0;
		if(!LoadChunkSize(chunkedContent, curChunkedPos, chunkSize, endChunkSize)){
			return false;
		}
		if(chunkSize == 0) {
			//try to read closing \r\n
			pClient->Read(chunkedContent, chunkedContent.GetCount(), 2, &GetSettings().GetReadTimeout());
			break;
		}

		size_t total = endChunkSize + chunkSize;
		if(chunkedContent.GetCount() < total) {

			//chunk has not completely arrived yet
			size_t alreadyLoaded = chunkedContent.GetCount();
			size_t missing       = total - alreadyLoaded;
			size_t missingRead   = pClient->Read(chunkedContent, alreadyLoaded, missing, &GetSettings().GetReadTimeout());
			if( missingRead != missing) {
				log::Logging::Log(log::Logging::LOGLEVEL_INFO,"timeout or error while reading chunk: alreadyLoaded: %zu, missing: %zu, missingRead: %zu",
					alreadyLoaded,
					missing,
					missingRead);
				return false;
			}
		}

		contentBuf.Append(contentBuf.GetCount(),chunkedContent,endChunkSize,chunkSize);

		if(chunkedContent.GetCount() < (total + 2)) {
			size_t missing = (total + 2) - chunkedContent.GetCount();
			size_t readClosing = pClient->Read(chunkedContent, chunkedContent.GetCount(), missing, &GetSettings().GetReadTimeout());
			if( readClosing != missing) {
				log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error while reading \\r\\n for closing chunk");
				return false;
			}
		}

		size_t foundClose = HttpHeader::FindEndOfLine(chunkedContent.GetElementAt(total), 2);
		if(foundClose != 2) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"error no closing \\r\\n in chunk");
			return false;
		}
		curChunkedPos = total + 2;
	}

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"finished loading chunked content"); }

	return contentBuf.GetCount() > 0;
}

bool HttpClientEx::LoadContentLength(HtmlData& contentBuf, const std::string& contentLengthString) {

	size_t contentLength = 0;
	if(!tools::StringTools::TransformString(contentLengthString,contentLength)) {
		if(log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"invalid content-length specified: %s", contentLengthString.c_str());
		return false;
	}

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"loading content by content-length: %zu",contentLength); }

	if(contentBuf.GetCount() < contentLength) {
		size_t bytesToLoad = contentLength - contentBuf.GetCount();
		if(pClient->Read(contentBuf, contentBuf.GetCount(), bytesToLoad, &GetSettings().GetReadTimeout()) != bytesToLoad) {
			if(log::Logging::IsLogLevelTrace())
				log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"could not load complete content");
			return false;
		}
	}

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"finished loading content by content-length"); }

	return true;
}

bool HttpClientEx::ProcessAfterRequest(const HttpHeader& header, const HttpRequest& request, HttpRequestResult& result) {

	std::string keepAliveVal;
	bool isKeepAliveConnection = false;
	if ( GetSettings().GetKeepAlive() &&
		 header.GetProperty("connection",keepAliveVal)
	){
		tools::StringTools::ToLowerIP(keepAliveVal);
		isKeepAliveConnection = ( keepAliveVal.compare("keep-alive") == 0 );
	}
	if(!isKeepAliveConnection) {
		Disconnect();
	}

	std::string lastModifiedString;
	if( !header.GetProperty("last-modified",lastModifiedString) ||
		!tools::TimeTools::TryParseDate(lastModifiedString,result.lastModified)
	){
		if( !header.GetProperty("date",lastModifiedString) ||
			!tools::TimeTools::TryParseDate(lastModifiedString,result.lastModified)
		){
			tools::TimeTools::InitTm(result.lastModified);
		}
	}

	switch(header.GetStatusCode())
	{
	case 200:
		result.httpStatusCode  = header.GetStatusCode();
		result.effectiveHeader = header;
		result.effectiveUrl    = request.url;
		result.effectiveHost   = host;
		return true;

	case 300: //Multiple Choices
	case 301: //Moved Permanently
	case 302: //Found
	case 307: //Temporary Redirect
	{
		size_t newRedirCount = ++result.redirectedCount;
		bool success = HandleRedirect(header, request, result);
		result.redirectedCount = newRedirCount;
		return success;
	}

	case 400:
	case 403:
	case 404:
	case 500:
		// end of well known error codes
	default:
		log::Logging::Log(
			log::Logging::LOGLEVEL_INFO,
			"invalid response code in http response: %d %s\n request:\n%s",
			header.GetStatusCode(),
			header.GetStatusMessage().c_str()
		);
		return false;
	}
}

bool HttpClientEx::SendRequest(const HttpRequest& request, HttpRequestResult& result) {

	std::string requestString;
	request.ToString(requestString);

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"sending http request to %s:\n%s",request.url.GetFullUrl().c_str(),requestString.c_str());
	}

	tools::PerformanceCounter measure;
	measure.Start();
	if(!pClient->Write(requestString.c_str(),requestString.length())) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"could not send http request:\n%s",requestString.c_str());
		return false;
	}
	measure.Stop(result.writeTime);
	result.writtenBytes = requestString.length();
	return true;
}

bool HttpClientEx::HandleRedirect(const HttpHeader& header, const HttpRequest& request, HttpRequestResult& result) {

	if(GetSettings().GetRedirectLimit() == 0)
		return false;

	HttpUrl redirectUrl;
	HttpUrlParser::ParseURL(request.url,header.GetLocation(),redirectUrl);

	if(log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE,"redirecting (%d) to: %s", header.GetStatusCode(), redirectUrl.GetFullUrl().c_str());
	}

	size_t redirectFollowDeepth = GetSettings().GetRedirectLimit() - 1;

	bool isSameDomain = (redirectUrl.GetFullDomain().compare(request.url.GetFullDomain()) == 0);
	isSameDomain &= ( isSameDomain && (redirectUrl.GetScheme().compare(request.url.GetScheme()) == 0) );
	isSameDomain &= ( isSameDomain && (redirectUrl.GetPort().compare(request.url.GetPort()) == 0) );

	HttpClientEx* pClient = this;
	if(!isSameDomain) {
		pClient = new HttpClientEx();
		pClient->SetSettings(GetSettings());
		pClient->GetSettings().SetRedirectLimit(redirectFollowDeepth);
	}
	else {
		GetSettings().SetRedirectLimit(redirectFollowDeepth);
	}

	switch(request.GetType()) {

	case HttpRequest::GET:
		pClient->Get(redirectUrl, result);
		break;

	case HttpRequest::POST:
		pClient->Post(redirectUrl, result);
		break;

	default:
		THROW_EXCEPTION(errors::NotImplementedException,"HTTP method not implemented");
		return false;
	}

	if(!isSameDomain) {
		delete pClient;
	}
	else {
		GetSettings().SetRedirectLimit(redirectFollowDeepth+1);
	}
	return result.success;
}

void HttpClientEx::InitRequestFromSettings(HttpRequest& request) {

	if(GetSettings().GetCompression()) {
		request.AddHeaderEntry("Accept-Encoding", "gzip, deflate"); }
	else {
		request.RemoveHeaderEntry("Accept-Encoding"); }

	if(!GetSettings().GetUserAgent().empty()) {
		request.AddHeaderEntry("User-Agent",GetSettings().GetUserAgent()); }
	else {
		request.RemoveHeaderEntry("User-Agent"); }

	if(GetSettings().GetKeepAlive()) {
		request.AddHeaderEntry("Connection","Keep-Alive"); }
	else {
		request.RemoveHeaderEntry("Connection"); }

}

}
