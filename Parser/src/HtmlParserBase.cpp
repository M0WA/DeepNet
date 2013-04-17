/*
 * HtmlParserBase.cpp
 *
 *  Created on: 06.03.2012
 *      Author: Moritz Wagner
 */

#include "HtmlParserBase.h"

#include "HtmlParserThread.h"
#include "HtmlParserParam.h"

using namespace threading;

namespace parser {

HtmlParserBase::HtmlParserBase()
: Thread((Thread::ThreadFunction)&(HtmlParserBase::HtmlParserThreadFunc))
, parserParam(NULL)
{

}

HtmlParserBase::~HtmlParserBase() {
}

void* HtmlParserBase::HtmlParserThreadFunc(Thread::THREAD_PARAM* threadParam)
{
	parser::HtmlParserBase* instance = dynamic_cast<parser::HtmlParserBase*>(threadParam->instance);
	instance->parserParam = reinterpret_cast<HtmlParserParam*>(threadParam->pParam);

	if(!instance->StartParser())
		return (void*)1;

	bool errorOccured = false;
	while(!instance->ShallEnd())
	{
		if(instance->WatchDog()) {
			errorOccured = true;
			break; }

		sleep(1);
	}

	bool bReturn = !instance->StopParser() || errorOccured;
	instance->parserParam = NULL;
	return (void*)bReturn;
}

bool HtmlParserBase::StopParser()
{
	std::map<HtmlParserThread*,HtmlParserParam*>::iterator iterThreads = htmlParserThreads.begin();
	for(; iterThreads != htmlParserThreads.end(); ++iterThreads)
	{
		iterThreads->first->SetShallEnd(true);
	}

	iterThreads = htmlParserThreads.begin();
	for(; iterThreads != htmlParserThreads.end(); ++iterThreads)
	{
		iterThreads->first->WaitForThread();
		delete iterThreads->first;
		delete iterThreads->second;
	}
	htmlParserThreads.clear();

	return true;
}

bool HtmlParserBase::WatchDog()
{
	std::map<HtmlParserThread*,HtmlParserParam*>::iterator iterThreads = htmlParserThreads.begin();

	//check if at least one thread is alive
	for(; iterThreads != htmlParserThreads.end(); ++iterThreads){
		if ( iterThreads->first->IsRunning() )
			return false;
	}
	return true;
}

}
