/**
 *
 * @file FencedUrlFetcherThread.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

#include <vector>
#include "GenericWebUrlFetcherThread.h"

namespace crawler {

class FencedUrlFetcherThread : public GenericWebUrlFetcherThread {

public:
	struct FencedUrlFetcherThreadParam : public GenericWebUrlFetcherThread::GenericWebUrlFetcherThreadParam {
		std::vector<long long> secondLevelDomains;
	};

public:
	FencedUrlFetcherThread();
	virtual ~FencedUrlFetcherThread();
};

}
