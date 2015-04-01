/**
 *
 * @file src/HTMLElement.h
 * @author Moritz Wagner
 * @date 05.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"
#include "Element.h"
#include "DOMTokenList.h"
#include "DOMSettableTokenList.h"
#include "HTMLCollection.h"

namespace domparser {
	class Document;

/**
 * @brief implementation of a generic html element
 * @see domparser::Element
 */
class HTMLElement : public domparser::Element {
public:
	/**
	 * @enum HTMLTag
	 * @brief all compatible html types
	 */
	enum HTMLTag {
		unknownTag,
		htmlTag,
		headTag,
		titleTag,
		baseTag,
		linkTag,
		metaTag,
		styleTag,
		scriptTag,
		noscriptTag,
		bodyTag,
		articleTag,
		sectionTag,
		navTag,
		asideTag,
		h1Tag,
		h2Tag,
		h3Tag,
		h4Tag,
		h5Tag,
		h6Tag,
		hgroupTag,
		headerTag,
		footerTag,
		addressTag,
		pTag,
		hrTag,
		preTag,
		blockquoteTag,
		olTag,
		ulTag,
		liTag,
		dlTag,
		dtTag,
		ddTag,
		figureTag,
		figcaptionTag,
		divTag,
		aTag,
		emTag,
		strongTag,
		smallTag,
		sTag,
		citeTag,
		qTag,
		dfnTag,
		abbrTag,
		timeTag,
		codeTag,
		varTag,
		sampTag,
		kbdTag,
		subTag,
		supTag,
		iTag,
		bTag,
		uTag,
		markTag,
		rubyTag,
		rtTag,
		rpTag,
		bdiTag,
		bdoTag,
		spanTag,
		brTag,
		wbrTag,
		insTag,
		delTag,
		imgTag,
		iframeTag,
		embedTag,
		objectTag,
		paramTag,
		videoTag,
		audioTag,
		sourceTag,
		trackTag,
		canvasTag,
		mapTag,
		areaTag,
		tableTag,
		captionTag,
		colgroupTag,
		colTag,
		tbodyTag,
		theadTag,
		tfootTag,
		trTag,
		tdTag,
		thTag,
		formTag,
		fieldsetTag,
		legendTag,
		labelTag,
		inputTag,
		buttonTag,
		selectTag,
		datalistTag,
		optgroupTag,
		optionTag,
		textareaTag,
		keygenTag,
		outputTag,
		progressTag,
		meterTag,
		detailsTag,
		summaryTag,
		commandTag,
		menuTag,
		dialogTag,
	};

protected:
	HTMLElement(Document* ownerDocument, const DOMString& localName,const HTMLTag htmlType);
	HTMLElement(Document* ownerDocument, const HTMLTag htmlType);
	virtual ~HTMLElement();

public:
	HTMLTag GetHtmlTagType() const { return htmlType; }

public:
	static HTMLTag TagFromName(const DOMString& localName);
	static DOMString NameFromTag(const HTMLTag localName);

private:
	const HTMLTag htmlType;

private:
    DOMString title;
    DOMString lang;
    bool translate;
    DOMString dir;
	DOMStringMap dataset;
};

class HTMLUnknownElement : public domparser::HTMLElement {
public:
	HTMLUnknownElement(Document* ownerDocument, const DOMString& tagName) : HTMLElement(ownerDocument, tagName, HTMLElement::unknownTag) {}
};

// ///////////////////////////////////////////////////////////
//
// root element
//
// ///////////////////////////////////////////////////////////

class HTMLHtmlElement : public domparser::HTMLElement {
public:
	HTMLHtmlElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::htmlTag) {}
};

// ///////////////////////////////////////////////////////////
//
// document metadata
//
// ///////////////////////////////////////////////////////////


class HTMLHeadElement : public domparser::HTMLElement {
public:
	HTMLHeadElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::headTag) {}
};

class HTMLTitleElement : public domparser::HTMLElement {
public:
	HTMLTitleElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::titleTag) {}

private:
	DOMString text;
};

class HTMLBaseElement : public domparser::HTMLElement {
public:
	HTMLBaseElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::baseTag) {}
private:
	DOMString href;
    DOMString target;
};


class HTMLLinkElement : public domparser::HTMLElement {
public:
	HTMLLinkElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::linkTag) {}
private:
	bool disabled;
	DOMString href;
	DOMString rel;
	DOMTokenList relList;
	DOMString media;
	DOMString hreflang;
	DOMString type;
	/*
[PutForwards=value] DOMSettableTokenList sizes;
  */
};

class HTMLMetaElement : public domparser::HTMLElement {
public:
	HTMLMetaElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::metaTag) {}

private:
	DOMString name;
	DOMString httpEquiv;
	DOMString content;
};

class HTMLStyleElement : public domparser::HTMLElement {
public:
	HTMLStyleElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::styleTag) {}

private:
	bool disabled;
	DOMString media;
	DOMString type;
	bool scoped;
};

// ///////////////////////////////////////////////////////////
//
// scripting
//
// ///////////////////////////////////////////////////////////

class HTMLScriptElement : public domparser::HTMLElement {
public:
	HTMLScriptElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::scriptTag) {}

public:
	DOMString src;
	bool async;
	bool defer;
	DOMString type;
	DOMString charset;
	DOMString text;
};

class HTMLNoscriptElement : public domparser::HTMLElement {
public:
	HTMLNoscriptElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::noscriptTag) {}
};

// ///////////////////////////////////////////////////////////
//
// sections
//
// ///////////////////////////////////////////////////////////

class HTMLBodyElement : public domparser::HTMLElement {
public:
	HTMLBodyElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::bodyTag) {}

private:
/*
EventHandler onafterprint;
EventHandler onbeforeprint;
EventHandler onbeforeunload;
EventHandler onblur;
OnErrorEventHandler onerror;
EventHandler onfocus;
EventHandler onhashchange;
EventHandler onload;
EventHandler onmessage;
EventHandler onoffline;
EventHandler ononline;
EventHandler onpopstate;
EventHandler onpagehide;
EventHandler onpageshow;
EventHandler onresize;
EventHandler onscroll;
EventHandler onstorage;
EventHandler onunload;
*/
};

class HTMLArticleElement : public domparser::HTMLElement {
public:
	HTMLArticleElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::articleTag) {}
};

class HTMLSectionElement : public domparser::HTMLElement {
public:
	HTMLSectionElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::sectionTag) {}
};

class HTMLNavElement : public domparser::HTMLElement {
public:
	HTMLNavElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::navTag) {}
};

class HTMLAsideElement : public domparser::HTMLElement {
public:
	HTMLAsideElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::asideTag) {}
};

class HTMLHeadingElement : public domparser::HTMLElement {
protected:
	HTMLHeadingElement(Document* ownerDocument, const HTMLTag tag, unsigned short rank) : HTMLElement(ownerDocument, tag), rank(rank) {}

protected:
	unsigned short rank;
};

class HTMLH1Element : public domparser::HTMLHeadingElement {
public:
	HTMLH1Element(Document* ownerDocument) : HTMLHeadingElement(ownerDocument, HTMLElement::h1Tag, 1) {}
};

class HTMLH2Element : public domparser::HTMLHeadingElement {
public:
	HTMLH2Element(Document* ownerDocument) : HTMLHeadingElement(ownerDocument, HTMLElement::h2Tag, 2) {}
};

class HTMLH3Element : public domparser::HTMLHeadingElement {
public:
	HTMLH3Element(Document* ownerDocument) : HTMLHeadingElement(ownerDocument, HTMLElement::h3Tag, 3) {}
};

class HTMLH4Element : public domparser::HTMLHeadingElement {
public:
	HTMLH4Element(Document* ownerDocument) : HTMLHeadingElement(ownerDocument, HTMLElement::h4Tag, 4) {}
};

class HTMLH5Element : public domparser::HTMLHeadingElement {
public:
	HTMLH5Element(Document* ownerDocument) : HTMLHeadingElement(ownerDocument, HTMLElement::h5Tag, 5) {}
};

class HTMLH6Element : public domparser::HTMLHeadingElement {
public:
	HTMLH6Element(Document* ownerDocument) : HTMLHeadingElement(ownerDocument, HTMLElement::h6Tag, 6) {}
};

class HTMLHgroupElement : public domparser::HTMLElement {
public:
	HTMLHgroupElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::hgroupTag) {}
};

class HTMLHeaderElement : public domparser::HTMLElement {
public:
	HTMLHeaderElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::headerTag) {}
};

class HTMLFooterElement : public domparser::HTMLElement {
public:
	HTMLFooterElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::footerTag) {}
};

class HTMLAddressElement : public domparser::HTMLElement {
public:
	HTMLAddressElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::addressTag) {}
};

// ///////////////////////////////////////////////////////////
//
// groupings
//
// ///////////////////////////////////////////////////////////

class HTMLParagraphElement : public domparser::HTMLElement {
public:
	HTMLParagraphElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::pTag) {}
};

class HTMLHrElement : public domparser::HTMLElement {
public:
	HTMLHrElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::hrTag) {}
};

class HTMLPreElement : public domparser::HTMLElement {
public:
	HTMLPreElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::preTag) {}
};

class HTMLQuoteElement : public domparser::HTMLElement {
protected:
	HTMLQuoteElement(Document* ownerDocument, const HTMLTag tag) : HTMLElement(ownerDocument, tag) {
		/*
		switch(tag) {
		case qTag:
		case blockquoteTag:
			break;
		default:
			throw;
		}
		*/
	}

protected:
	DOMString cite;
};

class HTMLBlockquoteElement : public domparser::HTMLQuoteElement {
public:
	HTMLBlockquoteElement(Document* ownerDocument) : HTMLQuoteElement(ownerDocument, HTMLElement::blockquoteTag) {}
};

class HTMLOListElement : public domparser::HTMLElement {
public:
	HTMLOListElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::olTag) {}

private:
	bool reversed;
	long start;
	DOMString type;
};

class HTMLUListElement : public domparser::HTMLElement {
public:
	HTMLUListElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::ulTag) {}
};

class HTMLLiElement : public domparser::HTMLElement {
public:
	HTMLLiElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::liTag) {}

private:
	long value;
};

class HTMLDListElement : public domparser::HTMLElement {
public:
	HTMLDListElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::dlTag) {}
};

class HTMLDtElement : public domparser::HTMLElement {
public:
	HTMLDtElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::dtTag) {}
};

class HTMLDdElement : public domparser::HTMLElement {
public:
	HTMLDdElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::ddTag) {}
};

class HTMLFigureElement : public domparser::HTMLElement {
public:
	HTMLFigureElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::figureTag) {}
};

class HTMLFigcaptionElement : public domparser::HTMLElement {
public:
	HTMLFigcaptionElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::figcaptionTag) {}
};

class HTMLDivElement : public domparser::HTMLElement {
public:
	HTMLDivElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::divTag) {}
};

// ///////////////////////////////////////////////////////////
//
// text-level semantics
//
// ///////////////////////////////////////////////////////////

class HTMLAnchorElement : public domparser::HTMLElement {
public:
	HTMLAnchorElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::aTag) {}
};

class HTMLEmElement : public domparser::HTMLElement {
public:
	HTMLEmElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::emTag) {}
};

class HTMLStrongElement : public domparser::HTMLElement {
public:
	HTMLStrongElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::strongTag) {}
};

class HTMLSmallElement : public domparser::HTMLElement {
public:
	HTMLSmallElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::smallTag) {}
};

class HTMLSElement : public domparser::HTMLElement {
public:
	HTMLSElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::sTag) {}
};

class HTMLCiteElement : public domparser::HTMLElement {
public:
	HTMLCiteElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::citeTag) {}
};

class HTMLQElement : public domparser::HTMLQuoteElement {
public:
	HTMLQElement(Document* ownerDocument) : HTMLQuoteElement(ownerDocument,HTMLElement::qTag) {}
};

class HTMLDfnElement : public domparser::HTMLElement {
public:
	HTMLDfnElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::dfnTag) {}
};

class HTMLAbbrElement : public domparser::HTMLElement {
public:
	HTMLAbbrElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::abbrTag) {}
};

class HTMLTimeElement : public domparser::HTMLElement {
public:
	HTMLTimeElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::timeTag) {}

private:
	DOMString datetime;
};

class HTMLCodeElement : public domparser::HTMLElement {
public:
	HTMLCodeElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::codeTag) {}
};

class HTMLVarElement : public domparser::HTMLElement {
public:
	HTMLVarElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::varTag) {}
};

class HTMLSampElement : public domparser::HTMLElement {
public:
	HTMLSampElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::sampTag) {}
};

class HTMLKbdElement : public domparser::HTMLElement {
public:
	HTMLKbdElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::kbdTag) {}
};

class HTMLSubElement : public domparser::HTMLElement {
public:
	HTMLSubElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::subTag) {}
};

class HTMLSupElement : public domparser::HTMLElement {
public:
	HTMLSupElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::supTag) {}
};

class HTMLIElement : public domparser::HTMLElement {
public:
	HTMLIElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::iTag) {}
};

class HTMLBElement : public domparser::HTMLElement {
public:
	HTMLBElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::bTag) {}
};

class HTMLUElement : public domparser::HTMLElement {
public:
	HTMLUElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::uTag) {}
};

class HTMLMarkElement : public domparser::HTMLElement {
public:
	HTMLMarkElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::markTag) {}
};

class HTMLRubyElement : public domparser::HTMLElement {
public:
	HTMLRubyElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::rubyTag) {}
};

class HTMLRtElement : public domparser::HTMLElement {
public:
	HTMLRtElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::rtTag) {}
};

class HTMLRpElement : public domparser::HTMLElement {
public:
	HTMLRpElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::rpTag) {}
};

class HTMLBdiElement : public domparser::HTMLElement {
public:
	HTMLBdiElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::bdiTag) {}
};

class HTMLBdoElement : public domparser::HTMLElement {
public:
	HTMLBdoElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::bdoTag) {}
};

class HTMLSpanElement : public domparser::HTMLElement {
public:
	HTMLSpanElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::spanTag) {}
};

class HTMLBrElement : public domparser::HTMLElement {
public:
	HTMLBrElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::brTag) {}
};

class HTMLWbrElement : public domparser::HTMLElement {
public:
	HTMLWbrElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::wbrTag) {}
};

// ///////////////////////////////////////////////////////////
//
// edits
//
// ///////////////////////////////////////////////////////////

class HTMLModElement : public domparser::HTMLElement {
protected:
	HTMLModElement(Document* ownerDocument, const HTMLTag tag) : HTMLElement(ownerDocument, tag) {}
};

class HTMLInsElement : public domparser::HTMLModElement {
public:
	HTMLInsElement(Document* ownerDocument) : HTMLModElement(ownerDocument, HTMLElement::insTag) {}
};

class HTMLDelElement : public domparser::HTMLModElement {
public:
	HTMLDelElement(Document* ownerDocument) : HTMLModElement(ownerDocument, HTMLElement::delTag) {}
};

// ///////////////////////////////////////////////////////////
//
// embedded content
//
// ///////////////////////////////////////////////////////////

class HTMLImageElement : public domparser::HTMLElement {
public:
	HTMLImageElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::imgTag) {}

private:
	DOMString alt;
	DOMString src;

	DOMString crossOrigin;
	DOMString useMap;
	bool isMap;
	unsigned long width;
	unsigned long height;
	unsigned long naturalWidth;
	unsigned long naturalHeight;
	bool complete;
};

class HTMLIFrameElement : public domparser::HTMLElement {
public:
	HTMLIFrameElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::iframeTag) {}

private:
	DOMString src;
	DOMString srcdoc;
	DOMString name;
//[PutForwards=value] DOMSettableTokenList sandbox;
	bool seamless;
	DOMString width;
	DOMString height;
	Document* contentDocument;
//WindowProxy? contentWindow;
};

class HTMLEmbedElement : public domparser::HTMLElement {
public:
	HTMLEmbedElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::embedTag) {}

private:
	DOMString src;
	DOMString type;
	DOMString width;
	DOMString height;
//legacycaller any (any... arguments);
};

class HTMLObjectElement : public domparser::HTMLElement {
public:
	HTMLObjectElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::objectTag) {}

private:
	DOMString data;
	DOMString type;
	bool typeMustMatch;
	DOMString name;
	DOMString useMap;
//HTMLFormElement? form;
	DOMString width;
	DOMString height;
	Document* contentDocument;
//WindowProxy? contentWindow;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
//bool checkValidity();
//void setCustomValidity(DOMString error);

//legacycaller any (any... arguments);
};

class HTMLParamElement : public domparser::HTMLElement {
public:
	HTMLParamElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::paramTag) {}

private:
	DOMString name;
	DOMString value;
};

class HTMLMediaElement : public domparser::HTMLElement {
protected:
	HTMLMediaElement(Document* ownerDocument, const HTMLTag tag) : HTMLElement(ownerDocument, tag) {}
  /*
  // error state
  MediaError? error;

  // network state
       DOMString src;
  DOMString currentSrc;
       DOMString crossOrigin;
  const unsigned short NETWORK_EMPTY = 0;
  const unsigned short NETWORK_IDLE = 1;
  const unsigned short NETWORK_LOADING = 2;
  const unsigned short NETWORK_NO_SOURCE = 3;
  unsigned short networkState;
       DOMString preload;
  TimeRanges buffered;
  void load();
  DOMString canPlayType(DOMString type);

  // ready state
  const unsigned short HAVE_NOTHING = 0;
  const unsigned short HAVE_METADATA = 1;
  const unsigned short HAVE_CURRENT_DATA = 2;
  const unsigned short HAVE_FUTURE_DATA = 3;
  const unsigned short HAVE_ENOUGH_DATA = 4;
  unsigned short readyState;
  bool seeking;

  // playback state
       double currentTime;
  unrestricted double duration;
  Date startDate;
  bool paused;
       double defaultPlaybackRate;
       double playbackRate;
  TimeRanges played;
  TimeRanges seekable;
  bool ended;
       bool autoplay;
       bool loop;
  void play();
  void pause();

  // media controller
       DOMString mediaGroup;
       MediaController? controller;

  // controls
       bool controls;
       double volume;
       bool muted;
       bool defaultMuted;

  // tracks
  AudioTrackList audioTracks;
  VideoTrackList videoTracks;
  TextTrackList textTracks;
  TextTrack addTextTrack(DOMString kind, optional DOMString label, optional DOMString language);
 */
};

class HTMLVideoElement : public domparser::HTMLMediaElement {
public:
	HTMLVideoElement(Document* ownerDocument) : HTMLMediaElement(ownerDocument,HTMLElement::videoTag) {}

private:
	unsigned long width;
	unsigned long height;
	unsigned long videoWidth;
	unsigned long videoHeight;
	DOMString poster;
};

class HTMLAudioElement : public domparser::HTMLMediaElement {
public:
	HTMLAudioElement(Document* ownerDocument) : HTMLMediaElement(ownerDocument,HTMLElement::audioTag) {}
};

class HTMLSourceElement : public domparser::HTMLElement {
public:
	HTMLSourceElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::sourceTag) {}

private:
	DOMString src;
	DOMString type;
	DOMString media;
};

class HTMLTrackElement : public domparser::HTMLElement {
private:
	enum ReadyState {
		NONE = 0,
		LOADING = 1,
		LOADED = 2,
		ERROR = 3,
	};

public:
	HTMLTrackElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::trackTag) {}

private:
	DOMString kind;
	DOMString src;
	DOMString srclang;
	DOMString label;
	bool isDefault;

	ReadyState readyState;

//TextTrack track;
};

class HTMLCanvasElement : public domparser::HTMLElement {
public:
	HTMLCanvasElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::canvasTag) {}

private:
	unsigned long width;
	unsigned long height;

	//DOMString toDataURL(optional DOMString type, any... arguments);
	//void toBlob(FileCallback? _callback, optional DOMString type, any... arguments);

	//object? getContext(DOMString contextId, any... arguments);
};

class HTMLMapElement : public domparser::HTMLElement {
public:
	HTMLMapElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::mapTag) {}

private:
	DOMString name;
	HTMLCollection areas;
	HTMLCollection images;
};

class HTMLAreaElement : public domparser::HTMLElement {
public:
	HTMLAreaElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::areaTag) {}

private:
	DOMString alt;
	DOMString coords;
	DOMString shape;
  //stringifier DOMString href;
	DOMString target;

	DOMString rel;
	DOMTokenList relList;
	DOMString media;
	DOMString hreflang;
	DOMString type;

	DOMString protocol;
	DOMString host;
	DOMString hostname;
	DOMString port;
	DOMString pathname;
	DOMString search;
	DOMString hash;
};

// ///////////////////////////////////////////////////////////
//
// tabular data
//
// ///////////////////////////////////////////////////////////

class HTMLTableCaptionElement : public domparser::HTMLElement {
public:
	HTMLTableCaptionElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::captionTag) {}
};

class HTMLTableSectionElement : public domparser::HTMLElement {
protected:
	HTMLTableSectionElement(Document* ownerDocument, const HTMLTag tag) : HTMLElement(ownerDocument, tag) {}
};

class HTMLTableColElement : public domparser::HTMLElement {
public:
	HTMLTableColElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::colTag) {}
protected:
	HTMLTableColElement(Document* ownerDocument, const HTMLTag tag) : HTMLElement(ownerDocument, tag) {}

private:
	unsigned long span;
};

class HTMLTableElement : public domparser::HTMLElement {
public:
	HTMLTableElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::tableTag) {}

private:
	HTMLTableCaptionElement* caption;
	//HTMLElement* createCaption();
	//void deleteCaption();
	HTMLTableSectionElement* tHead;
	//HTMLElement createTHead();
	//void deleteTHead();
	HTMLTableSectionElement* tFoot;
	//HTMLElement createTFoot();
	//void deleteTFoot();
	HTMLCollection tBodies;
	HTMLElement* createTBody();
	HTMLCollection rows;
	//HTMLElement insertRow(optional long index);
	//void deleteRow(long index);
	DOMString border;
};

class HTMLTableColgroupElement : public domparser::HTMLTableColElement {
public:
	HTMLTableColgroupElement(Document* ownerDocument) : HTMLTableColElement(ownerDocument,HTMLElement::colgroupTag) {}
};

class HTMLTbodyElement : public domparser::HTMLTableSectionElement {
public:
	HTMLTbodyElement(Document* ownerDocument) : HTMLTableSectionElement(ownerDocument,HTMLElement::tbodyTag) {}
};

class HTMLTheadElement : public domparser::HTMLTableSectionElement {
public:
	HTMLTheadElement(Document* ownerDocument) : HTMLTableSectionElement(ownerDocument,HTMLElement::theadTag) {}
};

class HTMLTfootElement : public domparser::HTMLTableSectionElement {
public:
	HTMLTfootElement(Document* ownerDocument) : HTMLTableSectionElement(ownerDocument,HTMLElement::tfootTag) {}
};

class HTMLTableRowElement : public domparser::HTMLElement {
public:
	HTMLTableRowElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::trTag) {}

private:
	long rowIndex;
	long sectionRowIndex;
	HTMLCollection cells;
	//HTMLElement insertCell(optional long index);
	//void deleteCell(long index);
};

class HTMLTableCellElement : public domparser::HTMLElement {
protected:
	HTMLTableCellElement(Document* ownerDocument, const HTMLTag tag) : HTMLElement(ownerDocument,tag) {}
};

class HTMLTableDataCellElement : public domparser::HTMLTableCellElement {
public:
	HTMLTableDataCellElement(Document* ownerDocument) : HTMLTableCellElement(ownerDocument,HTMLElement::tdTag) {}
};

class HTMLTableHeaderCellElement : public domparser::HTMLTableCellElement {
public:
	HTMLTableHeaderCellElement(Document* ownerDocument) : HTMLTableCellElement(ownerDocument,HTMLElement::thTag) {}

private:
	DOMString scope;
	DOMString abbr;
};

// ///////////////////////////////////////////////////////////
//
// forms
//
// ///////////////////////////////////////////////////////////

class HTMLFormElement : public domparser::HTMLElement {
public:
	HTMLFormElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::formTag) {}

private:
	DOMString acceptCharset;
	DOMString action;
	DOMString autocomplete;
	DOMString enctype;
	DOMString encoding;
	DOMString method;
	DOMString name;
	bool noValidate;
	DOMString target;

	//HTMLFormControlsCollection elements;
	long length;
	//getter Element (unsigned long index);
	//getter object (DOMString name);

	//void submit();
	//void reset();
	//bool checkValidity();
};

class HTMLFieldSetElement : public domparser::HTMLElement {
public:
	HTMLFieldSetElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::fieldsetTag) {}

private:
	bool disabled;
	HTMLFormElement* form;
	DOMString name;

	DOMString type;

	//HTMLFormControlsCollection elements;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);
};

class HTMLLegendElement : public domparser::HTMLElement {
public:
	HTMLLegendElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::legendTag) {}

private:
	HTMLFormElement* form;
};

class HTMLLabelElement : public domparser::HTMLElement {
public:
	HTMLLabelElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::labelTag) {}

private:
	HTMLFormElement* form;
	DOMString htmlFor;
	HTMLElement* control;
};

class HTMLInputElement : public domparser::HTMLElement {
public:
	HTMLInputElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::inputTag) {}

private:
	DOMString accept;
	DOMString alt;
	DOMString autocomplete;
	bool autofocus;
	bool defaultChecked;
	bool checked;
	DOMString dirName;
	bool disabled;
	HTMLFormElement* form;
	//FileList? files;
	DOMString formAction;
	DOMString formEnctype;
	DOMString formMethod;
	bool formNoValidate;
	DOMString formTarget;
	unsigned long height;
	bool indeterminate;
	HTMLElement* list;
	DOMString max;
	long maxLength;
	DOMString min;
	bool multiple;
	DOMString name;
	DOMString pattern;
	DOMString placeholder;
	bool readOnly;
	bool required;
	unsigned long size;
	DOMString src;
	DOMString step;
	DOMString type;
	DOMString defaultValue;
	DOMString value;
	//Date? valueAsDate;
	double valueAsNumber;
	unsigned long width;

	//void stepUp(optional long n);
	//void stepDown(optional long n);

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);

	NodeList labels;

	//void select();
	unsigned long selectionStart;
	unsigned long selectionEnd;
	DOMString selectionDirection;

	//void setSelectionRange(unsigned long start, unsigned long end, optional DOMString direction);
};

class HTMLButtonElement : public domparser::HTMLElement {
public:
	HTMLButtonElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::buttonTag) {}

private:
	bool autofocus;
	bool disabled;
	HTMLFormElement* form;
	DOMString formAction;
	DOMString formEnctype;
	DOMString formMethod;
	bool formNoValidate;
	DOMString formTarget;
	DOMString name;
	DOMString type;
    DOMString value;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);

	NodeList labels;
};

class HTMLSelectElement : public domparser::HTMLElement {
public:
	HTMLSelectElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::selectTag) {}

private:
	bool autofocus;
	bool disabled;
	HTMLFormElement* form;
	bool multiple;
	DOMString name;
	bool required;
	unsigned long size;

	DOMString type;

	//HTMLOptionsCollection options;
	unsigned long length;
	//getter Element item(unsigned long index);
	//object namedItem(DOMString name);
	//void add((HTMLOptionElement or HTMLOptGroupElement) element, optional (HTMLElement or long)? before = null);
	//void remove(long index);
	//setter creator void (unsigned long index, HTMLOptionElement? option);

	HTMLCollection selectedOptions;
	long selectedIndex;
	DOMString value;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);

	NodeList labels;
};

class HTMLDataListElement : public domparser::HTMLElement {
public:
	HTMLDataListElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::datalistTag) {}

private:
	HTMLCollection options;
};

class HTMLOptGroupElement : public domparser::HTMLElement {
public:
	HTMLOptGroupElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::optgroupTag) {}

private:
	bool disabled;
	DOMString label;
};

class HTMLOptionElement : public domparser::HTMLElement {
public:
	HTMLOptionElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::optionTag) {}

private:
	bool disabled;
	HTMLFormElement* form;
	DOMString label;
	bool defaultSelected;
	bool selected;
	DOMString value;

	DOMString text;
	long index;
};

class HTMLTextAreaElement : public domparser::HTMLElement {
public:
	HTMLTextAreaElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::textareaTag) {}

private:
	bool autofocus;
	unsigned long cols;
	DOMString dirName;
	bool disabled;
	HTMLFormElement* form;
	long maxLength;
	DOMString name;
	DOMString placeholder;
	bool readOnly;
	bool required;
	unsigned long rows;
	DOMString wrap;

	DOMString type;
	DOMString defaultValue;
	DOMString value;
	unsigned long textLength;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);

	NodeList labels;

	//void select();
	unsigned long selectionStart;
	unsigned long selectionEnd;
	DOMString selectionDirection;

	//void setSelectionRange(unsigned long start, unsigned long end, optional DOMString direction);
};

class HTMLKeygenElement : public domparser::HTMLElement {
public:
	HTMLKeygenElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::keygenTag) {}

private:
	bool autofocus;
	DOMString challenge;
	bool disabled;
	HTMLFormElement* form;
	DOMString keytype;
	DOMString name;

	DOMString type;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);

	NodeList labels;
};

class HTMLOutputElement : public domparser::HTMLElement {
public:
	HTMLOutputElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::outputTag) {}

private:
	DOMSettableTokenList htmlFor;
	HTMLFormElement* form;
	DOMString name;

	DOMString type;
	DOMString defaultValue;
	DOMString value;

	bool willValidate;
	//ValidityState validity;
	DOMString validationMessage;
	//bool checkValidity();
	//void setCustomValidity(DOMString error);

	NodeList labels;
};

class HTMLProgressElement : public domparser::HTMLElement {
public:
	HTMLProgressElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::progressTag) {}

private:
	double value;
	double max;
	double position;
	NodeList labels;
};

class HTMLMeterElement : public domparser::HTMLElement {
public:
	HTMLMeterElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::meterTag) {}

private:
	double value;
	double min;
	double max;
	double low;
	double high;
	double optimum;
	NodeList labels;
};


class HTMLDetailsElement : public domparser::HTMLElement {
public:
	HTMLDetailsElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::detailsTag) {}

private:
	bool open;
};


class HTMLSummaryElement : public domparser::HTMLElement {
public:
	HTMLSummaryElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::summaryTag) {}
};

class HTMLCommandElement : public domparser::HTMLElement {
public:
	HTMLCommandElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::commandTag) {}

private:
	DOMString type;
	DOMString label;
	DOMString icon;
	bool disabled;
	bool checked;
	DOMString radiogroup;
	HTMLElement* command;
};

class HTMLMenuElement : public domparser::HTMLElement {
public:
	HTMLMenuElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::menuTag) {}

private:
	DOMString type;
	DOMString label;
};

class HTMLDialogElement : public domparser::HTMLElement {
public:
	HTMLDialogElement(Document* ownerDocument) : HTMLElement(ownerDocument,HTMLElement::dialogTag) {}

private:
	bool open;
	DOMString returnValue;

	//void show(optional (MouseEvent or Element) anchor);
	//void showModal(optional (MouseEvent or Element) anchor);
	//void close(optional DOMString returnValue);
};

}
