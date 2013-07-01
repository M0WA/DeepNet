/**
 * @file PerformanceCounter.cpp
 * @author Moritz Wagner
 * @date 20.09.2011
 */

#include "PerformanceCounter.h"

#include "TimeTools.h"

namespace tools
{

bool PerformanceCounter::enablePerformanceLog = true;

PerformanceCounter::PerformanceCounter()
{
}

PerformanceCounter::~PerformanceCounter()
{
}

void PerformanceCounter::Start(void)
{
	gettimeofday(&startval, 0);
}

double PerformanceCounter::Stop(void)
{
	gettimeofday(&endval, 0);

	timeval duration;
	TimeTools::TimevalSubtract(endval, startval, duration);
	double dSec          = static_cast<double>( duration.tv_sec );
	double dMicroseconds = static_cast<double>( duration.tv_usec );
	return ( dSec + ((dMicroseconds / 1000.0f) / 1000.0f) );
}

void PerformanceCounter::Stop(timeval& duration) {
	gettimeofday(&endval, 0);
	TimeTools::TimevalSubtract(endval, startval, duration);
}

void PerformanceCounter::EnablePerformanceLog(const bool enable) {
	enablePerformanceLog = enable;
}

bool PerformanceCounter::IsPerformanceLogEnabled() const {
	return enablePerformanceLog;
}

}
