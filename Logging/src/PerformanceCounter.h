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

private:
	timeval startval;
	timeval endval;
};
}

#ifdef ENABLE_PERFORMANCE_LOG
	#define PERFORMANCE_LOG_START  \
		tools::PerformanceCounter loggingPerformanceCounter;\
		loggingPerformanceCounter.Start();

	#define PERFORMANCE_LOG_RESTART \
		loggingPerformanceCounter.Start();

	#define PERFORMANCE_LOG_STOP(logMsg){ \
		double dDurationPerformanceCounter = 0.0; \
		std::ostringstream ssLogPerformanceCounter; \
		dDurationPerformanceCounter = loggingPerformanceCounter.Stop(); \
		ssLogPerformanceCounter << logMsg << " duration: " <<  dDurationPerformanceCounter << " sec(-s)"; \
		log::Logging::Log(log::Logging::GetLogLevel(),ssLogPerformanceCounter.str()); }

#else
	#define PERFORMANCE_LOG_START
	#define PERFORMANCE_LOG_RESTART
	#define PERFORMANCE_LOG_STOP(logMsg) {}
#endif
