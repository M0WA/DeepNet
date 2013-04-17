/**
 *
 * @file Event.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include "DOMTypes.h"

namespace htmlparser {
	class EventTarget;

class EventInit {
public:
	EventInit()
	: bubbles(false)
	, cancelable(false)
	{ }

	EventInit(const bool& bubbles, const bool& cancelable)
	: bubbles(bubbles)
	, cancelable(cancelable)
	{ }

	bool bubbles;
	bool cancelable;
};

class Event {
public:
	enum EventPhaseType {
		NONE = 0,
		CAPTURING_PHASE = 1,
		AT_TARGET = 2,
		BUBBLING_PHASE = 3,
	};

public:
	Event(const DOMString& type, const EventInit& init);
	Event(const DOMString& type);
	virtual ~Event();

	bool GetDispatchFlag() const { return dispatch_flag; }
	bool GetInitializedFlag() const { return initialized_flag; }

	void SetDispatchFlag(const bool dispatch_flag) { this->dispatch_flag = dispatch_flag; }
	void SetIsTrusted(const bool isTrusted) { this->isTrusted = isTrusted; }
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
