/*
 * UnitTestRobotTxt.h
 *
 *  Created on: 03.12.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include "UnitTest.h"

namespace toolbot {

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

