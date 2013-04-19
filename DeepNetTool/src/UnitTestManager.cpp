/**
 *
 * @file UnitTestManager.cpp
 * @author Moritz Wagner
 * @date Apr 19, 2013
 *
 */

#include "UnitTestManager.h"

#include "UnitTest.h"

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
		success &= (*iter)->Run(); }
	return success;
}

void UnitTestManager::Cleanup() {
	std::vector<toolbot::UnitTest*>::iterator iter = tests.begin();
	for(;iter != tests.end(); ++iter) {
		delete (*iter);}
	tests.clear();
}

}
