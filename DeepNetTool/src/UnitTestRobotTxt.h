/*
 * UnitTestRobotTxt.h
 *
 *  Created on: 03.12.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>

namespace toolbot {

class UnitTestRobotTxt {
private:
	UnitTestRobotTxt();
public:
	virtual ~UnitTestRobotTxt();

public:
	static bool Test(const std::string& robotsTxt);
};

}

