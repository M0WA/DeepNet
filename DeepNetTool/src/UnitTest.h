/**
 *
 * @file UnitTest.h
 * @author Moritz Wagner
 * @date Apr 19, 2013
 *
 */

#pragma once

namespace toolbot {

class UnitTest {

protected:
	UnitTest();
public:
	virtual ~UnitTest();

	virtual bool Run()=0;
};

}
