/**
 *
 * @file QueryLimitations.h
 * @author Moritz Wagner
 * @date 23.02.2014
 *
 */

#pragma once

#include <string>
#include <map>
#include <ctime>

#include <StringTools.h>
#include <TimeTools.h>

#include <InvalidOperationException.h>

namespace queryserver {

class QueryFactory;

class QueryLimitations {

	friend class QueryFactory;

public:
	typedef enum
	{
		LIMITATION_UNKNOWN = 0,

		LIMITATION_DOMAIN  = 1,
		LIMITATION_MAX_AGE = 2,
		LIMITATION_LANG    = 4,
		LIMITATION_MIN_AGE = 16,

		LIMITATION_MAX     = 0xFF,
	} QueryLimitationsFlag;

public:
	QueryLimitations();
	virtual ~QueryLimitations();

public:
	/**
	 * returns all enabled flags
	 * @return enabled flags
	 */
	QueryLimitations::QueryLimitationsFlag GetEnabledFlags(void) const;

	/**
	 * checks if certain criteria type is enabled
	 * @param type criteria type to check
	 * @return true if enabled, false if disabled
	 */
	bool IsLimitationEnabled(const QueryLimitations::QueryLimitationsFlag& type) const;

public:
	/**
	 * gets struct tm based limitation
	 * @param type type of limitation
	 * @param out time value
	 * @return true if success, false if error
	 */
	bool GetLimitationByType(const QueryLimitations::QueryLimitationsFlag& type, struct tm& out) const {

		if(!IsLimitationEnabled(type)) {
			THROW_EXCEPTION(errors::InvalidOperationException,"queryserver::QueryLimitations::GetLimitationByType(type == not enabled)"); }

		std::map<QueryLimitationsFlag,std::string>::const_iterator i(limits.find(type));
		return tools::TimeTools::TryParseDate(i->second, out);
	}

	/**
	 * gets limitation by type
	 * @param type type of limitation
	 * @param out value for limitation
	 * @return true if success, false if error
	 */
	template <class T>
	bool GetLimitationByType(const QueryLimitations::QueryLimitationsFlag& type, T& out) const {

		if(!IsLimitationEnabled(type)) {
			THROW_EXCEPTION(errors::InvalidOperationException,"queryserver::QueryLimitations::GetLimitationByType(type == not enabled)"); }

		std::map<QueryLimitationsFlag,std::string>::const_iterator i(limits.find(type));
		return tools::StringTools::TransformString(i->second, out);
	}

private:
	std::map<QueryLimitationsFlag,std::string> limits;
};

}

