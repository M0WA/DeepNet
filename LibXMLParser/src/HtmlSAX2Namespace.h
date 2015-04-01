/*
 * HtmlSAX2Namespace.h
 *
 *  Created on: 02.02.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace libxmlparser {

class HtmlSAX2Namespace
{
public:
	HtmlSAX2Namespace();
	virtual ~HtmlSAX2Namespace();

public:
	std::string prefix;
	std::string URI;
};

}
