/**
 *
 * @file src/DocumentType.h
 * @author Moritz Wagner
 * @date 04.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"
#include "Node.h"

namespace domparser {

class DocumentType : public Node {
public:
	DocumentType(Document* ownerDocument);
	virtual ~DocumentType();

	const DOMString& GetName() const { return name; }

private:
	DOMString name;
	DOMString publicId;
	DOMString systemId;
};

}
