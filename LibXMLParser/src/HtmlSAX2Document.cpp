/*
 * HtmlSAX2Document.cpp
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#include "HtmlSAX2Document.h"

#include <sstream>

#include <ContainerTools.h>
#include <CharsetEncoder.h>

namespace libxmlparser {

HtmlSAX2Document::HtmlSAX2Document(const htmlparser::DatabaseUrl& url)
: result(url){
}

HtmlSAX2Document::~HtmlSAX2Document() {
}

void HtmlSAX2Document::Reset() {
	elements.clear();
	result.hyperlinks.clear();
	result.images.clear();
	result.content.clear();
	result.meta.clear();
	result.warnings.clear();
	result.errors.clear();
	result.fatals.clear();
	result.wellformed = 0;
}

}
