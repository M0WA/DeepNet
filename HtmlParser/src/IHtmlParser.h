/**
 * @file IHtmlParser.h
 * @author Moritz Wagner
 * @date 02.06.2013
 */

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
	IHtmlParserResult(const caching::DatabaseUrl& url) : url(url), wellformed() {}

public:
	virtual ~IHtmlParserResult() {}

public:
	/**
	 * gets all hyperlinks from associated document
	 * @param hyperlinks all hyperlinks
	 */
	void HyperLinks(std::vector<network::HttpUrl>& hyperlinks) const { hyperlinks = this->hyperlinks; }

	/**
	 * gets all images from associated document
	 * @param images all images
	 */
	void Images(std::vector<network::HttpUrl>& images) const { images = this->images; }

	/**
	 * gets all content from associated document
	 * @param content all content
	 */
	void Content(std::vector< std::pair<std::string,std::string> >& content) const { content = this->content; }

	/**
	 * gets all meta content from associated document
	 * @param meta all meta content
	 */
	void Meta(std::vector< std::pair<std::string,std::string> >& meta) const { meta = this->meta; }

	/**
	 * gets all warnings from associated document
	 * @param warnings all warnings
	 */
	void Warnings(std::vector<std::string>& warnings) const { warnings = this->warnings; }

	/**
	 * gets all errors from associated document
	 * @param errors all errors
	 */
	void Errors(std::vector<std::string>& errors) const { errors = this->errors; }

	/**
	 * gets all fatal errors from associated document
	 * @param fatals all fatal errors
	 */
	void FatalErrors(std::vector<std::string>& fatals) const { fatals = this->fatals; }

public:
	/**
	 * hyperlinks
	 */
	std::vector<network::HttpUrl> hyperlinks;

	/**
	 * images
	 */
	std::vector<network::HttpUrl> images;

	/**
	 * content
	 */
	std::vector< std::pair<std::string,std::string> > content;

	/**
	 * meta content
	 */
	std::vector< std::pair<std::string,std::string> > meta;

	/**
	 * warnings
	 */
	std::vector<std::string> warnings;

	/**
	 * errors
	 */
	std::vector<std::string> errors;

	/**
	 * fatal errors
	 */
	std::vector<std::string> fatals;

	/**
	 * url associated with document
	 */
	const caching::DatabaseUrl& url;

	/**
	 * bigger than 0 if document is wellformed
	 */
	int wellformed;

public:
	/**
	 * dumps results to an XML string
	 * @param xmlContent content as XML
	 */
	virtual void DumpXML(std::string& xmlContent);
};

/**
 * @brief interface class for all supported html parsers.
 * use this class for parsing html, use factory class only to instantiate.
 * @see htmlparser::HtmlParserFactory
 */
class IHtmlParser {

	friend class HtmlParserFactory;

protected:
	IHtmlParser() {}

public:
	virtual ~IHtmlParser() {}

	/**
	 * parses html and generates content result
	 * @param url url of html
	 * @param html html to parse
	 * @param result result containing content and info for html documents
	 * @return true if successful, false if unsuccessful
	 */
	virtual bool Parse(const caching::DatabaseUrl& url,const network::HtmlData& html, tools::Pointer<IHtmlParserResult>& result)=0;
};

}
