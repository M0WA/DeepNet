/**
 * @file TimeTools.h
 * @author Moritz Wagner
 * @date 21.12.2012
 */

#pragma once

#include <sys/time.h>
#include <string>

namespace tools {

/**
 * @brief class implementing date and time specific functions and formats.
 */
class TimeTools {
private:
	TimeTools();
public:
	virtual ~TimeTools();

public:
	/**
	 * converts milliseconds to timeval.
	 * @param milliseconds milliseconds.
	 * @return timeval.
	 */
	static struct timeval MilliSecondsToTimeval(const size_t& milliseconds);

	/**
	 * converts milliseconds to timeval.
	 * @param milliseconds milliseconds.
	 * @param out timeval.
	 */
	static void MilliSecondsToTimeval(const size_t& milliseconds, struct timeval& out);

	/**
	 * converts timeval to milliseconds.
	 * @param in timeval
	 * @return milliseconds.
	 */
	static size_t TimevalToMilliSeconds(const struct timeval& in);

	/**
	 * subtracts two timevals.
	 * @param time1 minuend.
	 * @param time2 subtrahend.
	 * @param result result.
	 * @return false on error, true on success.
	 */
	static bool TimevalSubtract(struct timeval time1, struct timeval time2, struct timeval& result);

	/**
	 * adds two timevals.
	 * @param time1 timeval.
	 * @param time2 timeval.
	 * @param result result.
	 * @return false on error, true on success.
	 */
	static bool TimevalAddition(struct timeval time1, struct timeval time2, struct timeval& result);

	/**
	 * converts timeval to string (containing seconds).
	 * @param timeVal timeval.
	 * @return string.
	 */
	static std::string TimevalToString(struct timeval timeVal);

	/**
	 * normalize timeval in place.
	 * @param time timeval to normalize.
	 */
	static void NormalizeTimeval(struct timeval& time);

	/**
	 * try to parse date according to ISO112,ISO1036 and ASCII time format.
	 * @param timeString string to parse.
	 * @param tmOut result.
	 * @return false on error, true on success.
	 */
	static bool TryParseDate(const std::string& timeString, struct tm& tmOut);

	/**
	 * parse string according to ISO1123 standard.
	 * @param timeString string to parse.
	 * @param tmOut result.
	 * @return false on error, true on success.
	 */
	static bool ParseDate_ISO_1123(const std::string& timeString, struct tm& tmOut);

	/**
	 * parse string according to ISO1036 standard.
	 * @param timeString string to parse.
	 * @param tmOut result.
	 * @return false on error, true on success.
	 */
	static bool ParseDate_ISO_1036(const std::string& timeString, struct tm& tmOut);

	/**
	 * parse string according to ASCII time format.
	 * @param timeString string to parse.
	 * @param tmOut result.
	 * @return false on error, true on success.
	 */
	static bool ParseDate_AscTime (const std::string& timeString, struct tm& tmOut);

	/**
	 * zero initialize struct tm.
	 * @param init tm to initialize.
	 */
	static void InitTm(struct tm& init);

	/**
	 * zero initialize timeval.
	 * @param init timeval to initialize.
	 */
	static void InitTimeval(struct timeval& init);


	/**
	 * zero initialize timeval.
	 * @return timeval to initialize.
	 */
	static struct timeval InitTimeval();

	/**
	 * checks if timeval is zero initialized.
	 * @param test timeval to check.
	 * @return false if not zero initialized, true if it is.
	 */
	static bool IsZero(const struct timeval& test);

	/**
	 * checks if struct tm is zero initialized.
	 * @param test struct tm to check.
	 * @return false if not zero initialized, true if it is.
	 */
	static bool IsZero(struct tm test);

	/**
	 * gets current time in UTC as struct tm.
	 * @return current UTC time.
	 */
    static struct tm NowUTC(void);

	/**
	 * gets current time in UTC as struct tm.
	 * @param tmNow current UTC time.
	 */
    static void NowUTC(struct tm& tmNow);

	/**
	 * gets future time in UTC as struct tm adding nDays.
	 * @param tmFuture future UTC time.
	 * @param nDays days to add to current time.
	 */
    static void NowUTCAdd(struct tm& tmFuture, const int nDays);

	/**
	 * gets future time in UTC as struct tm adding nDays.
	 * @param nDays days to add to current time.
	 * @return future UTC time.
	 */
    static struct tm NowUTCAdd(const int nDays);
};

}
