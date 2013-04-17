/*
 * UnitTestRobotTxt.cpp
 *
 *  Created on: 03.12.2012
 *      Author: Moritz Wagner
 */

#include "UnitTestRobotTxt.h"

#include <RobotTxt.h>

namespace toolbot {

UnitTestRobotTxt::UnitTestRobotTxt() {
}

UnitTestRobotTxt::~UnitTestRobotTxt() {
}

bool UnitTestRobotTxt::Test(const std::string& robotsTxt) {

	caching::RobotTxt txt(-1,-1,-1);
	txt.Load(robotsTxt);

	std::string generatedRobotsTxt = txt.ToString();
	//TODO: compare generated robots.txt against pre-loaded result
	return false;
}

}
