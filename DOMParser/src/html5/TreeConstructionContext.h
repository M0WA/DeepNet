/**
 *
 * @file TreeConstructionContext.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include "OpenElementStack.h"

namespace domparser {

namespace html5 {

/**
 * @brief context for html5 tree construction stage
 * @see domparser::html5::TreeConstruction
 */
class TreeConstructionContext {

public:
	enum InsertionMode {
		initial,
		before_html,
		before_head,
		in_head,
		in_head_noscript,
		after_head,
		in_body,
		text,
		in_table,
		in_table_text,
		in_caption,
		in_column_group,
		in_table_body,
		in_row,
		in_cell,
		in_select,
		in_select_in_table,
		after_body,
		in_frameset,
		after_frameset,
		after_after_body,
		after_after_frameset,
	};

public:
	TreeConstructionContext();
	virtual ~TreeConstructionContext();

public:
	/**
	 * algorithm to "reset the insertion mode appropriately"
	 */
	void ResetMode();

	/**
	 * switches insertion mode
	 * @param newMode insertion mode to switch to
	 */
	void SwitchMode(const TreeConstructionContext::InsertionMode newMode);


private:
	InsertionMode insertionMode;
	InsertionMode orgInsertionMode;

	OpenElementStack openElements;
};

}

}
