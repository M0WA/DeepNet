/**
 *
 * @file MutationObserver.h
 * @author Moritz Wagner
 * @date 06.03.2013
 *
 */

#pragma once

#include <vector>

#include "DOMTypes.h"
#include "MutationRecord.h"

namespace domparser {

/**
 * @brief wrapper class for domparser::MutationObserver attributes
 * used for initialization only
 */
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

/**
 * @brief track mutations in DOM tree during runtime
 */
class MutationObserver {
public:
	/**
	 * callback function for mutations
	 * @param mutations mutation records for given observer
	 * @param observer calling observer for this mutation
	 */
	typedef void (*MutationCallback)(std::vector<MutationRecord>& mutations, MutationObserver observer);

public:
	/**
	 * construct mutation observer specifing it's callback
	 * @param callback callback function used in this observer
	 * @see domparser::MutationObserver::MutationCallback
	 */
	MutationObserver(MutationCallback callback);
	virtual ~MutationObserver();

	/**
	 * initializes the target to be observer for mutations
	 * @param target node to observe
	 * @param options initialization parameters
	 */
	void observe(Node* target, const MutationObserverInit& options);

	/**
	 * disconnect this observer, no longer used, no mutation records will be triggered
	 * after a call to this function
	 */
	void disconnect();

	/**
	 * TODO: implement !!!!
	 */
	std::vector<MutationRecord> takeRecords();

private:
	MutationCallback callback;
};

}
