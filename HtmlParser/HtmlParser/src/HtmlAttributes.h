/*
 * HtmlAttributes.h
 *
 *  Created on: 12.01.2012
 *      Author: Moritz Wagner
 */

#pragma once

namespace htmlparser {

//supported http tags
enum html_attribute_type {
	id_attribute,
	name_attribute,
	style_attribute,
	type_attribute,
} html_attribute_type_;

struct html_attribute_symbols_ : symbols<char,unsigned int>
{
	html_attribute_symbols_()
	{
		add
			("id", id_attribute)
			("name", name_attribute)
			("style", style_attribute)
			("type", type_attribute)
		;
	}
} html_attribute_symbols;

struct html_attribute
{
	html_attribute_type attribute_type;
	std::string content;
} html_attribute_;

}
