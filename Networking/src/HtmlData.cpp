/**
 * @file HtmlData.cpp
 * @author Moritz Wagner
 * @date 23.11.2012
 */

#include "HtmlData.h"

#include <cstring>
#include <cstdlib>

#include <Logging.h>
#include <CharsetEncoder.h>
#include <MimeType.h>

namespace network {

const char HtmlData::emptyBuffer = 0;

const char* HtmlData::GetBuffer() const {
	return ((GetCount()>0) ? GetConstElements() : &emptyBuffer);
}

size_t HtmlData::GetBufferSize() const {

	return ((GetCount()>0) ? GetCount() : 1);
}

bool HtmlData::ConvertToHostCharset() {

	if(GetCount() == 0) {
		return false;}

	//parse content-type as mime string
	std::string mimeType,mimeEncoding;
	bool isHtml = false;
	if(!contentType.empty() && tools::MimeType::ParseMimeString(contentType,mimeType,mimeEncoding))	{
		isHtml =  mimeType.compare("text/html") == 0;
		bool validType = isHtml || mimeType.compare("text/plain") == 0;
		if(!validType) {
			if (log::Logging::IsLogLevelTrace())
				log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "not an html document");
			Release();
			return false;
		}

		int confidence;
		std::string encodingHint = mimeEncoding;
		bool hintCorrect;
		if(!DetectCharset(encodingHint, confidence, mimeEncoding, hintCorrect) ||
		   !tools::CharsetEncoder::IsValidEncodingName(mimeEncoding) ) {
			if (log::Logging::IsLogLevelTrace())
				log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "error while detecting charset for html");
			Release();
			return false;
		}
	}

	char zero = 0;
	std::string out;
	if( !tools::CharsetEncoder::Convert(GetBuffer(), GetBufferSize(), mimeEncoding, out) ) {

		if (log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "error while converting to host charset");
		Release();
		return false;
	}

	Release();
	Append(out.c_str(),out.length());
	Append(&zero,1);

	if(isHtml) {
		//EncodeHtml();
	}

	return !out.empty();
}

/*
bool HtmlData::EncodeHtml() {

	if(GetCount() == 0) {
		return false;}

	char zero = 0;
	std::string out;
	if(!tools::CharsetEncoder::EncodeHtmlEntities(reinterpret_cast<const unsigned char*>(GetBuffer()), GetBufferSize(), out)) {
		log::Logging::Log(log::Logging::GetLogLevel(),"invalid html source:\n %s",out.c_str());
		Release();
		return false; }

	if(!out.empty()) {
		Release();
		Append(out.c_str(),out.length());
		Append(&zero,1);
		return true;
	}
	else {
		Release();
		return false; }
}
*/

bool HtmlData::DetectCharset(const std::string& charsetHint, int& confidence, std::string& detectedEncoding, bool& hintCorrect) {

	tools::CharsetEncoder::DetectMatch result(charsetHint);
	bool success = tools::CharsetEncoder::Detect(GetBuffer(), GetBufferSize(), result);

	hintCorrect = result.encodingHintCorrect;
	confidence  = result.encodingConfidence;
	detectedEncoding = result.encodingName;

	if (!success && log::Logging::IsLogLevelTrace()) {
		log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "error while detecting charset encoding");}
	return success;
}

const std::string& HtmlData::GetContentType() const {
	return contentType;
}

void HtmlData::SetContentType(const std::string& contentType) {
	this->contentType = contentType;
}

}
