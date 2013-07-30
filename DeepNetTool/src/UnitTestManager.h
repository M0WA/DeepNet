/**
 *
 * @file UnitTestManager.h
 * @author Moritz Wagner
 * @date 19.04.2013
 *
 */

#pragma once

#include <vector>

namespace toolbot {

class UnitTest;

/**
 * @brief class to run multiple toolbot::UnitTest in sequence
 */
class UnitTestManager {
public:
	UnitTestManager();
	virtual ~UnitTestManager();

	/**
	 * schedules a toolbot::UnitTest to run.
	 * all unit tests are cleaned up on finish automatically.
	 * @param unitTest unittest to run
	 */
	void AddUnitTest(toolbot::UnitTest* unitTest);


	/**
	 * runs all previously scheduled unit tests.
	 * log will tell more details about errors.
	 * @return true if all unit tests succeeded, else false
	 */
	bool Run();

private:
	void Cleanup();

private:
	std::vector<toolbot::UnitTest*> tests;
	std::vector<toolbot::UnitTest*> successTests;
	std::vector<toolbot::UnitTest*> errorTests;
};

}
