/**
 *
 * @file HTMLCollection.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include "DOMTypes.h"
#include "ListImpl.h"

namespace htmlparser {
	class Element;

/**
 * represents a generic collection of Elements
 */
class HTMLCollection : public ListImpl<Element> {
public:
	HTMLCollection();
	virtual ~HTMLCollection();

	/**
	 * returns a contained element by its tag name
	 * @param name name of the element to look for
	 * @return element
	 */
	void* GetNamedItem(const DOMString& name);
};

}
