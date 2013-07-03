/**
 *
 * @file DOM3/DOMImplementationImpl.cpp
 * @author Moritz Wagner
 * @date 22.06.2013
 *
 */

#include "DOMImplementationImpl.h"

namespace domparser {

namespace dom3 {

DOMImplementationImpl::DOMImplementationImpl() {
}

DOMImplementationImpl::~DOMImplementationImpl() {
}

domparser::dom3::DOMImplementation* DOMImplementationImpl::clone() const {
	return new DOMImplementationImpl();
}

bool DOMImplementationImpl::hasFeature(const domparser::dom3::DOMString& feature, const domparser::dom3::DOMString& version) const {
	return false;
}

domparser::dom3::DOMObject* DOMImplementationImpl::getFeature(const domparser::dom3::DOMString& feature, const domparser::dom3::DOMString& version) const {
	return 0;
}

domparser::dom3::DocumentType* DOMImplementationImpl::createDocumentType(
			const domparser::dom3::DOMString& qualifiedName,
			const domparser::dom3::DOMString& publicId,
			const domparser::dom3::DOMString& systemId) throw(domparser::dom3::DOMException) {
	return 0;
}

domparser::dom3::Document* DOMImplementationImpl::createDocument(
		const domparser::dom3::DOMString* const namespaceURI,
		const domparser::dom3::DOMString* const qualifiedName,
		const DocumentType* const doctype) throw(domparser::dom3::DOMException) {
	return 0;
}

}

}
