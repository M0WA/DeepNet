/*
 * HtmlSAX2Document.h
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <vector>
#include <string>

#include <HttpUrl.h>
#include "HtmlSAX2Element.h"

namespace htmlparser {

class HtmlSAX2Document {
public:
	HtmlSAX2Document();
	virtual ~HtmlSAX2Document();

public:
	inline void Reset() { elements.clear(); }

public:
	const std::vector<network::HttpUrl>& HyperLinks() const { return this->hyperlinks; }
	void HyperLinks(std::vector<network::HttpUrl>& hyperlinks) const { hyperlinks = this->hyperlinks; }

	const std::vector<network::HttpUrl>& Images() const { return this->images; }
	void Images(std::vector<network::HttpUrl>& images) const { images = this->images; }

	const std::vector< std::pair<std::string,std::string> >& Content() const { return this->content; }
	void Content(std::vector< std::pair<std::string,std::string> >& content) const { content = this->content; }

	const std::vector< std::pair<std::string,std::string> >& Meta() const { return this->meta; }
	void Meta(std::vector< std::pair<std::string,std::string> >& meta) const { meta = this->meta; }

	const std::vector<std::string>& Warnings() const { return this->warnings; }
	void Warnings(std::vector<std::string>& warnings) const { warnings = this->warnings; }

	const std::vector<std::string>& Errors() const { return this->errors; }
	void Errors(std::vector<std::string>& errors) const { errors = this->errors; }

	const std::vector<std::string>& FatalErrors() const { return this->fatals; }
	void FatalErrors(std::vector<std::string>& fatals) const { fatals = this->fatals; }

	std::vector<HtmlSAX2Element> elements;

	std::vector<network::HttpUrl> hyperlinks;
	std::vector<network::HttpUrl> images;
	std::vector< std::pair<std::string,std::string> > content;
	std::vector< std::pair<std::string,std::string> > meta;

	std::vector<std::string> warnings;
	std::vector<std::string> errors;
	std::vector<std::string> fatals;
};

}
