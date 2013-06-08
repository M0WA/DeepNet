/**
 *
 * @file Event.h
 * @author Moritz Wagner
 * @date 04.03.2013
 *
 */

#pragma once

#include "DOMTypes.h"

namespace domparser {
	class EventTarget;

/**
 * @brief initializes a DOM event specification it's release condition
 * for more information please consult W3C specification
 */
class EventInit {
public:
	/**
	 * constructs "normal" event attributes
	 */
	EventInit()
	: bubbles(false)
	, cancelable(false)
	{ }

	/**
	 * constructs an event init condition specifing all items
	 * @param bubbles use bubble algo when releasing chained event
	 * @param cancelable true if event is cancelable after it's released
	 */
	EventInit(const bool& bubbles, const bool& cancelable)
	: bubbles(bubbles)
	, cancelable(cancelable)
	{ }

	bool bubbles;
	bool cancelable;
};

class Event {
public:
	/**
	 * @enum EventPhaseType
	 * @brief release phase of this event
	 */
	//TODO: DOCUMENATION NEEDED, describe event types
	enum EventPhaseType {
		NONE = 0,
		CAPTURING_PHASE = 1,
		AT_TARGET = 2,
		BUBBLING_PHASE = 3,
	};

public:
	/**
	 * constructs an event by it's type string and init parameters
	 * @param type type-string of this element
	 * @param init initialization parameters for this event
	 */
	Event(const DOMString& type, const EventInit& init);

	/**
	 * constructs an event by it's type string using default init parameters (cancelable = false, bubbles = false)
	 * @param type type-string of this element
	 */
	Event(const DOMString& type);
	virtual ~Event();

	/**
	 * gets this event's dispatch flag
	 * @return true if set, false if unset
	 */
	bool GetDispatchFlag() const { return dispatch_flag; }

	/**
	 * gets this event's initialized flag
	 * @return true if set, false if unset
	 */
	bool GetInitializedFlag() const { return initialized_flag; }

	/**
	 * sets this event's dispatch flag
	 * @param dispatch_flag new dispatch state
	 */
	void SetDispatchFlag(const bool dispatch_flag) { this->dispatch_flag = dispatch_flag; }

	/**
	 * sets this event's trusted flag
	 * @param isTrusted true if event is trusted (within parents' documents domain)
	 */
	void SetIsTrusted(const bool isTrusted) { this->isTrusted = isTrusted; }

	/**
	 * set's this events target
	 * @param target new target of this event
	 */
	void SetTarget(EventTarget* target) { this->target = target; }

private:
	void stopPropagation();
	void stopImmediatePropagation();
	void preventDefault();

private:
	bool GetDefaultPrevented() const { return canceled_flag; }

private:
	void initEvent(const DOMString& type, const bool& bubbles, const bool& cancelable);

private:
	DOMString type;
	EventTarget* target;
	EventTarget* currentTarget;

	EventPhaseType eventPhase;

	bool bubbles;
	bool cancelable;

	//bool defaultPrevented;

	bool isTrusted;
	DOMTimestamp timestamp;

private:
    bool stop_propagation_flag;
    bool stop_immediate_propagation_flag;
    bool canceled_flag;
    bool initialized_flag;
    bool dispatch_flag;

};

}
