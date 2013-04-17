/**
 *
 * @file UnitTestHtmlTokeniser.cpp
 * @author Moritz Wagner
 * @date Mar 9, 2013
 *
 * TODO: description for this file
 *
 */

#include "UnitTestHtmlTokeniser.h"

#include <Logging.h>

#include "UnitTestHtmlDocumentFactory.h"

namespace toolbot {

UnitTestHtmlTokeniser::UnitTestHtmlTokeniser(UnitTestHtmlDocumentFactory& factory)
: htmlparser::Tokeniser(dynamic_cast<htmlparser::DocumentFactory&>(factory)){
}

UnitTestHtmlTokeniser::~UnitTestHtmlTokeniser() {
}

void UnitTestHtmlTokeniser::EmitCharacter() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting character");
	htmlparser::Tokeniser::EmitCharacter();
}

void UnitTestHtmlTokeniser::EmitComment() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting comment");

	htmlparser::Tokeniser::EmitComment();
}

void UnitTestHtmlTokeniser::EmitTag() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting tag");

	htmlparser::Tokeniser::EmitTag();
}

void UnitTestHtmlTokeniser::EmitDocType() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting DOCTYPE");

	htmlparser::Tokeniser::EmitDocType();
}

void UnitTestHtmlTokeniser::SwitchState(const htmlparser::TokeniserState& newState) {

	log::Logging::LogTrace(GetLineColumnString() + " switch state: " + NameFromState(state) + " => " + NameFromState(newState));

	htmlparser::Tokeniser::SwitchState(newState);
}

void UnitTestHtmlTokeniser::ParseError() const {

	log::Logging::LogTrace(GetLineColumnString() + " tokeniser error");

	htmlparser::Tokeniser::ParseError();
}

std::string UnitTestHtmlTokeniser::NameFromState(const htmlparser::TokeniserState& stateIn) {

	switch(stateIn) {
	case htmlparser::Data_state:
	    return "Data_state";
	case htmlparser::Character_reference_in_data_state:
	    return "Character_reference_in_data_state";
	case htmlparser::RCDATA_state:
	    return "RCDATA_state";
	case htmlparser::Character_reference_in_RCDATA_state:
	    return "Character_reference_in_RCDATA_state";
	case htmlparser::RAWTEXT_state:
	    return "RAWTEXT_state";
	case htmlparser::Script_data_state:
	    return "Script_data_state";
	case htmlparser::PLAINTEXT_state:
	    return "PLAINTEXT_state";
	case htmlparser::Tag_open_state:
	    return "Tag_open_state";
	case htmlparser::End_tag_open_state:
	    return "End_tag_open_state";
	case htmlparser::Tag_name_state:
	    return "Tag_name_state";
	case htmlparser::RCDATA_less_than_sign_state:
	    return "RCDATA_less_than_sign_state";
	case htmlparser::RCDATA_end_tag_open_state:
	    return "RCDATA_end_tag_open_state";
	case htmlparser::RCDATA_end_tag_name_state:
	    return "RCDATA_end_tag_name_state";
	case htmlparser::RAWTEXT_less_than_sign_state:
	    return "RAWTEXT_less_than_sign_state";
	case htmlparser::RAWTEXT_end_tag_open_state:
	    return "RAWTEXT_end_tag_open_state";
	case htmlparser::RAWTEXT_end_tag_name_state:
	    return "RAWTEXT_end_tag_name_state";
	case htmlparser::Script_data_less_than_sign_state:
	    return "Script_data_less_than_sign_state";
	case htmlparser::Script_data_end_tag_open_state:
	    return "Script_data_end_tag_open_state";
	case htmlparser::Script_data_end_tag_name_state:
	    return "Script_data_end_tag_name_state";
	case htmlparser::Script_data_escape_start_state:
	    return "Script_data_escape_start_state";
	case htmlparser::Script_data_escape_start_dash_state:
	    return "Script_data_escape_start_dash_state";
	case htmlparser::Script_data_escaped_state:
	    return "Script_data_escaped_state";
	case htmlparser::Script_data_escaped_dash_state:
	    return "Script_data_escaped_dash_state";
	case htmlparser::Script_data_escaped_dash_dash_state:
	    return "Script_data_escaped_dash_dash_state";
	case htmlparser::Script_data_escaped_less_than_sign_state:
	    return "Script_data_escaped_less_than_sign_state";
	case htmlparser::Script_data_escaped_end_tag_open_state:
	    return "Script_data_escaped_end_tag_open_state";
	case htmlparser::Script_data_escaped_end_tag_name_state:
	    return "Script_data_escaped_end_tag_name_state";
	case htmlparser::Script_data_double_escape_start_state:
	    return "Script_data_double_escape_start_state";
	case htmlparser::Script_data_double_escaped_state:
	    return "Script_data_double_escaped_state";
	case htmlparser::Script_data_double_escaped_dash_state:
	    return "Script_data_double_escaped_dash_state";
	case htmlparser::Script_data_double_escaped_dash_dash_state:
	    return "Script_data_double_escaped_dash_dash_state";
	case htmlparser::Script_data_double_escaped_less_than_sign_state:
	    return "Script_data_double_escaped_less_than_sign_state";
	case htmlparser::Script_data_double_escape_end_state:
	    return "Script_data_double_escape_end_state";
	case htmlparser::Before_attribute_name_state:
	    return "Before_attribute_name_state";
	case htmlparser::Attribute_name_state:
	    return "Attribute_name_state";
	case htmlparser::After_attribute_name_state:
	    return "After_attribute_name_state";
	case htmlparser::Before_attribute_value_state:
	    return "Before_attribute_value_state";
	case htmlparser::Attribute_value__double_quoted__state:
	    return "Attribute_value__double_quoted__state";
	case htmlparser::Attribute_value__single_quoted__state:
	    return "Attribute_value__single_quoted__state";
	case htmlparser::Attribute_value__unquoted__state:
	    return "Attribute_value__unquoted__state";
	case htmlparser::Character_reference_in_attribute_value_state:
	    return "Character_reference_in_attribute_value_state";
	case htmlparser::After_attribute_value__quoted__state:
	    return "After_attribute_value__quoted__state";
	case htmlparser::Self_closing_start_tag_state:
	    return "Self_closing_start_tag_state";
	case htmlparser::Bogus_comment_state:
	    return "Bogus_comment_state";
	case htmlparser::Markup_declaration_open_state:
	    return "Markup_declaration_open_state";
	case htmlparser::Comment_start_state:
	    return "Comment_start_state";
	case htmlparser::Comment_start_dash_state:
	    return "Comment_start_dash_state";
	case htmlparser::Comment_state:
	    return "Comment_state";
	case htmlparser::Comment_end_dash_state:
	    return "Comment_end_dash_state";
	case htmlparser::Comment_end_state:
	    return "Comment_end_state";
	case htmlparser::Comment_end_bang_state:
	    return "Comment_end_bang_state";
	case htmlparser::DOCTYPE_state:
	    return "DOCTYPE_state";
	case htmlparser::Before_DOCTYPE_name_state:
	    return "Before_DOCTYPE_name_state";
	case htmlparser::DOCTYPE_name_state:
	    return "DOCTYPE_name_state";
	case htmlparser::After_DOCTYPE_name_state:
	    return "After_DOCTYPE_name_state";
	case htmlparser::After_DOCTYPE_public_keyword_state:
	    return "After_DOCTYPE_public_keyword_state";
	case htmlparser::Before_DOCTYPE_public_identifier_state:
	    return "Before_DOCTYPE_public_identifier_state";
	case htmlparser::DOCTYPE_public_identifier__double_quoted__state:
	    return "DOCTYPE_public_identifier__double_quoted__state";
	case htmlparser::DOCTYPE_public_identifier__single_quoted__state:
	    return "DOCTYPE_public_identifier__single_quoted__state";
	case htmlparser::After_DOCTYPE_public_identifier_state:
	    return "After_DOCTYPE_public_identifier_state";
	case htmlparser::Between_DOCTYPE_public_and_system_identifiers_state:
	    return "Between_DOCTYPE_public_and_system_identifiers_state";
	case htmlparser::After_DOCTYPE_system_keyword_state:
	    return "After_DOCTYPE_system_keyword_state";
	case htmlparser::Before_DOCTYPE_system_identifier_state:
	    return "Before_DOCTYPE_system_identifier_state";
	case htmlparser::DOCTYPE_system_identifier__double_quoted__state:
	    return "DOCTYPE_system_identifier__double_quoted__state";
	case htmlparser::DOCTYPE_system_identifier__single_quoted__state:
	    return "DOCTYPE_system_identifier__single_quoted__state";
	case htmlparser::After_DOCTYPE_system_identifier_state:
	    return "After_DOCTYPE_system_identifier_state";
	case htmlparser::Bogus_DOCTYPE_state:
	    return "Bogus_DOCTYPE_state";
	case htmlparser::CDATA_section_state:
	    return "CDATA_section_state";

	default:
		return "UNKNOWN_TOKENISER_STATE";
	}
}


}
