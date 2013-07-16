/**
 *
 * @file UnitTestRobotTxt.cpp
 * @author Moritz Wagner
 * @date 03.12.2012
 *
 */

#include "UnitTestRobotTxt.h"

#include <RobotTxt.h>

namespace toolbot {

UnitTestRobotTxt::UnitTestRobotTxt(const std::string& robotsTxt)
: robotsTxt(robotsTxt){
}

UnitTestRobotTxt::~UnitTestRobotTxt() {
}

bool UnitTestRobotTxt::Run() {

	caching::RobotTxt txt(-1,-1,-1);
	txt.Load(robotsTxt);

	std::string generatedRobotsTxt = txt.ToString();
	//TODO: compare generated robots.txt against pre-loaded result
	return false;
}

}
