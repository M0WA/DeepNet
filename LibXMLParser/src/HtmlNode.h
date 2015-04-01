/*
 * HtmlNode.h
 *
 *  Created on: 12.01.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include "HtmlTags.h"
#include "HtmlAttributes.h"

namespace libxmlparser {

struct html_node
{
    //html_tag_type tag_type;
	std::string tag_type;
    std::vector<html_child_node> children;
    //std::vector<html_attribute> attributes;
};

}
