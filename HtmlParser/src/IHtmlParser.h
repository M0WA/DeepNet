#pragma once

#include <vector>
#include <Pointer.h>
#include <HttpUrl.h>
#include <DatabaseUrl.h>

namespace network {
	class HtmlData;
}

namespace htmlparser {

/**
 * @brief interface class for html parser results
 * @see htmlparser::IHtmlParser
 */
class IHtmlParserResult {

protected:
	IHtmlParserResult(const DatabaseUrl& url) : url(url) {}

public:
	virtual ~IHtmlParserResult() {}

public:
	void HyperLinks(std::vector<network::HttpUrl>& hyperlinks) const { hyperlinks = this->hyperlinks; }
	void Images(std::vector<network::HttpUrl>& images) const { images = this->images; }
	void Content(std::vector< std::pair<std::string,std::string> >& content) const { content = this->content; }
	void Meta(std::vector< std::pair<std::string,std::string> >& meta) const { meta = this->meta; }
	void Warnings(std::vector<std::string>& warnings) const { warnings = this->warnings; }
	void Errors(std::vector<std::string>& errors) const { errors = this->errors; }
	void FatalErrors(std::vector<std::string>& fatals) const { fatals = this->fatals; }

public:
	std::vector<network::HttpUrl> hyperlinks;
	std::vector<network::HttpUrl> images;
	std::vector< std::pair<std::string,std::string> > content;
	std::vector< std::pair<std::string,std::string> > meta;

	std::vector<std::string> warnings;
	std::vector<std::string> errors;
	std::vector<std::string> fatals;

	const DatabaseUrl& url;
	int wellformed;

public:
	virtual void DumpXML(std::string& xmlContent);
};

/**
 * @brief interface class for all supported html parsers.
 * use this class for parsing html, use factory class only to instanciate.
 * @see htmlparser::HtmlParserFactory
 */
class IHtmlParser {

	friend class HtmlParserFactory;

public:
	typedef enum {
		LIBXML = 0,
		DOM,
		MAX_HTML_PARSER_TYPE,
	} HTML_PARSER_TYPE;

protected:
	IHtmlParser() {}

public:
	virtual ~IHtmlParser() {}

	/**
	 * parses html and generates content result
	 * @param html html to parse
	 * @param result result containing content and info for html documents
	 * @return true if successful, false if unsuccessful
	 */
	virtual bool Parse(const network::HtmlData& html, tools::Pointer<IHtmlParserResult>& result)=0;
};

}
