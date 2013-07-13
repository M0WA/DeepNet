/**
 *
 * @file UnitTestManager.cpp
 * @author Moritz Wagner
 * @date 19.04.2013
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
		log::Logging::LogInfo("unit test: %s, starting",(*iter)->GetName().c_str());
		bool singleTestSuccess = (*iter)->Run();
		if(singleTestSuccess) {
			log::Logging::LogInfo("unit test: %s, success",(*iter)->GetName().c_str());
			successTests.push_back(*iter);
		}
		else {
			log::Logging::LogError("unit test: %s, ERROR",(*iter)->GetName().c_str());
			errorTests.push_back(*iter);
		}
		success &= singleTestSuccess;
	}
	return success;
}

void UnitTestManager::Cleanup() {
	successTests.clear();
	errorTests.clear();

	std::vector<toolbot::UnitTest*>::iterator iter = tests.begin();
	for(;iter != tests.end(); ++iter) {
		delete (*iter);}
	tests.clear();
}

}
