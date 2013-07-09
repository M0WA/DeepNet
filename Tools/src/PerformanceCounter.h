/**
 * @file PerformanceCounter.h
 * @author Moritz Wagner
 * @date 20.09.2011
 */

#pragma once

#include <sys/time.h>
#include <sstream>

#include "Logging.h"

namespace tools
{

/**
 * @brief precise time measurement class.
 * use this class for measuring time in a high
 * precision.
 */
class PerformanceCounter
{
public:
	PerformanceCounter();
	virtual ~PerformanceCounter();

	/**
	 * start measurement.
	 */
	void Start(void);

	/**
	 * stop measurement.
	 * @return duration (in seconds).
	 */
	double Stop(void);

	/**
	 * stop measurement.
	 * @param duration duration (in seconds).
	 */
	void Stop(timeval& duration);

public:
	/**
	 * used to enable/disable PERFORMANCE_LOG_* macros at runtime
	 * @param enable true to enable, false to disable
	 */
	static void EnablePerformanceLog(const bool enable);

	/**
	 * checks if performance log is enabled
	 * @return true if enabled, false if disabled
	 */
	static bool IsPerformanceLogEnabled();

private:
	timeval startval;
	timeval endval;

private:
	static bool enablePerformanceLog;
};
}

#ifdef ENABLE_PERFORMANCE_LOG
	#define PERFORMANCE_LOG_START  \
		tools::PerformanceCounter loggingPerformanceCounter;\
		loggingPerformanceCounter.Start(); \

	#define PERFORMANCE_LOG_RESTART \
		loggingPerformanceCounter.Start(); \

	#define PERFORMANCE_LOG_STOP(logMsg){ \
		double dDurationPerformanceCounter(loggingPerformanceCounter.Stop()); \
		if(tools::PerformanceCounter::IsPerformanceLogEnabled()) { \
			std::ostringstream ssLogPerformanceCounter; \
			ssLogPerformanceCounter << logMsg << " duration: " <<  dDurationPerformanceCounter << " sec(-s)"; \
			log::Logging::LogCurrentLevel(ssLogPerformanceCounter.str()); \
		} \
	} \

#else
	#define PERFORMANCE_LOG_START
	#define PERFORMANCE_LOG_RESTART
	#define PERFORMANCE_LOG_STOP(logMsg) {}
#endif
