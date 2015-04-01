/**
 *
 * @file TreeConstruction.h
 * @author Moritz Wagner
 * @date 20.06.2013
 *
 */

#pragma once

#include "TreeConstructionContext.h"
#include "../generic/TreeConstructionBase.h"

namespace domparser {

namespace html5 {

/**
 * @brief tree construction class form HTML5
 * @see http://www.w3.org/TR/2008/WD-html5-20080610/parsing.html#parse
 * @see http://www.w3.org/TR/2008/WD-html5-20080610/dom.html
 */
class TreeConstruction : public domparser::generic::TreeConstructionBase {
protected:

public:
	TreeConstruction();
	virtual ~TreeConstruction();

public:
	virtual bool OnToken(const domparser::generic::Token& token);

private:
	//rules
	void UsingRulesForInsertionMode(const TreeConstructionContext::InsertionMode useMode,const domparser::generic::Token& token);

private:
	TreeConstructionContext context;
};

}

}

