/**
 *
 * @file TreeConstructionBase.h
 * @author Moritz Wagner
 * @date 20.06.2013
 *
 */

#pragma once

namespace domparser {

namespace generic {

class Token;

class TreeConstructionBase {

protected:
	TreeConstructionBase();
public:
	virtual ~TreeConstructionBase();

public:
	virtual bool OnToken(const domparser::generic::Token& token) = 0;
};

}

}
