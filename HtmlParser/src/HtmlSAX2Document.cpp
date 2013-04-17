/*
 * HtmlSAX2Document.cpp
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#include "HtmlSAX2Document.h"

namespace htmlparser {

HtmlSAX2Document::HtmlSAX2Document(const htmlparser::DatabaseUrl& url)
: url(url)
{
}

HtmlSAX2Document::~HtmlSAX2Document()
{
}

}
