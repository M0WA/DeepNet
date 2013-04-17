/**
 *
 * @file TokeniserState.h
 * @author Moritz Wagner
 * @date 02.03.2013
 *
 * contains all states from current html standard.
 * http://www.w3.org/TR/2011/WD-html5-20110405/tokenization.html
 *
 */

#pragma once

namespace htmlparser {

/**
 * @enum TokeniserState
 * @brief standard compliant tokeniser states.
 * see http://www.w3.org/TR/2011/WD-html5-20110405/tokenization.html.
 */
enum TokeniserState {
	Data_state,                                         //!< Data_state
	Character_reference_in_data_state,                  //!< Character_reference_in_data_state
	RCDATA_state,                                       //!< RCDATA_state
	Character_reference_in_RCDATA_state,                //!< Character_reference_in_RCDATA_state
	RAWTEXT_state,                                      //!< RAWTEXT_state
	Script_data_state,                                  //!< Script_data_state
	PLAINTEXT_state,                                    //!< PLAINTEXT_state
	Tag_open_state,                                     //!< Tag_open_state
	End_tag_open_state,                                 //!< End_tag_open_state
	Tag_name_state,                                     //!< Tag_name_state
	RCDATA_less_than_sign_state,                        //!< RCDATA_less_than_sign_state
	RCDATA_end_tag_open_state,                          //!< RCDATA_end_tag_open_state
	RCDATA_end_tag_name_state,                          //!< RCDATA_end_tag_name_state
	RAWTEXT_less_than_sign_state,                       //!< RAWTEXT_less_than_sign_state
	RAWTEXT_end_tag_open_state,                         //!< RAWTEXT_end_tag_open_state
	RAWTEXT_end_tag_name_state,                         //!< RAWTEXT_end_tag_name_state
	Script_data_less_than_sign_state,                   //!< Script_data_less_than_sign_state
	Script_data_end_tag_open_state,                     //!< Script_data_end_tag_open_state
	Script_data_end_tag_name_state,                     //!< Script_data_end_tag_name_state
	Script_data_escape_start_state,                     //!< Script_data_escape_start_state
	Script_data_escape_start_dash_state,                //!< Script_data_escape_start_dash_state
	Script_data_escaped_state,                          //!< Script_data_escaped_state
	Script_data_escaped_dash_state,                     //!< Script_data_escaped_dash_state
	Script_data_escaped_dash_dash_state,                //!< Script_data_escaped_dash_dash_state
	Script_data_escaped_less_than_sign_state,           //!< Script_data_escaped_less_than_sign_state
	Script_data_escaped_end_tag_open_state,             //!< Script_data_escaped_end_tag_open_state
	Script_data_escaped_end_tag_name_state,             //!< Script_data_escaped_end_tag_name_state
	Script_data_double_escape_start_state,              //!< Script_data_double_escape_start_state
	Script_data_double_escaped_state,                   //!< Script_data_double_escaped_state
	Script_data_double_escaped_dash_state,              //!< Script_data_double_escaped_dash_state
	Script_data_double_escaped_dash_dash_state,         //!< Script_data_double_escaped_dash_dash_state
	Script_data_double_escaped_less_than_sign_state,    //!< Script_data_double_escaped_less_than_sign_state
	Script_data_double_escape_end_state,                //!< Script_data_double_escape_end_state
	Before_attribute_name_state,                        //!< Before_attribute_name_state
	Attribute_name_state,                               //!< Attribute_name_state
	After_attribute_name_state,                         //!< After_attribute_name_state
	Before_attribute_value_state,                       //!< Before_attribute_value_state
	Attribute_value__double_quoted__state,              //!< Attribute_value__double_quoted__state
	Attribute_value__single_quoted__state,              //!< Attribute_value__single_quoted__state
	Attribute_value__unquoted__state,                   //!< Attribute_value__unquoted__state
	Character_reference_in_attribute_value_state,       //!< Character_reference_in_attribute_value_state
	After_attribute_value__quoted__state,               //!< After_attribute_value__quoted__state
	Self_closing_start_tag_state,                       //!< Self_closing_start_tag_state
	Bogus_comment_state,                                //!< Bogus_comment_state
	Markup_declaration_open_state,                      //!< Markup_declaration_open_state
	Comment_start_state,                                //!< Comment_start_state
	Comment_start_dash_state,                           //!< Comment_start_dash_state
	Comment_state,                                      //!< Comment_state
	Comment_end_dash_state,                             //!< Comment_end_dash_state
	Comment_end_state,                                  //!< Comment_end_state
	Comment_end_bang_state,                             //!< Comment_end_bang_state
	DOCTYPE_state,                                      //!< DOCTYPE_state
	Before_DOCTYPE_name_state,                          //!< Before_DOCTYPE_name_state
	DOCTYPE_name_state,                                 //!< DOCTYPE_name_state
	After_DOCTYPE_name_state,                           //!< After_DOCTYPE_name_state
	After_DOCTYPE_public_keyword_state,                 //!< After_DOCTYPE_public_keyword_state
	Before_DOCTYPE_public_identifier_state,             //!< Before_DOCTYPE_public_identifier_state
	DOCTYPE_public_identifier__double_quoted__state,    //!< DOCTYPE_public_identifier__double_quoted__state
	DOCTYPE_public_identifier__single_quoted__state,    //!< DOCTYPE_public_identifier__single_quoted__state
	After_DOCTYPE_public_identifier_state,              //!< After_DOCTYPE_public_identifier_state
	Between_DOCTYPE_public_and_system_identifiers_state,//!< Between_DOCTYPE_public_and_system_identifiers_state
	After_DOCTYPE_system_keyword_state,                 //!< After_DOCTYPE_system_keyword_state
	Before_DOCTYPE_system_identifier_state,             //!< Before_DOCTYPE_system_identifier_state
	DOCTYPE_system_identifier__double_quoted__state,    //!< DOCTYPE_system_identifier__double_quoted__state
	DOCTYPE_system_identifier__single_quoted__state,    //!< DOCTYPE_system_identifier__single_quoted__state
	After_DOCTYPE_system_identifier_state,              //!< After_DOCTYPE_system_identifier_state
	Bogus_DOCTYPE_state,                                //!< Bogus_DOCTYPE_state
	CDATA_section_state,                                //!< CDATA_section_state
};

}
