/**
 *
 * @file src/HTMLCollection.h
 * @author Moritz Wagner
 * @date 04.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"
#include "ListImpl.h"

namespace domparser {
	class Element;

/**
 * @brief represents a random access list for html elements
 */
class HTMLCollection : public ListImpl<Element> {
public:
	HTMLCollection();
	virtual ~HTMLCollection();

	/**
	 * get an item by it's tag name
	 */
	void* GetNamedItem(const DOMString& name);
};

}
