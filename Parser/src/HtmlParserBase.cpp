/*
 * HtmlParserBase.cpp
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#include "HtmlParserBase.h"

#include "HtmlParserThread.h"
#include "HtmlParserParam.h"

#include <Logging.h>

using namespace threading;

namespace parser {

HtmlParserBase::HtmlParserBase(const HtmlParserParam* parserParam)
: Thread((Thread::ThreadFunction)&(HtmlParserBase::HtmlParserThreadFunc))
, parserParam(parserParam) {
}

HtmlParserBase::~HtmlParserBase() {
}

void* HtmlParserBase::HtmlParserThreadFunc(Thread::THREAD_PARAM* threadParam)
{
	log::Logging::RegisterThreadID("HtmlParserBase");
	parser::HtmlParserBase* instance(dynamic_cast<parser::HtmlParserBase*>(threadParam->instance));

	if(!instance->StartParser())
		return (void*)1;

	bool errorOccured(false);
	while(!instance->ShallEnd())
	{
		if(instance->WatchDog()) {
			errorOccured = true;
			break; }

		sleep(1);
	}

	bool bReturn = !instance->StopParser() || errorOccured;
	return (void*)bReturn;
}

bool HtmlParserBase::StopParser()
{
	std::map<HtmlParserThread*,HtmlParserParam*>::iterator iterThreads(htmlParserThreads.begin());
	for(; iterThreads != htmlParserThreads.end(); ++iterThreads) {
		iterThreads->first->SetShallEnd(true); }

	iterThreads = htmlParserThreads.begin();
	for(; iterThreads != htmlParserThreads.end(); ++iterThreads) {
		iterThreads->first->WaitForThread();
		delete iterThreads->first;
		delete iterThreads->second;}

	htmlParserThreads.clear();
	return true;
}

bool HtmlParserBase::WatchDog()
{
	//check if at least one thread is alive
	std::map<HtmlParserThread*,HtmlParserParam*>::const_iterator iterThreads(htmlParserThreads.begin());
	for(; iterThreads != htmlParserThreads.end(); ++iterThreads){
		if ( iterThreads->first->IsRunning() )
			return false;
	}
	return true;
}

}
