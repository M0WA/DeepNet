/**
 * @file TimeTools.cpp
 * @author Moritz Wagner
 * @date 21.12.2012
 */

#include "TimeTools.h"

#include <cmath>
#include <sstream>

namespace tools {

static const struct tm zeroTm = { 0 };

TimeTools::TimeTools() {
}

TimeTools::~TimeTools() {
}

struct timeval TimeTools::MilliSecondsToTimeval(const size_t& milliseconds) {

	struct timeval out;
	MilliSecondsToTimeval(milliseconds, out);
	return out;
}

void TimeTools::MilliSecondsToTimeval(const size_t& in, struct timeval& out) {

	out.tv_sec = 0;
	out.tv_usec = 0;

	size_t milliseconds = in;

	if (milliseconds > 1000) {
		float seconds = floor((milliseconds / 1000.0f));
		milliseconds -= ((__time_t ) seconds) * 1000;

		out.tv_sec = (__time_t ) seconds;
	}
	out.tv_usec = milliseconds * 1000;
}

size_t TimeTools::TimevalToMilliSeconds(const struct timeval& in) {

	size_t milliseconds = in.tv_sec * 1000;
	milliseconds += in.tv_usec / 1000;
	return milliseconds;
}

bool TimeTools::TimevalSubtract(struct timeval x, struct timeval y, struct timeval& result) {

	timerclear(&result);
	timersub(&x, &y, &result);
	int success = timerisset(&result);
	if(success > 0)
		NormalizeTimeval(result);

	return success > 0;
}

bool TimeTools::TimevalAddition(struct timeval x, struct timeval y, struct timeval& result) {

	timerclear(&result);
	timeradd(&x, &y, &result);
	int success = timerisset(&result);

	if(success > 0)
		NormalizeTimeval(result);

	return success > 0;
}

std::string TimeTools::TimevalToString(struct timeval timeVal) {

	NormalizeTimeval(timeVal);

	std::ostringstream oss;
	oss << timeVal.tv_sec << "." << (timeVal.tv_usec / 1000) << "s";
	return oss.str();
}

void TimeTools::NormalizeTimeval(struct timeval& time) {

	while(time.tv_usec > 1000000) {
		time.tv_usec -= 1000000;
		++time.tv_sec;
	}
}

bool TimeTools::TryParseDate(const std::string& timeString, struct tm& tmOut) {

	if( ParseDate_ISO_1123(timeString, tmOut) )
		return true;

	if( ParseDate_ISO_1036(timeString, tmOut) )
		return true;

	if( ParseDate_AscTime(timeString, tmOut) )
		return true;

	return false;
}

bool TimeTools::ParseDate_ISO_1123(const std::string& timeString, struct tm& tmOut) {

	// RFC 822, updated by RFC 1123
	// Sun, 06 Nov 1994 08:49:37 GMT

	static const char* pszFmtIso1123 = "%a, %d %b %Y %H:%M:%S %Z";
	return strptime(timeString.c_str(), pszFmtIso1123, &tmOut) != 0;
}

bool TimeTools::ParseDate_ISO_1036(const std::string& timeString, struct tm& tmOut){

	// RFC 850, obsoleted by RFC 1036
	// Sunday, 06-Nov-94 08:49:37 GMT

	static const char* pszFmtIso1036 = "%A, %d-%b-%y %H:%M:%S %Z";
	return strptime(timeString.c_str(), pszFmtIso1036, &tmOut) != 0;
}

bool TimeTools::ParseDate_AscTime(const std::string& timeString, struct tm& tmOut) {

	// ANSI C's asctime() format
	// Sun Nov  6 08:49:37 1994

	static const char* pszFmtAscTime = " %a %b  %d %H:%M:%S %Y";
	return strptime(timeString.c_str(), pszFmtAscTime, &tmOut) != 0;
}

bool TimeTools::ParsePostgreSQLTimestamp(const std::string timeString, struct tm& tmOut) {

	// 1994-11-06 08:49:37

	static const char* pszFmtAscTime = " %Y-%m-%d %H:%M:%S";
	return strptime(timeString.c_str(), pszFmtAscTime, &tmOut) != 0;
}

void TimeTools::InitTm(struct tm& init) {
	init = zeroTm;
}

void TimeTools::InitTimeval(struct timeval& init) {
	timerclear(&init);
}

struct timeval TimeTools::InitTimeval() {
	struct timeval result;
	InitTimeval(result);
	return result;
}

bool TimeTools::IsZero(const struct timeval& test) {
	return timerisset(&test) > 0;
}

bool TimeTools::IsZero(struct tm test) {
	time_t timeT = mktime(&test);
	return timeT == 0;
}

struct tm TimeTools::NowUTC(void) {

  struct tm tmNow;
  TimeTools::NowUTC(tmNow);
  return tmNow;
}

void TimeTools::NowUTC(struct tm& tmNow) {

  time_t now = time(0);
  gmtime_r(&now,&tmNow);
}

void TimeTools::NowUTCAdd(struct tm& tmFuture, const int nDays) {

    time_t now = time(0);
    now += (nDays * 86400); //86400 seconds/day
    gmtime_r(&now,&tmFuture);
}

struct tm TimeTools::NowUTCAdd(const int nDays) {
	struct tm tmFuture;
	TimeTools::NowUTCAdd(tmFuture, nDays);
	return tmFuture;
}

}
