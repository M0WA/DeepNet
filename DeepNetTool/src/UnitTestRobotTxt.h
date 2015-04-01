/**
 *
 * @file UnitTestRobotTxt.h
 * @author Moritz Wagner
 * @date 03.12.2012
 *
 */

#pragma once

#include <string>
#include "UnitTest.h"

namespace toolbot {

/**
 * @brief implements unit tests for parsing robot.txts
 * @see caching::RobotTxt
 */
class UnitTestRobotTxt : public UnitTest {
public:
	UnitTestRobotTxt(const std::string& robotsTxt);
	virtual ~UnitTestRobotTxt();

public:
	virtual bool Run();
	virtual std::string GetName() const { return "UnitTestRobotTxt"; }

private:
	std::string robotsTxt;
};

}

