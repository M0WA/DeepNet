/**
 *
 * @file src/DOMImplementation.h
 * @author Moritz Wagner
 * @date 04.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"

namespace domparser {
	class DocumentType;
	class Document;

/**
 * @brief implementation of DOM tree specified by W3C
 * @see domparser::DocumentFactory on how to construct documents properly
 */
class DOMImplementation {
public:
	DOMImplementation();
	virtual ~DOMImplementation();

	/**
	 * creates a DocumentType
	 * @param qualifiedName name including namespace
	 * @param publicId PublicID
	 * @param systemId SystemID
	 * @return created document type object
	 */
	DocumentType* createDocumentType(const DOMString& qualifiedName, const DOMString& publicId, const DOMString& systemId) {
		return 0;
	}

	//XMLDocument createDocument(DOMString? namespace, [TreatNullAs=EmptyString] DOMString qualifiedName, DocumentType? doctype);

	/**
	 * creates a html document
	 * @param title title of the constructed document
	 * @return created html document
	 */
	Document* createHTMLDocument(const DOMString& title) {
		return 0;//new Document(0, this, url, "utf-8", data.GetContentType().c_str());
	}
};

}
