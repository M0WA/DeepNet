/**
 *
 * @file ElementFactory.cpp
 * @author Moritz Wagner
 * @date Mar 5, 2013
 *
 * TODO: description for this file
 *
 */

#include "ElementFactory.h"

#include <map>
#include <string>

#include "Element.h"
#include "HTMLElement.h"

#include <Mutex.h>

namespace htmlparser {

ElementFactory::ElementFactory(Document* doc,const DOMString& localName)
: doc(doc)
, localName(localName){
}

ElementFactory::~ElementFactory() {
}

Element* ElementFactory::FromName(Document* doc,const DOMString& localName) {
	ElementFactory instance(doc,localName);
	return instance.FromName();
}

Element* ElementFactory::FromName(Document* doc, const DOMString* nameSpace, const DOMString& qualifiedName) {
	return 0;
}

Element* ElementFactory::FromName() {

	HTMLElement::HTMLTag tag = HTMLElement::TagFromName(localName);

	Element* newElement = 0;
	switch( tag )
	{
	case HTMLElement::htmlTag:
		newElement = dynamic_cast<Element*>(new HTMLHtmlElement(doc));
		break;
	case HTMLElement::headTag:
		newElement = dynamic_cast<Element*>(new HTMLHeadElement(doc));
		break;
	case HTMLElement::titleTag:
		newElement = dynamic_cast<Element*>(new HTMLTitleElement(doc));
		break;
	case HTMLElement::baseTag:
		newElement = dynamic_cast<Element*>(new HTMLBaseElement(doc));
		break;
	case HTMLElement::linkTag:
		newElement = dynamic_cast<Element*>(new HTMLLinkElement(doc));
		break;
	case HTMLElement::metaTag:
		newElement = dynamic_cast<Element*>(new HTMLMetaElement(doc));
		break;
	case HTMLElement::styleTag:
		newElement = dynamic_cast<Element*>(new HTMLStyleElement(doc));
		break;
	case HTMLElement::scriptTag:
		newElement = dynamic_cast<Element*>(new HTMLScriptElement(doc));
		break;
	case HTMLElement::noscriptTag:
		newElement = dynamic_cast<Element*>(new HTMLNoscriptElement(doc));
		break;
	case HTMLElement::bodyTag:
		newElement = dynamic_cast<Element*>(new HTMLBodyElement(doc));
		break;
	case HTMLElement::articleTag:
		newElement = dynamic_cast<Element*>(new HTMLArticleElement(doc));
		break;
	case HTMLElement::sectionTag:
		newElement = dynamic_cast<Element*>(new HTMLSectionElement(doc));
		break;
	case HTMLElement::navTag:
		newElement = dynamic_cast<Element*>(new HTMLNavElement(doc));
		break;
	case HTMLElement::asideTag:
		newElement = dynamic_cast<Element*>(new HTMLAsideElement(doc));
		break;
	case HTMLElement::h1Tag:
		newElement = dynamic_cast<Element*>(new HTMLH1Element(doc));
		break;
	case HTMLElement::h2Tag:
		newElement = dynamic_cast<Element*>(new HTMLH2Element(doc));
		break;
	case HTMLElement::h3Tag:
		newElement = dynamic_cast<Element*>(new HTMLH3Element(doc));
		break;
	case HTMLElement::h4Tag:
		newElement = dynamic_cast<Element*>(new HTMLH4Element(doc));
		break;
	case HTMLElement::h5Tag:
		newElement = dynamic_cast<Element*>(new HTMLH5Element(doc));
		break;
	case HTMLElement::h6Tag:
		newElement = dynamic_cast<Element*>(new HTMLH6Element(doc));
		break;
	case HTMLElement::hgroupTag:
		newElement = dynamic_cast<Element*>(new HTMLHgroupElement(doc));
		break;
	case HTMLElement::headerTag:
		newElement = dynamic_cast<Element*>(new HTMLHeaderElement(doc));
		break;
	case HTMLElement::footerTag:
		newElement = dynamic_cast<Element*>(new HTMLFooterElement(doc));
		break;
	case HTMLElement::addressTag:
		newElement = dynamic_cast<Element*>(new HTMLAddressElement(doc));
		break;
	case HTMLElement::pTag:
		newElement = dynamic_cast<Element*>(new HTMLParagraphElement(doc));
		break;
	case HTMLElement::hrTag:
		newElement = dynamic_cast<Element*>(new HTMLHrElement(doc));
		break;
	case HTMLElement::preTag:
		newElement = dynamic_cast<Element*>(new HTMLPreElement(doc));
		break;
	case HTMLElement::blockquoteTag:
		newElement = dynamic_cast<Element*>(new HTMLBlockquoteElement(doc));
		break;
	case HTMLElement::olTag:
		newElement = dynamic_cast<Element*>(new HTMLOListElement(doc));
		break;
	case HTMLElement::ulTag:
		newElement = dynamic_cast<Element*>(new HTMLUListElement(doc));
		break;
	case HTMLElement::liTag:
		newElement = dynamic_cast<Element*>(new HTMLLiElement(doc));
		break;
	case HTMLElement::dlTag:
		newElement = dynamic_cast<Element*>(new HTMLDListElement(doc));
		break;
	case HTMLElement::dtTag:
		newElement = dynamic_cast<Element*>(new HTMLDtElement(doc));
		break;
	case HTMLElement::ddTag:
		newElement = dynamic_cast<Element*>(new HTMLDdElement(doc));
		break;
	case HTMLElement::figureTag:
		newElement = dynamic_cast<Element*>(new HTMLFigureElement(doc));
		break;
	case HTMLElement::figcaptionTag:
		newElement = dynamic_cast<Element*>(new HTMLFigcaptionElement(doc));
		break;
	case HTMLElement::divTag:
		newElement = dynamic_cast<Element*>(new HTMLDivElement(doc));
		break;
	case HTMLElement::aTag:
		newElement = dynamic_cast<Element*>(new HTMLAnchorElement(doc));
		break;
	case HTMLElement::emTag:
		newElement = dynamic_cast<Element*>(new HTMLEmElement(doc));
		break;
	case HTMLElement::strongTag:
		newElement = dynamic_cast<Element*>(new HTMLStrongElement(doc));
		break;
	case HTMLElement::smallTag:
		newElement = dynamic_cast<Element*>(new HTMLSmallElement(doc));
		break;
	case HTMLElement::sTag:
		newElement = dynamic_cast<Element*>(new HTMLSElement(doc));
		break;
	case HTMLElement::citeTag:
		newElement = dynamic_cast<Element*>(new HTMLCiteElement(doc));
		break;
	case HTMLElement::qTag:
		newElement = dynamic_cast<Element*>(new HTMLQElement(doc));
		break;
	case HTMLElement::dfnTag:
		newElement = dynamic_cast<Element*>(new HTMLDfnElement(doc));
		break;
	case HTMLElement::abbrTag:
		newElement = dynamic_cast<Element*>(new HTMLAbbrElement(doc));
		break;
	case HTMLElement::timeTag:
		newElement = dynamic_cast<Element*>(new HTMLTimeElement(doc));
		break;
	case HTMLElement::codeTag:
		newElement = dynamic_cast<Element*>(new HTMLCodeElement(doc));
		break;
	case HTMLElement::varTag:
		newElement = dynamic_cast<Element*>(new HTMLVarElement(doc));
		break;
	case HTMLElement::sampTag:
		newElement = dynamic_cast<Element*>(new HTMLSampElement(doc));
		break;
	case HTMLElement::kbdTag:
		newElement = dynamic_cast<Element*>(new HTMLKbdElement(doc));
		break;
	case HTMLElement::subTag:
		newElement = dynamic_cast<Element*>(new HTMLSubElement(doc));
		break;
	case HTMLElement::supTag:
		newElement = dynamic_cast<Element*>(new HTMLSupElement(doc));
		break;
	case HTMLElement::iTag:
		newElement = dynamic_cast<Element*>(new HTMLIElement(doc));
		break;
	case HTMLElement::bTag:
		newElement = dynamic_cast<Element*>(new HTMLBElement(doc));
		break;
	case HTMLElement::uTag:
		newElement = dynamic_cast<Element*>(new HTMLUElement(doc));
		break;
	case HTMLElement::markTag:
		newElement = dynamic_cast<Element*>(new HTMLMarkElement(doc));
		break;
	case HTMLElement::rubyTag:
		newElement = dynamic_cast<Element*>(new HTMLRubyElement(doc));
		break;
	case HTMLElement::rtTag:
		newElement = dynamic_cast<Element*>(new HTMLRtElement(doc));
		break;
	case HTMLElement::rpTag:
		newElement = dynamic_cast<Element*>(new HTMLRpElement(doc));
		break;
	case HTMLElement::bdiTag:
		newElement = dynamic_cast<Element*>(new HTMLBdiElement(doc));
		break;
	case HTMLElement::bdoTag:
		newElement = dynamic_cast<Element*>(new HTMLBdoElement(doc));
		break;
	case HTMLElement::spanTag:
		newElement = dynamic_cast<Element*>(new HTMLSpanElement(doc));
		break;
	case HTMLElement::brTag:
		newElement = dynamic_cast<Element*>(new HTMLBrElement(doc));
		break;
	case HTMLElement::wbrTag:
		newElement = dynamic_cast<Element*>(new HTMLWbrElement(doc));
		break;
	case HTMLElement::insTag:
		newElement = dynamic_cast<Element*>(new HTMLInsElement(doc));
		break;
	case HTMLElement::delTag:
		newElement = dynamic_cast<Element*>(new HTMLDelElement(doc));
		break;
	case HTMLElement::imgTag:
		newElement = dynamic_cast<Element*>(new HTMLImageElement(doc));
		break;
	case HTMLElement::iframeTag:
		newElement = dynamic_cast<Element*>(new HTMLIFrameElement(doc));
		break;
	case HTMLElement::embedTag:
		newElement = dynamic_cast<Element*>(new HTMLEmbedElement(doc));
		break;
	case HTMLElement::objectTag:
		newElement = dynamic_cast<Element*>(new HTMLObjectElement(doc));
		break;
	case HTMLElement::paramTag:
		newElement = dynamic_cast<Element*>(new HTMLParamElement(doc));
		break;
	case HTMLElement::videoTag:
		newElement = dynamic_cast<Element*>(new HTMLVideoElement(doc));
		break;
	case HTMLElement::audioTag:
		newElement = dynamic_cast<Element*>(new HTMLAudioElement(doc));
		break;
	case HTMLElement::sourceTag:
		newElement = dynamic_cast<Element*>(new HTMLSourceElement(doc));
		break;
	case HTMLElement::trackTag:
		newElement = dynamic_cast<Element*>(new HTMLTrackElement(doc));
		break;
	case HTMLElement::canvasTag:
		newElement = dynamic_cast<Element*>(new HTMLCanvasElement(doc));
		break;
	case HTMLElement::mapTag:
		newElement = dynamic_cast<Element*>(new HTMLMapElement(doc));
		break;
	case HTMLElement::areaTag:
		newElement = dynamic_cast<Element*>(new HTMLAreaElement(doc));
		break;
	case HTMLElement::tableTag:
		newElement = dynamic_cast<Element*>(new HTMLTableElement(doc));
		break;
	case HTMLElement::captionTag:
		newElement = dynamic_cast<Element*>(new HTMLTableCaptionElement(doc));
		break;
	case HTMLElement::colgroupTag:
		newElement = dynamic_cast<Element*>(new HTMLTableColgroupElement(doc));
		break;
	case HTMLElement::colTag:
		newElement = dynamic_cast<Element*>(new HTMLTableColElement(doc));
		break;
	case HTMLElement::tbodyTag:
		newElement = dynamic_cast<Element*>(new HTMLTbodyElement(doc));
		break;
	case HTMLElement::theadTag:
		newElement = dynamic_cast<Element*>(new HTMLTheadElement(doc));
		break;
	case HTMLElement::tfootTag:
		newElement = dynamic_cast<Element*>(new HTMLTfootElement(doc));
		break;
	case HTMLElement::trTag:
		newElement = dynamic_cast<Element*>(new HTMLTableRowElement(doc));
		break;
	case HTMLElement::tdTag:
		newElement = dynamic_cast<Element*>(new HTMLTableDataCellElement(doc));
		break;
	case HTMLElement::thTag:
		newElement = dynamic_cast<Element*>(new HTMLTableHeaderCellElement(doc));
		break;
	case HTMLElement::formTag:
		newElement = dynamic_cast<Element*>(new HTMLFormElement(doc));
		break;
	case HTMLElement::fieldsetTag:
		newElement = dynamic_cast<Element*>(new HTMLFieldSetElement(doc));
		break;
	case HTMLElement::legendTag:
		newElement = dynamic_cast<Element*>(new HTMLLegendElement(doc));
		break;
	case HTMLElement::labelTag:
		newElement = dynamic_cast<Element*>(new HTMLLabelElement(doc));
		break;
	case HTMLElement::inputTag:
		newElement = dynamic_cast<Element*>(new HTMLInputElement(doc));
		break;
	case HTMLElement::buttonTag:
		newElement = dynamic_cast<Element*>(new HTMLButtonElement(doc));
		break;
	case HTMLElement::selectTag:
		newElement = dynamic_cast<Element*>(new HTMLSelectElement(doc));
		break;
	case HTMLElement::datalistTag:
		newElement = dynamic_cast<Element*>(new HTMLDataListElement(doc));
		break;
	case HTMLElement::optgroupTag:
		newElement = dynamic_cast<Element*>(new HTMLOptGroupElement(doc));
		break;
	case HTMLElement::optionTag:
		newElement = dynamic_cast<Element*>(new HTMLOptionElement(doc));
		break;
	case HTMLElement::textareaTag:
		newElement = dynamic_cast<Element*>(new HTMLTextAreaElement(doc));
		break;
	case HTMLElement::keygenTag:
		newElement = dynamic_cast<Element*>(new HTMLKeygenElement(doc));
		break;
	case HTMLElement::outputTag:
		newElement = dynamic_cast<Element*>(new HTMLOutputElement(doc));
		break;
	case HTMLElement::progressTag:
		newElement = dynamic_cast<Element*>(new HTMLProgressElement(doc));
		break;
	case HTMLElement::meterTag:
		newElement = dynamic_cast<Element*>(new HTMLMeterElement(doc));
		break;
	case HTMLElement::detailsTag:
		newElement = dynamic_cast<Element*>(new HTMLDetailsElement(doc));
		break;
	case HTMLElement::summaryTag:
		newElement = dynamic_cast<Element*>(new HTMLSummaryElement(doc));
		break;
	case HTMLElement::commandTag:
		newElement = dynamic_cast<Element*>(new HTMLCommandElement(doc));
		break;
	case HTMLElement::menuTag:
		newElement = dynamic_cast<Element*>(new HTMLMenuElement(doc));
		break;
	case HTMLElement::dialogTag:
		newElement = dynamic_cast<Element*>(new HTMLDialogElement(doc));
		break;

	case HTMLElement::unknownTag:
	default:
		newElement = dynamic_cast<Element*>(new HTMLUnknownElement(doc,localName));
		break;
	}

	return newElement;
}

}
