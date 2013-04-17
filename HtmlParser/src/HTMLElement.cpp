/**
 *
 * @file HTMLElement.cpp
 * @author Moritz Wagner
 * @date Mar 5, 2013
 *
 * TODO: description for this file
 *
 */

#include "HTMLElement.h"

#include <map>
#include <string>

#include "HTMLElement.h"

#include <Mutex.h>

namespace htmlparser {

void InitializeTagMaps();
void RegisterTag(HTMLElement::HTMLTag tagType, const char* tag);

static threading::Mutex lockTagMaps;
static std::map<HTMLElement::HTMLTag,std::string> tagTypes;
static std::map<std::string,HTMLElement::HTMLTag> tagNames;

void RegisterTag(HTMLElement::HTMLTag tagType, const char* tag) {
	tagTypes[tagType] = tag;

	std::pair<std::string,HTMLElement::HTMLTag> pair(tag,tagType);
	tagNames.insert(pair);
}

void InitializeTagMaps() {

	threading::AutoMutex lock(lockTagMaps);

	if(tagTypes.size() > 0) {
		return; }

	RegisterTag(HTMLElement::unknownTag,"");

	RegisterTag(HTMLElement::htmlTag,"html");
	RegisterTag(HTMLElement::headTag,"head");
	RegisterTag(HTMLElement::titleTag,"title");
	RegisterTag(HTMLElement::baseTag,"base");
	RegisterTag(HTMLElement::linkTag,"link");
	RegisterTag(HTMLElement::metaTag,"meta");
	RegisterTag(HTMLElement::styleTag,"style");
	RegisterTag(HTMLElement::scriptTag,"script");
	RegisterTag(HTMLElement::noscriptTag,"noscript");
	RegisterTag(HTMLElement::bodyTag,"body");
	RegisterTag(HTMLElement::articleTag,"article");
	RegisterTag(HTMLElement::sectionTag,"section");
	RegisterTag(HTMLElement::navTag,"nav");
	RegisterTag(HTMLElement::asideTag,"aside");
	RegisterTag(HTMLElement::h1Tag,"h1");
	RegisterTag(HTMLElement::h2Tag,"h2");
	RegisterTag(HTMLElement::h3Tag,"h3");
	RegisterTag(HTMLElement::h4Tag,"h4");
	RegisterTag(HTMLElement::h5Tag,"h5");
	RegisterTag(HTMLElement::h6Tag,"h6");
	RegisterTag(HTMLElement::hgroupTag,"hgroup");
	RegisterTag(HTMLElement::headerTag,"header");
	RegisterTag(HTMLElement::footerTag,"footer");
	RegisterTag(HTMLElement::addressTag,"address");
	RegisterTag(HTMLElement::pTag,"p");
	RegisterTag(HTMLElement::hrTag,"hr");
	RegisterTag(HTMLElement::preTag,"pre");
	RegisterTag(HTMLElement::blockquoteTag,"blockquote");
	RegisterTag(HTMLElement::olTag,"ol");
	RegisterTag(HTMLElement::ulTag,"ul");
	RegisterTag(HTMLElement::liTag,"li");
	RegisterTag(HTMLElement::dlTag,"dl");
	RegisterTag(HTMLElement::dtTag,"dt");
	RegisterTag(HTMLElement::ddTag,"dd");
	RegisterTag(HTMLElement::figureTag,"figure");
	RegisterTag(HTMLElement::figcaptionTag,"figcaption");
	RegisterTag(HTMLElement::divTag,"div");
	RegisterTag(HTMLElement::aTag,"a");
	RegisterTag(HTMLElement::emTag,"em");
	RegisterTag(HTMLElement::strongTag,"strong");
	RegisterTag(HTMLElement::smallTag,"small");
	RegisterTag(HTMLElement::sTag,"s");
	RegisterTag(HTMLElement::citeTag,"cite");
	RegisterTag(HTMLElement::qTag,"q");
	RegisterTag(HTMLElement::dfnTag,"dfn");
	RegisterTag(HTMLElement::abbrTag,"abbr");
	RegisterTag(HTMLElement::timeTag,"time");
	RegisterTag(HTMLElement::codeTag,"code");
	RegisterTag(HTMLElement::varTag,"var");
	RegisterTag(HTMLElement::sampTag,"samp");
	RegisterTag(HTMLElement::kbdTag,"kbd");
	RegisterTag(HTMLElement::subTag,"sub");
	RegisterTag(HTMLElement::supTag,"sup");
	RegisterTag(HTMLElement::iTag,"i");
	RegisterTag(HTMLElement::bTag,"b");
	RegisterTag(HTMLElement::uTag,"u");
	RegisterTag(HTMLElement::markTag,"mark");
	RegisterTag(HTMLElement::rubyTag,"ruby");
	RegisterTag(HTMLElement::rtTag,"rt");
	RegisterTag(HTMLElement::rpTag,"rp");
	RegisterTag(HTMLElement::bdiTag,"bdi");
	RegisterTag(HTMLElement::bdoTag,"bdo");
	RegisterTag(HTMLElement::spanTag,"span");
	RegisterTag(HTMLElement::brTag,"br");
	RegisterTag(HTMLElement::wbrTag,"wbr");
	RegisterTag(HTMLElement::insTag,"ins");
	RegisterTag(HTMLElement::delTag,"del");
	RegisterTag(HTMLElement::imgTag,"img");
	RegisterTag(HTMLElement::iframeTag,"iframe");
	RegisterTag(HTMLElement::embedTag,"embed");
	RegisterTag(HTMLElement::objectTag,"object");
	RegisterTag(HTMLElement::paramTag,"param");
	RegisterTag(HTMLElement::videoTag,"video");
	RegisterTag(HTMLElement::audioTag,"audio");
	RegisterTag(HTMLElement::sourceTag,"source");
	RegisterTag(HTMLElement::trackTag,"track");
	RegisterTag(HTMLElement::canvasTag,"canvas");
	RegisterTag(HTMLElement::mapTag,"map");
	RegisterTag(HTMLElement::areaTag,"area");
	RegisterTag(HTMLElement::tableTag,"table");
	RegisterTag(HTMLElement::captionTag,"caption");
	RegisterTag(HTMLElement::colgroupTag,"colgroup");
	RegisterTag(HTMLElement::colTag,"col");
	RegisterTag(HTMLElement::tbodyTag,"tbody");
	RegisterTag(HTMLElement::theadTag,"thead");
	RegisterTag(HTMLElement::tfootTag,"tfoot");
	RegisterTag(HTMLElement::trTag,"tr");
	RegisterTag(HTMLElement::tdTag,"td");
	RegisterTag(HTMLElement::thTag,"th");
	RegisterTag(HTMLElement::formTag,"form");
	RegisterTag(HTMLElement::fieldsetTag,"fieldset");
	RegisterTag(HTMLElement::legendTag,"legend");
	RegisterTag(HTMLElement::labelTag,"label");
	RegisterTag(HTMLElement::inputTag,"input");
	RegisterTag(HTMLElement::buttonTag,"button");
	RegisterTag(HTMLElement::selectTag,"select");
	RegisterTag(HTMLElement::datalistTag,"datalist");
	RegisterTag(HTMLElement::optgroupTag,"optgroup");
	RegisterTag(HTMLElement::optionTag,"option");
	RegisterTag(HTMLElement::textareaTag,"textarea");
	RegisterTag(HTMLElement::keygenTag,"keygen");
	RegisterTag(HTMLElement::outputTag,"output");
	RegisterTag(HTMLElement::progressTag,"progress");
	RegisterTag(HTMLElement::meterTag,"meter");
	RegisterTag(HTMLElement::detailsTag,"details");
	RegisterTag(HTMLElement::summaryTag,"summary");
	RegisterTag(HTMLElement::commandTag,"command");
	RegisterTag(HTMLElement::menuTag,"menu");
	RegisterTag(HTMLElement::dialogTag,"dialog");
}

HTMLElement::HTMLElement(Document* ownerDocument, const HTMLTag htmlTypeIn)
: Element(ownerDocument, HTMLElement::NameFromTag(htmlTypeIn))
, htmlType(htmlTypeIn){
}

HTMLElement::HTMLElement(Document* ownerDocument, const DOMString& localName, const HTMLTag htmlTypeIn)
: Element(ownerDocument, localName)
, htmlType(htmlTypeIn){
}

HTMLElement::~HTMLElement() {
}

HTMLElement::HTMLTag HTMLElement::TagFromName(const DOMString& localName) {

	InitializeTagMaps();
	if(tagNames.count(localName) == 0){
		return HTMLElement::unknownTag; }
	return tagNames.at(localName);
}

DOMString HTMLElement::NameFromTag(const HTMLTag tag) {

	InitializeTagMaps();
	if(tagTypes.count(tag) == 0){
		return ""; }
	return tagTypes.at(tag);
}

}
