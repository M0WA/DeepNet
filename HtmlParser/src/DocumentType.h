/**
 *
 * @file DocumentType.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"
#include "Node.h"

namespace htmlparser {

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
