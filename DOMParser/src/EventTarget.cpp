/**
 *
 * @file EventTarget.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "EventTarget.h"

namespace domparser {

EventTarget::EventTarget() {
}

EventTarget::~EventTarget() {
}

void EventTarget::addEventListener(const DOMString& type, EventListener callback, bool capture) {

	listenEvents[type].insert( EventTargetListener(callback,capture) );
}

void EventTarget::removeEventListener(const DOMString& type, EventListener callback, bool capture) {

	listenEvents[type].erase( EventTargetListener(callback,capture) );
}

bool EventTarget::dispatchEvent(Event& event) {

	/*
	if(event.GetDispatchFlag() || !event.GetInitializedFlag() ) {
		//TODO: throw invalid state exception
		return false;
	}
	event.SetIsTrusted(false);
	event.SetDispatchFlag(true);
	event.SetTarget(this);
	*/

	return false;
}


}
