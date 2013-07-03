/**
 *
 * @file src/DOMTypes.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <string>
#include <map>
#include <ctime>

#include <Pointer.h>

#define DOMString std::string
#define DOMStringPtr tools::AutoPointer<DOMString>

#define DOMStringMap std::map<std::string, std::string>

#define DOMTimestamp struct tm
