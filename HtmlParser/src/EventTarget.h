/**
 *
 * @file EventTarget.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

#include <string>
#include <map>
#include <set>

#include "DOMTypes.h"

namespace htmlparser {
	class Event;

/**
 * implementation of an EventTarget, used a base class
 * for htmlparser::Node.
 * classes derived from EventTarget are able to receive
 * events during parse-time
 */
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
	/**
	 * adds an event listener for a certain event
	 * @param type type of the element as a string
	 * @param callback callback function when event occurs
	 * @param capture //TODO
	 */
	void addEventListener(const DOMString& type, EventListener callback, bool capture = false);

	/**
	 * removes an event listener for a certain event
	 * @param type type of the element as a string
	 * @param callback callback function when event occurs
	 * @param capture //TODO
	 */
	void removeEventListener(const DOMString& type, EventListener callback, bool capture = false);

	/**
	 * dispatch event on this target
	 * @param event event to dispatch
	 */
	bool dispatchEvent(Event& event);

private:
	std::map<DOMString, std::set<EventTargetListener> > listenEvents;
};

}
