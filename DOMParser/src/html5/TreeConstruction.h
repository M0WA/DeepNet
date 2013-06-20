/**
 *
 * @file TreeConstruction.h
 * @author Moritz Wagner
 * @date 20.06.2013
 *
 */

#pragma once

#include "../generic/TreeConstructionBase.h"

namespace domparser {

namespace html5 {

class TreeConstruction : public domparser::generic::TreeConstructionBase {
protected:
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
	TreeConstruction();
	virtual ~TreeConstruction();

public:
	virtual bool OnToken(const Token& token);

private:
	//rules
	void ResetInsertionMode();

private:
	void SwitchMode(const InsertionMode newMode);

private:
	InsertionMode insertionMode;
	InsertionMode orgInsertionMode;
};

}

}
