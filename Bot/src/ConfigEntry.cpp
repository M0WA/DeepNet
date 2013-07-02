/**
 *
 * @file ConfigEntry.cpp
 * @author Moritz Wagner
 * @date 02.07.2013
 *
 */

#include "ConfigEntry.h"

namespace bot {

ConfigEntry::ConfigEntry()
: name("")
, desc("")
, value("")
, mandatory(false)
, isFlag(false)
, lockOverride(false)
, valueSet(true)
{
}

ConfigEntry::ConfigEntry( const std::string& name, const std::string& desc, const bool mandatory, const bool isFlag, const std::string* defaultValue )
: name(name)
, desc(desc)
, value( (defaultValue ? *defaultValue : "") )
, mandatory(mandatory)
, isFlag(isFlag)
, lockOverride(false)
, valueSet(defaultValue)
{
}

ConfigEntry::~ConfigEntry() {
}

bool ConfigEntry::operator==(const std::string& rhs) const {
	return (name.compare(rhs) == 0);
}

void ConfigEntry::SetValue(const std::string& value) {
	SetValue(value.c_str());
}

void ConfigEntry::SetValue(const char* value) {
	if(!lockOverride) {
		this->value = value;
		valueSet = true;
	}
}

const std::string& ConfigEntry::GetValue() const {
	return value;
}

}
