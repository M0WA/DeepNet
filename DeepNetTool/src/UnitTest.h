/**
 *
 * @file UnitTest.h
 * @author Moritz Wagner
 * @date Apr 19, 2013
 *
 */

#pragma once

#include <string>

namespace toolbot {

/**
 * @brief base class for all unit tests
 * used in conjuction with toolbot::UnitTestManager
 * @see toolbot::UnitTestManager::AddUnitTest
 */
class UnitTest {

protected:
	UnitTest();
public:
	virtual ~UnitTest();

	/**
	 * called when unit test should run.
	 * @return true if successful, false if an error occurred.
	 */
	virtual bool Run()=0;

	/**
	 * gets name of the unit test derived from this class
	 * @return name of unit test
	 */
	virtual std::string GetName() const =0;
};

}
