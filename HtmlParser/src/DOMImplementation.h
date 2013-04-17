/**
 *
 * @file DOMImplementation.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"

namespace htmlparser {
	class DocumentType;
	class Document;

class DOMImplementation {
public:
	DOMImplementation();
	virtual ~DOMImplementation();

	DocumentType* createDocumentType(const DOMString& qualifiedName, const DOMString& publicId, const DOMString& systemId) {
		return 0;
	}

	//XMLDocument createDocument(DOMString? namespace, [TreatNullAs=EmptyString] DOMString qualifiedName, DocumentType? doctype);
	Document* createHTMLDocument(const DOMString& title) {
		return 0;//new Document(0, this, url, "utf-8", data.GetContentType().c_str());
	}
};

}
