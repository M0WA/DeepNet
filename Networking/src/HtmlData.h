/*
 * HtmlData.h
 *
 *  Created on: 23.11.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

#include <MemoryContainer.h>

namespace network {

class HtmlData : public tools::MemoryContainer<char>
{
public:
	HtmlData() : tools::MemoryContainer<char>() { }
	virtual ~HtmlData() { }

	bool ConvertToHostCharset();
	bool EncodeHtml();

	const char* GetBuffer() const;
	size_t GetBufferSize() const;

	void SetContentType(const std::string& contentType);
	const std::string& GetContentType() const;

private:
	bool DetectCharset(const std::string& charsetHint, int& confidence, std::string& detectedEncoding, bool& hintCorrect);

private:
	std::string contentType;
	static const char emptyBuffer;
};

}

