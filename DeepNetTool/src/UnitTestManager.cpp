/**
 *
 * @file UnitTestManager.cpp
 * @author Moritz Wagner
 * @date Apr 19, 2013
 *
 */

#include "UnitTestManager.h"
#include "UnitTest.h"

#include <Logging.h>

namespace toolbot {

UnitTestManager::UnitTestManager() {
}

UnitTestManager::~UnitTestManager() {
	Cleanup();
}

void UnitTestManager::AddUnitTest(toolbot::UnitTest* unitTest) {
	tests.push_back(unitTest);
}

bool UnitTestManager::Run() {
	bool success = true;
	std::vector<toolbot::UnitTest*>::iterator iter = tests.begin();
	for(;iter != tests.end(); ++iter) {
		log::Logging::Log(log::Logging::LOGLEVEL_INFO,"unit test: %s, starting",(*iter)->GetName().c_str());
		bool singleTestSuccess = (*iter)->Run();
		if(singleTestSuccess) {
			log::Logging::Log(log::Logging::LOGLEVEL_INFO,"unit test: %s, success",(*iter)->GetName().c_str()); }
		else {
			log::Logging::Log(log::Logging::LOGLEVEL_ERROR,"unit test: %s, ERROR",(*iter)->GetName().c_str()); }
		success &= singleTestSuccess;
	}
	return success;
}

void UnitTestManager::Cleanup() {
	std::vector<toolbot::UnitTest*>::iterator iter = tests.begin();
	for(;iter != tests.end(); ++iter) {
		delete (*iter);}
	tests.clear();
}

}
