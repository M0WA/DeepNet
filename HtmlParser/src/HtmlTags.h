/*
 * html_tags.h
 *
 *  Created on: 12.01.2012
 *      Author: Moritz Wagner
 */

#pragma once

namespace htmlparser {

//supported http tags
enum html_tag_type {
	anchor_tag,
	body_tag,
	div_tag,
	head_tag,
	html_tag,
	image_tag,
	meta_tag,
	script_tag,
	title_tag,
	paragraph_tag,
} html_tag_type_;

struct html_tag_symbols_ : symbols<char,unsigned int>
{
	html_tag_symbols_()
	{
		add
			("a",anchor_tag)
			("body",body_tag)
			("div",div_tag)
			("head",head_tag)
			("html",html_tag)
			("img",image_tag)
			("meta",meta_tag)
			("script",script_tag)
			("title",title_tag)
			("p",paragraph_tag)
		;
	}
} html_tag_symbols;

}
