/**
 *
 * @file DOM3/DOMImplementation.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include "DOMException.h"

namespace domparser {

namespace dom3 {

class DOMString;
class DOMObject;
class DocumentType;
class Document;

class DOMImplementation {
protected:
	DOMImplementation();
public:
	virtual ~DOMImplementation();

public:
	//DOM3 interface
	virtual bool hasFeature(const domparser::dom3::DOMString& feature, const domparser::dom3::DOMString& version) const = 0;
	virtual domparser::dom3::DOMObject* getFeature(const domparser::dom3::DOMString& feature, const domparser::dom3::DOMString& version) const = 0;

	virtual domparser::dom3::DocumentType* createDocumentType(
			const domparser::dom3::DOMString& qualifiedName,
			const domparser::dom3::DOMString& publicId,
			const domparser::dom3::DOMString& systemId) throw(domparser::dom3::DOMException) = 0;

	virtual domparser::dom3::Document* createDocument(
			const domparser::dom3::DOMString* const namespaceURI,
			const domparser::dom3::DOMString* const qualifiedName,
			const DocumentType* const doctype) throw(domparser::dom3::DOMException) = 0;

public:
	virtual DOMImplementation* clone() const = 0;
};

}

}
