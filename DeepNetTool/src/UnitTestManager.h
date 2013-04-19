/**
 *
 * @file UnitTestManager.h
 * @author Moritz Wagner
 * @date Apr 19, 2013
 *
 */

#pragma once

#include <vector>

namespace toolbot {

class UnitTest;
class UnitTestManager {
public:
	UnitTestManager();
	virtual ~UnitTestManager();

	void AddUnitTest(toolbot::UnitTest* unitTest);
	bool Run();

private:
	void Cleanup();

private:
	std::vector<toolbot::UnitTest*> tests;
};

}
