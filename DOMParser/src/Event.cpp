/**
 *
 * @file Event.cpp
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#include "Event.h"
#include <TimeTools.h>

namespace domparser {

Event::Event(const DOMString& type, const EventInit& init)
: type(type)
, target(0)
, currentTarget(0)
, eventPhase(NONE)
, bubbles(init.bubbles)
, cancelable(init.cancelable)
, isTrusted(false)
, stop_propagation_flag(false)
, stop_immediate_propagation_flag(false)
, canceled_flag(false)
, initialized_flag(false)
, dispatch_flag(false) {

	tools::TimeTools::InitTm(timestamp);
	initEvent(type, init.bubbles, init.cancelable);
}

Event::Event(const DOMString& type)
: type(type)
, target(0)
, currentTarget(0)
, eventPhase(NONE)
, bubbles(false)
, cancelable(false)
, isTrusted(false)
, stop_propagation_flag(false)
, stop_immediate_propagation_flag(false)
, canceled_flag(false)
, initialized_flag(false)
, dispatch_flag(false) {

	tools::TimeTools::InitTm(timestamp);
	initEvent(type, false, false);
}

Event::~Event() {
}

void Event::initEvent(const DOMString& type, const bool& bubbles, const bool& cancelable) {

	initialized_flag = true;
	if(dispatch_flag)
		return;

	stop_propagation_flag = false;
	stop_immediate_propagation_flag = false;
	canceled_flag = false;

	isTrusted = false;
	target = 0;
	this->type = type;
	this->bubbles = bubbles;
	this->cancelable = cancelable;
}

void Event::stopPropagation() {
	stop_propagation_flag = true;
}

void Event::stopImmediatePropagation() {
	stop_immediate_propagation_flag = stop_propagation_flag = true;
}

void Event::preventDefault() {

	if(cancelable) {
		canceled_flag = true;
	}
}

}
