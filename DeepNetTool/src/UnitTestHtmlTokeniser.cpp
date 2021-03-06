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
: domparser::html5::Tokeniser(dynamic_cast<domparser::DocumentFactory&>(factory)){
}

UnitTestHtmlTokeniser::~UnitTestHtmlTokeniser() {
}

void UnitTestHtmlTokeniser::EmitCharacter(const char charToEmit) {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting character");
	domparser::html5::Tokeniser::EmitCharacter(charToEmit);
}

void UnitTestHtmlTokeniser::EmitComment() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting comment");

	domparser::html5::Tokeniser::EmitComment();
}

void UnitTestHtmlTokeniser::EmitTag() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting tag");

	domparser::html5::Tokeniser::EmitTag();
}

void UnitTestHtmlTokeniser::EmitDocType() {

	log::Logging::LogTrace(GetLineColumnString() + " emmiting DOCTYPE");

	domparser::html5::Tokeniser::EmitDocType();
}

void UnitTestHtmlTokeniser::SwitchState(const domparser::html5::TokeniserState& newState) {

	log::Logging::LogTrace(GetLineColumnString() + " switch state: " + NameFromState(state) + " => " + NameFromState(newState));

	domparser::html5::Tokeniser::SwitchState(newState);
}

void UnitTestHtmlTokeniser::ParseError() const {

	log::Logging::LogTrace(GetLineColumnString() + " tokeniser error");

	domparser::html5::Tokeniser::ParseError();
}

std::string UnitTestHtmlTokeniser::NameFromState(const domparser::html5::TokeniserState& stateIn) {

	switch(stateIn) {
	case domparser::html5::Data_state:
	    return "Data_state";
	case domparser::html5::Character_reference_in_data_state:
	    return "Character_reference_in_data_state";
	case domparser::html5::RCDATA_state:
	    return "RCDATA_state";
	case domparser::html5::Character_reference_in_RCDATA_state:
	    return "Character_reference_in_RCDATA_state";
	case domparser::html5::RAWTEXT_state:
	    return "RAWTEXT_state";
	case domparser::html5::Script_data_state:
	    return "Script_data_state";
	case domparser::html5::PLAINTEXT_state:
	    return "PLAINTEXT_state";
	case domparser::html5::Tag_open_state:
	    return "Tag_open_state";
	case domparser::html5::End_tag_open_state:
	    return "End_tag_open_state";
	case domparser::html5::Tag_name_state:
	    return "Tag_name_state";
	case domparser::html5::RCDATA_less_than_sign_state:
	    return "RCDATA_less_than_sign_state";
	case domparser::html5::RCDATA_end_tag_open_state:
	    return "RCDATA_end_tag_open_state";
	case domparser::html5::RCDATA_end_tag_name_state:
	    return "RCDATA_end_tag_name_state";
	case domparser::html5::RAWTEXT_less_than_sign_state:
	    return "RAWTEXT_less_than_sign_state";
	case domparser::html5::RAWTEXT_end_tag_open_state:
	    return "RAWTEXT_end_tag_open_state";
	case domparser::html5::RAWTEXT_end_tag_name_state:
	    return "RAWTEXT_end_tag_name_state";
	case domparser::html5::Script_data_less_than_sign_state:
	    return "Script_data_less_than_sign_state";
	case domparser::html5::Script_data_end_tag_open_state:
	    return "Script_data_end_tag_open_state";
	case domparser::html5::Script_data_end_tag_name_state:
	    return "Script_data_end_tag_name_state";
	case domparser::html5::Script_data_escape_start_state:
	    return "Script_data_escape_start_state";
	case domparser::html5::Script_data_escape_start_dash_state:
	    return "Script_data_escape_start_dash_state";
	case domparser::html5::Script_data_escaped_state:
	    return "Script_data_escaped_state";
	case domparser::html5::Script_data_escaped_dash_state:
	    return "Script_data_escaped_dash_state";
	case domparser::html5::Script_data_escaped_dash_dash_state:
	    return "Script_data_escaped_dash_dash_state";
	case domparser::html5::Script_data_escaped_less_than_sign_state:
	    return "Script_data_escaped_less_than_sign_state";
	case domparser::html5::Script_data_escaped_end_tag_open_state:
	    return "Script_data_escaped_end_tag_open_state";
	case domparser::html5::Script_data_escaped_end_tag_name_state:
	    return "Script_data_escaped_end_tag_name_state";
	case domparser::html5::Script_data_double_escape_start_state:
	    return "Script_data_double_escape_start_state";
	case domparser::html5::Script_data_double_escaped_state:
	    return "Script_data_double_escaped_state";
	case domparser::html5::Script_data_double_escaped_dash_state:
	    return "Script_data_double_escaped_dash_state";
	case domparser::html5::Script_data_double_escaped_dash_dash_state:
	    return "Script_data_double_escaped_dash_dash_state";
	case domparser::html5::Script_data_double_escaped_less_than_sign_state:
	    return "Script_data_double_escaped_less_than_sign_state";
	case domparser::html5::Script_data_double_escape_end_state:
	    return "Script_data_double_escape_end_state";
	case domparser::html5::Before_attribute_name_state:
	    return "Before_attribute_name_state";
	case domparser::html5::Attribute_name_state:
	    return "Attribute_name_state";
	case domparser::html5::After_attribute_name_state:
	    return "After_attribute_name_state";
	case domparser::html5::Before_attribute_value_state:
	    return "Before_attribute_value_state";
	case domparser::html5::Attribute_value__double_quoted__state:
	    return "Attribute_value__double_quoted__state";
	case domparser::html5::Attribute_value__single_quoted__state:
	    return "Attribute_value__single_quoted__state";
	case domparser::html5::Attribute_value__unquoted__state:
	    return "Attribute_value__unquoted__state";
	case domparser::html5::Character_reference_in_attribute_value_state:
	    return "Character_reference_in_attribute_value_state";
	case domparser::html5::After_attribute_value__quoted__state:
	    return "After_attribute_value__quoted__state";
	case domparser::html5::Self_closing_start_tag_state:
	    return "Self_closing_start_tag_state";
	case domparser::html5::Bogus_comment_state:
	    return "Bogus_comment_state";
	case domparser::html5::Markup_declaration_open_state:
	    return "Markup_declaration_open_state";
	case domparser::html5::Comment_start_state:
	    return "Comment_start_state";
	case domparser::html5::Comment_start_dash_state:
	    return "Comment_start_dash_state";
	case domparser::html5::Comment_state:
	    return "Comment_state";
	case domparser::html5::Comment_end_dash_state:
	    return "Comment_end_dash_state";
	case domparser::html5::Comment_end_state:
	    return "Comment_end_state";
	case domparser::html5::Comment_end_bang_state:
	    return "Comment_end_bang_state";
	case domparser::html5::DOCTYPE_state:
	    return "DOCTYPE_state";
	case domparser::html5::Before_DOCTYPE_name_state:
	    return "Before_DOCTYPE_name_state";
	case domparser::html5::DOCTYPE_name_state:
	    return "DOCTYPE_name_state";
	case domparser::html5::After_DOCTYPE_name_state:
	    return "After_DOCTYPE_name_state";
	case domparser::html5::After_DOCTYPE_public_keyword_state:
	    return "After_DOCTYPE_public_keyword_state";
	case domparser::html5::Before_DOCTYPE_public_identifier_state:
	    return "Before_DOCTYPE_public_identifier_state";
	case domparser::html5::DOCTYPE_public_identifier__double_quoted__state:
	    return "DOCTYPE_public_identifier__double_quoted__state";
	case domparser::html5::DOCTYPE_public_identifier__single_quoted__state:
	    return "DOCTYPE_public_identifier__single_quoted__state";
	case domparser::html5::After_DOCTYPE_public_identifier_state:
	    return "After_DOCTYPE_public_identifier_state";
	case domparser::html5::Between_DOCTYPE_public_and_system_identifiers_state:
	    return "Between_DOCTYPE_public_and_system_identifiers_state";
	case domparser::html5::After_DOCTYPE_system_keyword_state:
	    return "After_DOCTYPE_system_keyword_state";
	case domparser::html5::Before_DOCTYPE_system_identifier_state:
	    return "Before_DOCTYPE_system_identifier_state";
	case domparser::html5::DOCTYPE_system_identifier__double_quoted__state:
	    return "DOCTYPE_system_identifier__double_quoted__state";
	case domparser::html5::DOCTYPE_system_identifier__single_quoted__state:
	    return "DOCTYPE_system_identifier__single_quoted__state";
	case domparser::html5::After_DOCTYPE_system_identifier_state:
	    return "After_DOCTYPE_system_identifier_state";
	case domparser::html5::Bogus_DOCTYPE_state:
	    return "Bogus_DOCTYPE_state";
	case domparser::html5::CDATA_section_state:
	    return "CDATA_section_state";

	default:
		return "UNKNOWN_TOKENISER_STATE";
	}
}


}
