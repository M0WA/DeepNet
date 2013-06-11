/**
 * @file HtmlData.h
 * @author Moritz Wagner
 * @date 23.11.2012
 */

#pragma once

#include <string>

#include <MemoryContainer.h>

namespace network {

/**
 * @brief container for HTML data which uses tools::MemoryContainer
 */
class HtmlData : public tools::MemoryContainer<char>
{
public:
	HtmlData() : tools::MemoryContainer<char>() { }
	virtual ~HtmlData() { }

	/**
	 * converts complete content to charset/encoding of the current host
	 * @return true if successful, false if unsuccessful
	 */
	bool ConvertToHostCharset();

	/**
	 * gets current buffer
	 * @return current buffer
	 */
	const char* GetBuffer() const;

	/**
	 * gets current buffer size
	 * @return current buffer
	 */
	size_t GetBufferSize() const;

	/**
	 * sets the content type for this HTML data
	 * @param contentType Content-Type, may include charset, i.e. text/html;charset=UTF8
	 */
	void SetContentType(const std::string& contentType);

	/**
	 * gets content type of this HTML data
	 * @return Content-Type, may include charset, i.e. text/html;charset=UTF8
	 */
	const std::string& GetContentType() const;

private:
	bool DetectCharset(const std::string& charsetHint, int& confidence, std::string& detectedEncoding, bool& hintCorrect);

	/**
	 * encode all characters that have a HTML Character Reference
	 * @return true if successful, false if unsuccessful
	 */
	//bool EncodeHtml();

private:
	std::string contentType;
	static const char emptyBuffer;
};

}

