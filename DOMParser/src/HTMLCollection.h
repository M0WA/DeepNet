/**
 *
 * @file HTMLCollection.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"
#include "ListImpl.h"

namespace domparser {
	class Element;

class HTMLCollection : public ListImpl<Element> {
public:
	HTMLCollection();
	virtual ~HTMLCollection();

	void* GetNamedItem(const DOMString& name);
};

}
