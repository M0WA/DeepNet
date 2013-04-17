/**
 *
 * @file MutationObserver.h
 * @author Moritz Wagner
 * @date Mar 6, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <vector>

#include "DOMTypes.h"
#include "MutationRecord.h"

namespace htmlparser {

class MutationObserverInit {
public:
	MutationObserverInit()
	: childList(false)
	, attributes(false)
	, characterData(false)
	, subtree(false)
	, attributeOldValue(false)
	, characterDataOldValue(false)
	{}

	virtual ~MutationObserverInit() {}

public:
	bool childList;
	bool attributes;
	bool characterData;
	bool subtree;
	bool attributeOldValue;
	bool characterDataOldValue;
	std::vector<DOMString> attributeFilter;
};

class MutationObserver {
public:
	typedef void (*MutationCallback)(std::vector<MutationRecord>& mutations, MutationObserver observer);

public:
	MutationObserver(MutationCallback callback);
	virtual ~MutationObserver();

	void observe(Node* target, const MutationObserverInit& options);
	void disconnect();
	std::vector<MutationRecord> takeRecords();

private:
	MutationCallback callback;
};

}
