/**
 * @file MimeType.cpp
 * @author Moritz Wagner
 * @date 15.05.2012
 */

#include "MimeType.h"

#include "StringTools.h"
#include "CharsetEncoder.h"

namespace tools {

MimeType::MimeType()
: magicCookie(magic_open(MAGIC_NONE))
{
	if(magicCookie)	{
		if(magic_load(magicCookie,NULL) != 0) {
			magic_close(magicCookie);
			magicCookie = 0;
		}
	}
}

MimeType::~MimeType()
{
	if(magicCookie) {
		magic_close(magicCookie);
		magicCookie = 0;
	}
}

std::string MimeType::GetMimeType(const void* pszBuffer, const size_t len)
{
	magic_setflags(magicCookie,MAGIC_MIME_TYPE);
	const char* pszMimeType = magic_buffer(magicCookie,pszBuffer,len);
	if(pszMimeType)
		return pszMimeType;
	return "";
}

std::string MimeType::GetMimeEncoding(const void* pszBuffer, const size_t len)
{
	magic_setflags(magicCookie,MAGIC_MIME_ENCODING);
	const char* pszMimeEncoding = magic_buffer(magicCookie,pszBuffer,len);
	if(pszMimeEncoding)
		return pszMimeEncoding;
	return "";
}

bool MimeType::ParseMimeString(const std::string& mimeString, std::string& mimeType, std::string& mimeEncoding)
{
	if(mimeString.empty())
		return false;

	std::string mimeStringLC = tools::StringTools::ToLowerNP(mimeString);
	if(!GetCharsetFromMimeString(mimeStringLC, mimeEncoding)) {
		mimeEncoding = ""; }

	size_t posEnd = mimeStringLC.find(";");
	if(posEnd == std::string::npos)
		posEnd = mimeStringLC.size();

	mimeType = mimeStringLC.substr(0,posEnd);
	StringTools::Trim(mimeType);
	return !mimeType.empty();
}

bool MimeType::GetCharsetFromMimeString(const std::string& contentType, std::string& encoding)
{
	size_t startPos = std::string::npos;
	if((startPos = contentType.find("charset=")) != std::string::npos)
	{
		startPos += 8;
		size_t tmpPos  = contentType.find(";",startPos);
		size_t sizeEnd = ( tmpPos != std::string::npos) ? tmpPos : contentType.size();
		int sizePos = sizeEnd - startPos;
		if(sizePos <= 0)
			return false;
		encoding = contentType.substr(startPos,static_cast<size_t>(sizePos));
		StringTools::Trim(encoding);
		StringTools::ReplaceString("\r", "", encoding);
		StringTools::ReplaceString("\n", "", encoding);
		return CharsetEncoder::IsValidEncodingName(encoding);
	}
	else
		return false;
}

}
