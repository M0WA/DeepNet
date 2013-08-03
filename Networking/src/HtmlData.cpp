/**
 * @file HtmlData.cpp
 * @author Moritz Wagner
 * @date 23.11.2012
 */

#include "HtmlData.h"

#include <string>
#include <cstring>
#include <cstdlib>

#include <Logging.h>
#include <CharsetEncoder.h>
#include <MimeType.h>

namespace network {

const char HtmlData::emptyBuffer(0);

const char* HtmlData::GetBuffer() const {
	return ((GetCount()>0) ? GetConstElements() : &emptyBuffer);
}

size_t HtmlData::GetBufferSize() const {

	return ((GetCount()>0) ? GetCount() : 1);
}

bool HtmlData::ConvertToHostCharset() {

	if(GetCount() == 0) {
		log::Logging::LogTrace("empty html/txt document cannot be converted, skipping");
		Release();
		return false;}

	//parse indicated content-type as mime string
	std::string mimeType,mimeEncoding;
	bool isHtml(false);
	if( !contentType.empty() &&
		tools::MimeType::ParseMimeString(contentType,mimeType,mimeEncoding)) {
		isHtml =  mimeType.compare("text/html") == 0;
		bool validType = isHtml || mimeType.compare("text/plain") == 0;
		if(!validType) {
			if (log::Logging::IsLogLevelTrace())
				log::Logging::LogTrace("not a valid content type string from html/txt document");
			Release();
			return false;
		}
	}
	else {
		log::Logging::LogTrace("no content type specified, guessing charset..."); }

	int confidence(0);
	char zero(0);
	std::string encodingHint(mimeEncoding);
	if(!tools::CharsetEncoder::IsValidEncodingName(encodingHint)) {
		encodingHint = ""; }

	bool hintCorrect(false);
	bool detectCorrect(DetectCharset(encodingHint, confidence, mimeEncoding, hintCorrect));
	detectCorrect &= tools::CharsetEncoder::IsValidEncodingName(mimeEncoding);
	if(!detectCorrect) {
		log::Logging::LogTrace("error while detecting charset for html");
		Release();
		return false; }

	log::Logging::LogTrace("detected charset: %s, hint was: %s",mimeEncoding.c_str(),encodingHint.c_str());

	std::string hostCharsetName(tools::CharsetEncoder::GetHostCharsetName());
	if( encodingHint.compare(hostCharsetName) != 0 &&
		!tools::CharsetEncoder::IsCharsetAlias(mimeEncoding.c_str(),hostCharsetName.c_str()) &&
		confidence != 10 //is a compatible charset
	) {
		if(confidence > 10) {
			std::string out;
			if( !tools::CharsetEncoder::Convert(GetBuffer(), GetBufferSize(), mimeEncoding, out) ) {
				log::Logging::LogTrace("error while converting to host charset: %s -> %s",mimeEncoding.c_str(),hostCharsetName.c_str());
				Release();
				return false;
			}

			log::Logging::LogTrace("conversion to host charset successful: %s -> %s",mimeEncoding.c_str(),hostCharsetName.c_str());

			Release();
			Append(out.c_str(),out.length());

			//TODO: set new content-type with host charset
		}
		else {
			log::Logging::LogTrace("error while converting content to host charset: %s (hint: %s, confidence: %d)",mimeEncoding.c_str(),encodingHint.c_str(),confidence);
			Release();
			return false;
		}
	}
	else {
		log::Logging::LogTrace("compatible charset detected, no conversion needed");
	}

	Append(&zero,1);

	if(isHtml) {
		//EncodeHtml();
	}

	return GetBufferSize() > 1;
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
		log::Logging::LogTrace("error while detecting charset encoding");}
	return success;
}

const std::string& HtmlData::GetContentType() const {
	return contentType;
}

void HtmlData::SetContentType(const std::string& contentType) {
	this->contentType = contentType;
}

}
