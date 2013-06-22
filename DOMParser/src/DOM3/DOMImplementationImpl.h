/**
 *
 * @file DOMImplementationImpl.h
 * @author Moritz Wagner
 * @date 22.06.2013
 *
 */

#pragma once

#include "DOMImplementation.h"

namespace domparser {

namespace dom3 {

class DOMImplementationImpl : public domparser::dom3::DOMImplementation {
public:
	DOMImplementationImpl();
	virtual ~DOMImplementationImpl();

public:
	virtual bool hasFeature(const domparser::dom3::DOMString& feature, const domparser::dom3::DOMString& version) const;
	virtual domparser::dom3::DOMObject* getFeature(const domparser::dom3::DOMString& feature, const domparser::dom3::DOMString& version) const;
	virtual domparser::dom3::DocumentType* createDocumentType(
			const domparser::dom3::DOMString& qualifiedName,
			const domparser::dom3::DOMString& publicId,
			const domparser::dom3::DOMString& systemId) throw(domparser::dom3::DOMException);

	virtual domparser::dom3::Document* createDocument(
			const domparser::dom3::DOMString* const namespaceURI,
			const domparser::dom3::DOMString* const qualifiedName,
			const DocumentType* const doctype) throw(domparser::dom3::DOMException);

public:
	virtual domparser::dom3::DOMImplementation* clone() const;
};

}

}
