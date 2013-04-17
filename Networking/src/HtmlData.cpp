/*
 * HtmlData.cpp
 *
 *  Created on: 23.11.2012
 *      Author: Moritz Wagner
 */

#include "HtmlData.h"

#include <cstring>
#include <cstdlib>

#include <Logging.h>
#include <CharsetEncoder.h>

namespace network {

const char HtmlData::emptyBuffer = 0;

const char* HtmlData::GetBuffer() const {
	return ((GetCount()>0) ? GetConstElements() : &emptyBuffer);
}

size_t HtmlData::GetBufferSize() const {

	return ((GetCount()>0) ? GetCount() : 1);
}

bool HtmlData::ConvertToHostCharset(const std::string& inEnc) {

	if(GetCount() == 0) {
		return false;}

	char zero = 0;
	std::string out;
	if( !tools::CharsetEncoder::Convert(GetBuffer(), GetBufferSize(), inEnc, out) ) {

		if (log::Logging::IsLogLevelTrace())
			log::Logging::Log(log::Logging::LOGLEVEL_TRACE, "error while converting to host charset");
		Release();
		return false;
	}

	//tools::CharsetEncoder::Convert(...) returns true and empty string
	//when no conversion needed...
	if(!out.empty()) {
		Release();
		Append(out.c_str(),out.length());
		Append(&zero,1);
		out.clear();
		return true;
	}
	else {
		Release();
		return false;
	}
}
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
