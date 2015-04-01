/**
 *
 * @file src/EventTarget.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <string>
#include <map>
#include <set>

#include "DOMTypes.h"

namespace domparser {
	class Event;

class EventTarget {

	typedef void (*EventListener)(const Event&);

private:
	struct EventTargetListener {
	public:
		EventTargetListener(EventListener callback, bool capture)
		: callback(callback)
		, capture(capture){}

		bool operator<(const EventTargetListener& rhs) const {
			return callback < rhs.callback;
		}

		EventListener callback;
		bool capture;
	};

public:
	EventTarget();
	virtual ~EventTarget();

public:
	void addEventListener(const DOMString& type, EventListener callback, bool capture = false);
	void removeEventListener(const DOMString& type, EventListener callback, bool capture = false);
	bool dispatchEvent(Event& event);

private:
	std::map<DOMString, std::set<EventTargetListener> > listenEvents;
};

}
