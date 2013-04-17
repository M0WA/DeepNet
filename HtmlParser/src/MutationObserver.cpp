/**
 *
 * @file MutationObserver.cpp
 * @author Moritz Wagner
 * @date Mar 6, 2013
 *
 * TODO: description for this file
 *
 */

#include "MutationObserver.h"

namespace htmlparser {

MutationObserver::MutationObserver(MutationCallback callback)
: callback(callback){
}

MutationObserver::~MutationObserver() {
}

void MutationObserver::observe(Node* target, const MutationObserverInit& options) {

}

void MutationObserver::disconnect() {

}

std::vector<MutationRecord> MutationObserver::takeRecords() {
	return std::vector<MutationRecord>();
}

}
