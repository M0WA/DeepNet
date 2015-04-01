/**
 *
 * @file Tokeniser.cpp
 * @author Moritz Wagner
 * @date 02.03.2013
 */

#include "Tokeniser.h"

#include <DatabaseLayer.h>
#include <HtmlData.h>
#include <StringTools.h>

#include <DatabaseUrl.h>
#include "../NamedCharacterReferences.h"
#include "../DocumentFactory.h"

namespace domparser {

namespace html5 {

Tokeniser::Tokeniser(DocumentFactory& factory)
: state(Data_state)
, factory(factory)
, next(0)
, start(0)
, end(0)
, charRefInAttribValAddChar(0){
}

Tokeniser::~Tokeniser() {
}

void Tokeniser::ParseError() const {

	factory.ParseError();
}

bool Tokeniser::OnDataState() {

	const char* current = Consume();

	switch(*current) {
	case '&':
		SwitchState(Character_reference_in_data_state);
		break;
	case '<':
		SwitchState(Tag_open_state);
		break;
	default:
		EmitCharacter(current,1);
		break;
	}
	return true;
}

bool Tokeniser::OnCharacterReferenceInDataState() {

	SwitchState(Data_state);
	std::string refString = ConsumeCharacterReference();

	if(refString.empty()) {
		EmitCharacter("&",1);}
	else {
		EmitCharacter(refString.c_str(),refString.length()); }

	return true;
}

bool Tokeniser::OnTagOpenState() {

	const char* current = Consume();

	switch(*current) {

	case '!':
		SwitchState(Markup_declaration_open_state);
		return true;
	case '/':
		SwitchState(End_tag_open_state);
		return true;
	case '?':
		SwitchState(Bogus_comment_state);
		return true;

	default:
		break;
	}

	if(!isalpha(*current)){
		ParseError();
		EmitCharacter("<",1);
		SwitchState(Data_state);
		next--;
		return true; }

	tagToken.tagType = domparser::generic::TagToken::START_TAG;
	tagToken.name = *current;

	SwitchState(Tag_name_state);
	return true;
}

bool Tokeniser::OnMarkupDeclarationOpenState() {

	const char* tmpCur = next;

	if(	strncmp(tmpCur,"--",2) == 0) {
		Consume(2);
		SwitchState(Comment_start_state);
	}
	else if ( strncasecmp(tmpCur,"doctype",7) == 0 ) {
		Consume(7);
		SwitchState(DOCTYPE_state);
	}
	else if( strncmp(tmpCur,"[CDATA[",7) == 0) {
		//TODO:if the current node is not an element in the HTML namespace and the next seven characters are "[CDATA["...
		//     check if element is not in the HTML namespace
		Consume(7);
		SwitchState(CDATA_section_state);
	}
	else {
		ParseError();
		SwitchState(Bogus_comment_state);
	}

	return true;
}

bool Tokeniser::OnEndTagOpenState(){

	const char* current = Consume();

	if(*current == '>') {
		ParseError();
		SwitchState(Data_state);
	}
	else if(!isalpha(*current)) {
		ParseError();
		SwitchState(Bogus_comment_state);
	}
	else {
		tagToken.tagType = domparser::generic::TagToken::END_TAG;
		tagToken.name = *current;
		SwitchState(Tag_name_state);
	}
	return true;
}

bool Tokeniser::OnBogusCommentState(){

	char* tmpCur = next - 1;
	size_t size = 0;
	for(;tmpCur < end; tmpCur++, size++ ) {
		if(*tmpCur == '>') {
			break;
		}
	}

	std::string comment;
	commentToken.comment.append(tmpCur,size);
	EmitComment();
	Consume(size + 1); //consume '>' also

	SwitchState(Data_state);
	return true;
}

bool Tokeniser::OnTagNameState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ' :
		SwitchState(Before_attribute_name_state);
		return true;
	case '/':
		SwitchState(Self_closing_start_tag_state);
		return true;
	case '>':
		SwitchState(Data_state);
		EmitTag();
		return true;

	default:
		break;
	}

	if( isalpha(*current) ) {
		tagToken.name += tolower(*current);
	}
	else {
		tagToken.name += *current;
	}

	return true;
}

bool Tokeniser::OnCommentStartState(){

	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Comment_start_dash_state);
		break;
	case '>':
		EmitComment();
		SwitchState(Data_state);
		break;

	default:
		commentToken.comment += *current;
		SwitchState(Comment_state);
		break;
	}

	return true;
}

bool Tokeniser::OnDoctypeState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\r':
	case '\n':
	case ' ':
		SwitchState(Before_DOCTYPE_name_state);
		break;

	default:
		ParseError();
		next--;
		SwitchState(Before_DOCTYPE_name_state);
		break;
	}

	return true;
}

bool Tokeniser::OnCDataSectionState(){

	SwitchState(Data_state);

	const char* current = next - 1;
	size_t maxSize = end-current;
	size_t i = 0;
	for(size_t i = 0; i < maxSize; i++) {
		if(strncmp(&current[i],"]]>",3) == 0) {
			break;
		}
	}

	if(i) {
		EmitCharacter(current,i);
	}

	Consume(i+3);
	return true;
}

bool Tokeniser::OnBeforeAttributeNameState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '/':
		SwitchState(Self_closing_start_tag_state);
		break;

	case '>':
		EmitTag();
		SwitchState(Data_state);
		break;

	case '"':
	case '\'':
	case '<':
	case '=':
		ParseError();
	default:
		tagToken.curAttrib.Reset();
		tagToken.curAttrib.name += (char)tolower(*current);
		SwitchState(Attribute_name_state);
		break;
	}

	return true;
}

bool Tokeniser::OnSelfClosingStartTagState(){

	const char* current = Consume();

	switch(*current) {
	case '>':
		tagToken.selfClosingFlag = true;
		EmitTag();
		SwitchState(Data_state);
		break;

	default:
		ParseError();
		SwitchState(Before_attribute_name_state);
		next--;
		break;
	}

	return true;
}

bool Tokeniser::OnCommentStartDashState() {

	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Comment_end_state);
		break;

	case '>':
		ParseError();
		EmitComment();
		SwitchState(Data_state);
		break;

	default:
		commentToken.comment += '-';
		commentToken.comment += *current;
		SwitchState(Comment_state);
		break;
	}

	return true;
}

bool Tokeniser::OnCommentState() {

	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Comment_end_dash_state);
		break;

	default:
		commentToken.comment += *current;
		break;
	}

	return true;
}

bool Tokeniser::OnBeforeDoctypeNameState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '>':
		ParseError();
		doctypeToken.Reset();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		break;

	default:
		break;
	}

	doctypeToken.Reset();
	doctypeToken.pName = &doctypeToken.name;
	if(isalpha(*current)) {
		*doctypeToken.pName += (char)tolower(*current);
	}
	else {
		*doctypeToken.pName += *current;
	}

	SwitchState(DOCTYPE_name_state);
	return true;
}

bool Tokeniser::OnAttributeNameState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(After_attribute_name_state);
		return true;

	case '/':
		SwitchState(Self_closing_start_tag_state);
		return true;

	case '=':
		SwitchState(Before_attribute_value_state);
		return true;

	case '>':
		SwitchState(Data_state);
		return true;

	case '"':
	case '\'':
	case '<':
		ParseError();
	default:
		break;
	}

	if(isalpha(*current)) {
		tagToken.curAttrib.name += (char)tolower(*current); }
	else {
		tagToken.curAttrib.name += *current; }

	return true;
}

bool Tokeniser::OnCommentEndDashState() {

	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Comment_end_state);
		break;

	default:
		commentToken.comment += '-';
		commentToken.comment += *current;
		SwitchState(Comment_state);
		break;
	}

	return true;
}

bool Tokeniser::OnDoctypeNameState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(After_DOCTYPE_name_state);
		return true;

	case '>':
		EmitDocType();
		SwitchState(Data_state);
		return true;

	default:
		break;
	}

	if(isalpha(*current)) {
		doctypeToken.name += (char)tolower(*current); }
	else {
		doctypeToken.name += *current; }

	return true;
}

bool Tokeniser::OnAfterAttributeNameState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '/':
		SwitchState(Self_closing_start_tag_state);
		return true;

	case '=':
		SwitchState(Before_attribute_value_state);
		return true;

	case '>':
		SwitchState(Data_state);
		return true;

	case '"':
	case '\'':
	case '<':
		ParseError();
	default:
		break;
	}

	if(!tagToken.name.empty()) {
		tagToken.attributes.push_back(tagToken.curAttrib);}
	tagToken.curAttrib.Reset();

	if(isalpha(*current)) {
		tagToken.curAttrib.name += (char)tolower(*current); }
	else {
		tagToken.curAttrib.name += *current; }


	return true;
}

bool Tokeniser::OnBeforeAttributeValueState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '"':
		SwitchState(Attribute_value__double_quoted__state);
		return true;

	case '\'':
		SwitchState(Attribute_value__single_quoted__state);
		return true;

	case '&':
		SwitchState(Attribute_value__unquoted__state);
		return true;

	case '>':
		SwitchState(Data_state);
		EmitTag();
		return true;

	case '<':
	case '=':
	case '`':
		ParseError();
	default:
		tagToken.curAttrib.value += *current;
		SwitchState(Attribute_value__unquoted__state);
		return true;
	}
}

bool Tokeniser::OnCommentEndState() {

	const char* current = Consume();

	switch(*current) {
	case '>':
		SwitchState(Data_state);
		return true;

	case '!':
		ParseError();
		SwitchState(Comment_end_bang_state);
		return true;

	case '-':
		commentToken.comment += '-';
		return true;

	default:
		commentToken.comment += "--";
		commentToken.comment += *current;
		SwitchState(Comment_state);
		return true;
	}
}

bool Tokeniser::OnAfterDoctypeNameState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '>':
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		break;
	}

	if(end - current < 6 ) {
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}

	std::string tmp;
	tmp.append(current,6);
	tools::StringTools::ToLowerIP(tmp);

	if( tmp.find("public") != std::string::npos ) {
		SwitchState(After_DOCTYPE_public_keyword_state);
		Consume(6);
	}
	else if ( tmp.find("system") != std::string::npos ) {
		SwitchState(After_DOCTYPE_system_keyword_state);
		Consume(6);
	}
	else {
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
	}

	return true;
}

bool Tokeniser::OnAttributeValueDoubleQuotedState() {

	const char* current = Consume();

	switch(*current) {
	case '"':
		SwitchState(After_attribute_value__quoted__state);
		return true;

	case '&':
		charRefInAttribValAddChar = '"';
		preCharRefInAttribState = state;
		SwitchState(Character_reference_in_attribute_value_state);
		return true;

	default:
		tagToken.curAttrib.value += *current;
		return true;
	}
}

bool Tokeniser::OnAttributeValueSingleQuotedState() {

	const char* current = Consume();

	switch(*current) {
	case '"':
		SwitchState(After_attribute_value__quoted__state);
		return true;

	case '&':
		charRefInAttribValAddChar = '\'';
		preCharRefInAttribState = state;
		SwitchState(Character_reference_in_attribute_value_state);
		return true;

	default:
		tagToken.curAttrib.value += *current;
		return true;
	}
}

bool Tokeniser::OnAttributeValueUnquotedState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(Before_attribute_name_state);
		return true;

	case '&':
		charRefInAttribValAddChar = '>';
		preCharRefInAttribState = state;
		SwitchState(Character_reference_in_attribute_value_state);
		return true;

	case '>':
		SwitchState(Data_state);
		EmitTag();
		return true;

	case '"':
	case '\'':
	case '<':
	case '=':
	case '`':
		ParseError();
	default:
		tagToken.curAttrib.value += *current;
		break;
	}
	return false;
}

bool Tokeniser::OnCommentEndBangState() {

	const char* current = Consume();

	switch(*current) {
	case '-':
		commentToken.comment += "--!";
		SwitchState(Comment_end_dash_state);
		return true;

	case '>':
		SwitchState(Data_state);
		EmitComment();
		return true;

	default:
		commentToken.comment += "--!";
		commentToken.comment += *current;
		SwitchState(Comment_state);
		return true;
	}
}

bool Tokeniser::OnBogusDoctypeState() {

	const char* current = Consume();

	switch(*current) {
	case '>':
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		return true;
	}
}

bool Tokeniser::OnAfterDoctypePublicKeywordState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(Before_DOCTYPE_public_identifier_state);
		return true;

	case '"':
		ParseError();
		doctypeToken.pPublicIdentifier = &doctypeToken.public_identifier;
		SwitchState(DOCTYPE_public_identifier__double_quoted__state);
		return true;

	case '\'':
		ParseError();
		doctypeToken.pPublicIdentifier = &doctypeToken.public_identifier;
		SwitchState(DOCTYPE_public_identifier__single_quoted__state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::OnAfterDoctypeSystemKeywordState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(Before_DOCTYPE_system_identifier_state);
		return true;

	case '"':
		ParseError();
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__double_quoted__state);
		return true;

	case '\'':
		ParseError();
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__single_quoted__state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::AfterAttributeValueQuotedState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(Before_attribute_name_state);
		return true;

	case '/':
		SwitchState(Self_closing_start_tag_state);
		return true;

	case '>':
		SwitchState(Data_state);
		EmitTag();
		return true;

	default:
		ParseError();
		next--;
		SwitchState(Before_attribute_name_state);
		return true;
	}
}

bool Tokeniser::CharacterReferenceInAttributeValueState() {

	std::string refString = ConsumeCharacterReference((charRefInAttribValAddChar != 0 ? &charRefInAttribValAddChar : NULL));
	if( refString.empty() ) {
		tagToken.curAttrib.value += '&'; }
	else {
		tagToken.curAttrib.value.append(refString);}

	SwitchState(preCharRefInAttribState);
	return true;
}

bool Tokeniser::OnBeforeDoctypePublicIdentifierState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '"':
		ParseError();
		doctypeToken.pPublicIdentifier = &doctypeToken.public_identifier;
		SwitchState(DOCTYPE_public_identifier__double_quoted__state);
		return true;

	case '\'':
		ParseError();
		doctypeToken.pPublicIdentifier = &doctypeToken.public_identifier;
		SwitchState(DOCTYPE_public_identifier__single_quoted__state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::OnDoctypePublicIdentifierDoubleQuotedState(){

	const char* current = Consume();

	switch(*current) {
	case '"':
		SwitchState(After_DOCTYPE_public_identifier_state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		doctypeToken.public_identifier += *current;
		return true;
	}
}

bool Tokeniser::OnDoctypePublicIdentifierSingleQuotedState(){

	const char* current = Consume();

	switch(*current) {
	case '\'':
		SwitchState(After_DOCTYPE_public_identifier_state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		doctypeToken.public_identifier += *current;
		return true;
	}
}

bool Tokeniser::OnBeforeDoctypeSystemIdentifierState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '"':
		ParseError();
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__double_quoted__state);
		return true;

	case '\'':
		ParseError();
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__single_quoted__state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::OnDoctypeSystemIdentifierDoubleQuotedState(){

	const char* current = Consume();

	switch(*current) {
	case '\"':
		SwitchState(After_DOCTYPE_system_identifier_state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		doctypeToken.system_identifier += *current;
		return true;
	}
}

bool Tokeniser::OnDoctypeSystemIdentifierSingleQuotedState(){

	const char* current = Consume();

	switch(*current) {
	case '\'':
		SwitchState(After_DOCTYPE_system_identifier_state);
		return true;

	case '>':
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		doctypeToken.system_identifier += *current;
		return true;
	}
}

bool Tokeniser::OnAfterDoctypePublicIdentifierState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		SwitchState(Between_DOCTYPE_public_and_system_identifiers_state);
		return true;

	case '>':
		SwitchState(Data_state);
		EmitDocType();
		return true;

	case '"':
		ParseError();
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__double_quoted__state);
		return true;

	case '\'':
		ParseError();
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__single_quoted__state);
		return true;

	default:
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::OnAfterDoctypeSystemIdentifierState(){

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '>':
		SwitchState(Data_state);
		EmitDocType();
		return true;

	default:
		ParseError();
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::OnBetweenDoctypePublicAndSystemIdentifiersState() {

	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		return true;

	case '>':
		SwitchState(Data_state);
		EmitDocType();
		return true;

	case '"':
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__double_quoted__state);
		return true;

	case '\'':
		doctypeToken.pSystemIdentifier = &doctypeToken.system_identifier;
		SwitchState(DOCTYPE_system_identifier__single_quoted__state);
		return true;

	default:
		ParseError();
		doctypeToken.force_quirks = true;
		SwitchState(Bogus_DOCTYPE_state);
		return true;
	}
}

bool Tokeniser::OnRCDATAState() {

	const char* current = Consume();

	switch(*current) {
	case '&':
		SwitchState(Character_reference_in_RCDATA_state);
		return true;
	case '<':
		SwitchState(RCDATA_less_than_sign_state);
		return true;

	default:
		EmitCharacter(current,1);
		return true;
	}
}

bool Tokeniser::OnCharacterReferenceInRCDATAState() {

	SwitchState(RCDATA_state);
	std::string refString = ConsumeCharacterReference();

	if(refString.empty()) {
		EmitCharacter("&",1); }
	else {
		EmitCharacter(refString.c_str(),refString.length()); }

	return true;
}

bool Tokeniser::OnRCDATALessThanSignState() {

	const char* current = Consume();

	switch(*current) {
	case '/':
		temporaryBuffer.clear();
		SwitchState(RCDATA_end_tag_open_state);
		return true;
	default:
		SwitchState(RCDATA_state);
		EmitCharacter("<",1);
		next--;
		return true;
	}
}

bool Tokeniser::OnRCDATAEndTagOpenState() {

	const char* current = Consume();

	if(isalpha(*current)) {
		tagToken.Reset();
		tagToken.name += tolower(*current);
		tagToken.tagType = domparser::generic::TagToken::END_TAG;
		temporaryBuffer += *current;
		SwitchState(RCDATA_end_tag_name_state);
	}
	else {
		SwitchState(RCDATA_state);
		EmitCharacter("</",2);
		next--;
	}

	return true;
}

bool Tokeniser::OnRCDATAEndTagNameState() {

	const char* current = Consume();

	if(isalpha(*current)) {
		tagToken.name += tolower(*current);
		temporaryBuffer += *current;
		return true; }

	switch(*current) {

	case '\t':
	case '\n':
	case '\r':
	case ' ':
		if(IsAppropriateEndTag()) {
			SwitchState(Before_attribute_name_state);
			return true;
		}
		break;

	case '/':
		if(IsAppropriateEndTag()) {
			SwitchState(Self_closing_start_tag_state);
			return true;
		}
		break;

	case '>':
		if(IsAppropriateEndTag()) {
			SwitchState(Data_state);
			return true;
		}
		break;

	default:
		break;
	}

	SwitchState(RCDATA_state);
	EmitCharacter("</",2);
	EmitCharacter(temporaryBuffer.c_str(),temporaryBuffer.length());
	next--;
	return true;
}

bool Tokeniser::OnScriptDataState() {

	const char* current = Consume();

	switch(*current) {
	case '<':
		SwitchState(Script_data_less_than_sign_state);
		return true;

	default:
		EmitCharacter(current,1);
		return true;
	}
}

bool Tokeniser::OnScriptDataLessThanSignState() {

	const char* current = Consume();

	switch(*current) {

	case '/':
		temporaryBuffer.clear();
		SwitchState(Script_data_end_tag_open_state);
		return true;

	case '!':
		SwitchState(Script_data_escape_start_state);
		EmitCharacter("<!",2);
		return true;

	default:
		SwitchState(Script_data_state);
		EmitCharacter("<");
		next--;
		return true;
	}
}

bool Tokeniser::OnScriptDataEndTagOpenState() {

	const char* current = Consume();
	if(isalpha(*current)) {
		tagToken.Reset();
		tagToken.tagType = domparser::generic::TagToken::END_TAG;
		tagToken.name += tolower(*current);
		temporaryBuffer += *current;
		SwitchState(Script_data_end_tag_name_state);
	}
	else {
		SwitchState(Script_data_state);
		EmitCharacter("</",2);
		next--;
	}

	return true;
}

bool Tokeniser::OnScriptDataEndTagNameState() {

	const char* current = Consume();

	if(isalpha(*current)) {
		tagToken.name += tolower(*current);
		temporaryBuffer += *current;
		return true; }

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':
		if(IsAppropriateEndTag()) {
			SwitchState(Before_attribute_name_state);
			return true; }
		break;

	case '/':
		if(IsAppropriateEndTag()) {
			SwitchState(Self_closing_start_tag_state);
			return true; }
		break;

	case '>':
		if(IsAppropriateEndTag()) {
			SwitchState(Data_state);
			return true; }
		break;

	default:
		break;
	}

	SwitchState(Script_data_state);
	EmitCharacter("</",2);
	EmitCharacter(temporaryBuffer.c_str(),temporaryBuffer.length());
	next--;
	return true;
}

bool Tokeniser::OnScriptDataEscapeStartState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Script_data_escape_start_dash_state);
		EmitCharacter(*current);
		return true;

	default:
		SwitchState(Script_data_state);
		next--;
		return true;
	}
}

bool Tokeniser::OnScriptDataEscapeStartDashState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Script_data_escaped_dash_dash_state);
  		EmitCharacter(*current);
		return true;

	default:
		SwitchState(Script_data_state);
		next--;
		return true;
	}
}

bool Tokeniser::OnScriptDataEscapedDashDashState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		EmitCharacter(current,1);
		return true;

	case '<':
		SwitchState(Script_data_escaped_less_than_sign_state);
		return true;

	case '>':
		SwitchState(Script_data_state);
		EmitCharacter(current,1);
		return true;

	default:
		SwitchState(Script_data_escaped_state);
		EmitCharacter(current,1);
		return true;
	}
}

bool Tokeniser::OnScriptDataEscapedLessThanSignState() {

	const char* current = Consume();

	switch(*current) {
	case '/':
		SwitchState(Script_data_escaped_end_tag_open_state);
		temporaryBuffer.clear();
		return true;

	default:
		break;
	}

	if(std::isalpha(*current)) {
		temporaryBuffer = std::tolower(*current);
		SwitchState(Script_data_double_escape_start_state);
		EmitCharacter('<');
		EmitCharacter(current,1);
	}
	else {
		SwitchState(Script_data_escaped_state);
		EmitCharacter('<');
		next--;
	}

	return true;
}

bool Tokeniser::OnScriptDataEscapedState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Script_data_escaped_dash_state);
		return true;

	case '<':
		SwitchState(Script_data_escaped_less_than_sign_state);
		return true;

	default:
		EmitCharacter(current);
		return true;
	}
}

bool Tokeniser::OnScriptDataEscapedDashState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Script_data_escaped_dash_state);
		EmitCharacter(*current);
		return true;

	case '<':
		SwitchState(Script_data_escaped_less_than_sign_state);
		return true;

	default:
		SwitchState(Script_data_escaped_state);
		EmitCharacter(*current);
		return true;
	}
}

bool Tokeniser::OnScriptDataEscapedEndTagOpenState() {
	const char* current = Consume();

	if(std::isalpha(*current)) {
		tagToken.tagType = domparser::generic::TagToken::END_TAG;
		tagToken.name = std::tolower(*current);
		temporaryBuffer += *current;
		SwitchState(Script_data_end_tag_name_state);
	}
	else {
		SwitchState(Script_data_state);
		EmitCharacter("</",2);
		next--;
	}

	return true;
}

bool Tokeniser::OnScriptDataEscapedEndTagNameState() {
	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case  ' ':
		if(IsAppropriateEndTag()) {
			SwitchState(Before_attribute_name_state);
			return true; }
		break;

	case '/':
		if(IsAppropriateEndTag()) {
			SwitchState(Self_closing_start_tag_state);
			return true; }
		break;

	case '>':
		if(IsAppropriateEndTag()) {
			SwitchState(Data_state);
			return true; }
		break;

	default:
		break;
	}

	if(std::isalpha(*current)) {
		tagToken.name += std::tolower(*current);
		temporaryBuffer += *current;
	}
	else {
		SwitchState(Script_data_escaped_state);
		EmitCharacter("</",2);
		EmitCharacter(temporaryBuffer.c_str(),temporaryBuffer.length());
		next--;
	}

	return true;
}

bool Tokeniser::OnScriptDataDoubleEscapeStartState() {
	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case  ' ':
	case  '/':
	case  '>':
		if(temporaryBuffer.compare("script") == 0) {
			SwitchState(Script_data_double_escaped_state); }
		else {
			SwitchState(Script_data_escaped_state);	}
		EmitCharacter(*current);
		return true;

	default:
		break;
	}

	if(std::isalpha(*current)) {
		temporaryBuffer += std::tolower(*current);
		EmitCharacter(*current); }
	else {
		SwitchState(Script_data_escaped_state);
		next--;
	}

	return true;
}

bool Tokeniser::OnScriptDataDoubleEscapedState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Script_data_double_escaped_dash_state);
		EmitCharacter(*current);
		return true;

	case '<':
		SwitchState(Script_data_double_escaped_less_than_sign_state);
		EmitCharacter(*current);
		return true;

	default:
		EmitCharacter(*current);
		return true;
	}
}

bool Tokeniser::OnScriptDataDoubleEscapedDashState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		SwitchState(Script_data_double_escaped_dash_dash_state);
		EmitCharacter(*current);
		return true;

	case '<':
		SwitchState(Script_data_double_escaped_less_than_sign_state);
		EmitCharacter(*current);
		return true;

	default:
		SwitchState(Script_data_double_escaped_state);
		EmitCharacter(*current);
		return true;
	}
}

bool Tokeniser::OnScriptDataDoubleEscapedDashDashState() {
	const char* current = Consume();

	switch(*current) {
	case '-':
		EmitCharacter(*current);
		return true;

	case '<':
		SwitchState(Script_data_double_escaped_less_than_sign_state);
		EmitCharacter(*current);
		return true;

	case '>':
		SwitchState(Script_data_state);
		EmitCharacter(*current);
		return true;

	default:
		SwitchState(Script_data_double_escaped_state);
		EmitCharacter(*current);
		return true;
	}
}

bool Tokeniser::OnScriptDataDoubleEscapedLessThanSignState() {
	const char* current = Consume();

	switch(*current) {
	case '/':
		temporaryBuffer.clear();
		SwitchState(Script_data_double_escape_end_state);
		EmitCharacter(*current);
		return true;

	default:
		SwitchState(Script_data_double_escaped_state);
		next--;
		return true;
	}
}

bool Tokeniser::OnScriptDataDoubleEscapeEndState() {
	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case  ' ':
	case  '/':
	case  '>':
		if(temporaryBuffer.compare("script") == 0) {
			SwitchState(Script_data_escaped_state);	}
		else {
			SwitchState(Script_data_double_escaped_state); }
		EmitCharacter(*current);
		return true;

	default:
		break;
	}

	if(std::isalpha(*current)) {
		temporaryBuffer += std::tolower(*current);
		EmitCharacter(*current);}
	else {
		SwitchState(Script_data_double_escaped_state);
		next--; }

	return true;
}

bool Tokeniser::OnRAWTEXTState() {
	const char* current = Consume();

	switch(*current) {
	case '<':
		SwitchState(RAWTEXT_less_than_sign_state);
		return true;

	default:
		EmitCharacter(*current);
		return true;
	}
}

bool Tokeniser::OnRAWTEXTLessThanSignState() {
	const char* current = Consume();

	switch(*current) {
	case '/':
		temporaryBuffer.clear();
		SwitchState(RAWTEXT_end_tag_open_state);
		return true;

	default:
		SwitchState(RAWTEXT_state);
		EmitCharacter('<');
		next--;
		return true;
	}
}

bool Tokeniser::OnRAWTEXTEndTagOpenState() {
	const char* current = Consume();

	if(std::isalpha(*current)) {
		tagToken.tagType = domparser::generic::TagToken::END_TAG;
		tagToken.name = std::tolower(*current);
		temporaryBuffer += *current;
		SwitchState(RAWTEXT_end_tag_name_state);
	}
	else {
		SwitchState(RAWTEXT_state);
		EmitCharacter("</",2);
		next--;
	}

	return true;
}

bool Tokeniser::OnRAWTEXTEndTagNameState() {
	const char* current = Consume();

	switch(*current) {
	case '\t':
	case '\n':
	case '\r':
	case  ' ':
		if(IsAppropriateEndTag()) {
			SwitchState(Before_attribute_name_state);
			return true; }
		break;

	case  '/':
		if(IsAppropriateEndTag()) {
			SwitchState(Self_closing_start_tag_state);
			return true; }
		break;

	case  '>':
		if(IsAppropriateEndTag()) {
			SwitchState(Data_state);
			return true; }
		break;

	default:
		break;
	}

	if(std::isalpha(*current)) {
		tagToken.name = std::tolower(*current);
		temporaryBuffer += *current;
	}
	else {
		SwitchState(RAWTEXT_state);
		EmitCharacter("</",2);
		EmitCharacter(temporaryBuffer.c_str(),temporaryBuffer.length());
		next--;
	}

	return true;
}

bool Tokeniser::OnPLAINTEXTState() {
	EmitCharacter(Consume(),1);
	return true;
}

void Tokeniser::EmitCharacter(const char* charToEmit, const size_t size) {
	for(size_t pos = 0; pos < size; pos++) {
		domparser::generic::CharacterToken charToken;
		charToken.Append(&charToEmit[pos],1);
		factory.OnToken(charToken);
	}
}

void Tokeniser::EmitCharacter(const char charToEmit) {
	EmitCharacter(&charToEmit,1);
}

void Tokeniser::EmitComment() {

	factory.OnToken(commentToken);
	commentToken.Reset();
}

void Tokeniser::EmitTag() {

	if(tagToken.tagType == domparser::generic::TagToken::START_TAG) {
		lastStartTagName = tagToken.name; }

	factory.OnToken(tagToken);
	tagToken.Reset();
}

void Tokeniser::EmitDocType() {

	factory.OnToken(doctypeToken);
	doctypeToken.Reset();
}

std::string Tokeniser::ConsumeCharacterReference(const char* additionalCharacter) {

	char* pTmpCur = next;

	switch(*pTmpCur) {
	case '\t':
	case '\n':
	case '\r':
	case ' ' :
	case '<' :
	case '&' :
		return "";
	default:
		break;
	}

	if(additionalCharacter && *pTmpCur == *additionalCharacter) {
		pTmpCur++;
	}

	size_t refSize = 0;
	switch(*pTmpCur) {
	case '#':
		refSize = ConsumeNumericCharacterReference(pTmpCur);
		break;
	default:
		refSize = ConsumeNamedCharacterReference(pTmpCur);
		break;
	}

	std::string refString;
	if( refSize > 0 ) {
		refString.append(pTmpCur,refSize+1);
		Consume(refSize + 1);
	}
	return refString;
}

size_t Tokeniser::ConsumeNamedCharacterReference(char* tmpCur) const {

	char* start = tmpCur;
	char* stop  = 0;

	size_t testSize = 1;
	size_t refSize = 0;
	while(start + testSize < end) {
		bool isPossibleRef = false, isCompleteRef = false;
		refSize = NamedCharacterReferences::IsRef(start, testSize, isPossibleRef, isCompleteRef);
		if(!isPossibleRef) {
			stop = 0;
			break; }
		stop = start + refSize;
		if(isCompleteRef) {
			break;	}
		testSize++;
	}

	if(stop && stop>start) {
		return stop - start;
	}
	else {
		ParseError();
		return 0;
	}
}

size_t Tokeniser::ConsumeNumericCharacterReference(char* tmpCur) const {

	char* start = tmpCur;

	bool isHexMode = false;
	switch(*tmpCur) {
	case 'X':
	case 'x':
		isHexMode = true;
		tmpCur++;
		break;

	default:
		break;
	}

	char* stop = tmpCur;
	while(stop < end) {

		bool isNumber = false;
		if(isHexMode) {
			switch(tolower(*stop)) {
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
				isNumber = true;
				break;
			default:
				break;
			}
		}

		if(!isNumber && !isdigit(*stop)) {
			break;
		}

		stop++;
	}

	if(!stop || stop <= start) {
		ParseError();
		return 0;}

	if(*(stop+1) != ';'){
		ParseError(); }
	else {
		stop++;	}

	return stop-start;
}

void Tokeniser::ResetAllTokens() {
	tagToken.Reset();
	commentToken.Reset();
	doctypeToken.Reset();
}

bool Tokeniser::Parse(const char* pData,const size_t& size, const bool logVerbose) {

	ResetAllTokens();

	this->db = db;
	this->logVerbose = logVerbose;

	next = const_cast<char*>(pData);
	start = pData;
	end = next + size;

	InitLineVector();

	SwitchState(Data_state);

	bool success = true;
	while(success && next < end) {
		success = ProcessState();
	}
	return success;
}

bool Tokeniser::ProcessState() {

	bool success = false;
	switch(state)
	{
	case Data_state:
		success = OnDataState();
	    break;
	case Character_reference_in_data_state:
		success = OnCharacterReferenceInDataState();
	    break;
	case RCDATA_state:
		success = OnRCDATAState();
	    break;
	case Character_reference_in_RCDATA_state:
		success = OnCharacterReferenceInRCDATAState();
	    break;
	case RAWTEXT_state:
		success = OnRAWTEXTState();
	    break;
	case Script_data_state:
		success = OnScriptDataState();
	    break;
	case PLAINTEXT_state:
		success = OnPLAINTEXTState();
	    break;
	case Tag_open_state:
		success = OnTagOpenState();
	    break;
	case End_tag_open_state:
		success = OnEndTagOpenState();
	    break;
	case Tag_name_state:
		success = OnTagNameState();
	    break;
	case RCDATA_less_than_sign_state:
		success = OnRCDATALessThanSignState();
	    break;
	case RCDATA_end_tag_open_state:
		success = OnRCDATAEndTagOpenState();
	    break;
	case RCDATA_end_tag_name_state:
		success = OnRCDATAEndTagNameState();
	    break;
	case RAWTEXT_less_than_sign_state:
		success = OnRAWTEXTLessThanSignState();
	    break;
	case RAWTEXT_end_tag_open_state:
		success = OnRAWTEXTEndTagOpenState();
	    break;
	case RAWTEXT_end_tag_name_state:
		success = OnRAWTEXTEndTagNameState();
	    break;
	case Script_data_less_than_sign_state:
		success = OnScriptDataLessThanSignState();
	    break;
	case Script_data_end_tag_open_state:
		success = OnScriptDataEndTagOpenState();
	    break;
	case Script_data_end_tag_name_state:
		success = OnScriptDataEndTagNameState();
	    break;
	case Script_data_escape_start_state:
		success = OnScriptDataEscapeStartState();
	    break;
	case Script_data_escape_start_dash_state:
		success = OnScriptDataEscapeStartDashState();
	    break;
	case Script_data_escaped_state:
		success = OnScriptDataEscapedState();
	    break;
	case Script_data_escaped_dash_state:
		success = OnScriptDataEscapedDashState();
	    break;
	case Script_data_escaped_dash_dash_state:
		success = OnScriptDataEscapedDashDashState();
	    break;
	case Script_data_escaped_less_than_sign_state:
		success = OnScriptDataEscapedLessThanSignState();
	    break;
	case Script_data_escaped_end_tag_open_state:
		success = OnScriptDataEscapedEndTagOpenState();
	    break;
	case Script_data_escaped_end_tag_name_state:
		success = OnScriptDataEscapedEndTagNameState();
	    break;
	case Script_data_double_escape_start_state:
		success = OnScriptDataDoubleEscapeStartState();
	    break;
	case Script_data_double_escaped_state:
		success = OnScriptDataDoubleEscapedState();
	    break;
	case Script_data_double_escaped_dash_state:
		success = OnScriptDataDoubleEscapedDashState();
	    break;
	case Script_data_double_escaped_dash_dash_state:
		success = OnScriptDataDoubleEscapedDashDashState();
	    break;
	case Script_data_double_escaped_less_than_sign_state:
		success = OnScriptDataDoubleEscapedLessThanSignState();
	    break;
	case Script_data_double_escape_end_state:
		success = OnScriptDataDoubleEscapeEndState();
	    break;
	case Before_attribute_name_state:
		success = OnBeforeAttributeNameState();
	    break;
	case Attribute_name_state:
		success = OnAttributeNameState();
	    break;
	case After_attribute_name_state:
		success = OnAfterAttributeNameState();
	    break;
	case Before_attribute_value_state:
		success = OnBeforeAttributeValueState();
	    break;
	case Attribute_value__double_quoted__state:
		success = OnAttributeValueDoubleQuotedState();
	    break;
	case Attribute_value__single_quoted__state:
		success = OnAttributeValueSingleQuotedState();
	    break;
	case Attribute_value__unquoted__state:
		success = OnAttributeValueUnquotedState();
	    break;
	case Character_reference_in_attribute_value_state:
		success = CharacterReferenceInAttributeValueState();
	    break;
	case After_attribute_value__quoted__state:
		success = AfterAttributeValueQuotedState();
	    break;
	case Self_closing_start_tag_state:
		success = OnSelfClosingStartTagState();
	    break;
	case Bogus_comment_state:
		success = OnBogusCommentState();
	    break;
	case Markup_declaration_open_state:
		success = OnMarkupDeclarationOpenState();
	    break;
	case Comment_start_state:
		success = OnCommentStartState();
	    break;
	case Comment_start_dash_state:
		success = OnCommentStartDashState();
	    break;
	case Comment_state:
		success = OnCommentState();
	    break;
	case Comment_end_dash_state:
		success = OnCommentEndDashState();
	    break;
	case Comment_end_state:
		success = OnCommentEndState();
	    break;
	case Comment_end_bang_state:
		success = OnCommentEndBangState();
	    break;
	case DOCTYPE_state:
		success = OnDoctypeState();
	    break;
	case Before_DOCTYPE_name_state:
		success = OnBeforeDoctypeNameState();
	    break;
	case DOCTYPE_name_state:
		success = OnDoctypeNameState();
	    break;
	case After_DOCTYPE_name_state:
		success = OnAfterDoctypeNameState();
	    break;
	case After_DOCTYPE_public_keyword_state:
		success = OnAfterDoctypePublicKeywordState();
	    break;
	case Before_DOCTYPE_public_identifier_state:
		success = OnBeforeDoctypePublicIdentifierState();
	    break;
	case DOCTYPE_public_identifier__double_quoted__state:
		success = OnDoctypePublicIdentifierDoubleQuotedState();
	    break;
	case DOCTYPE_public_identifier__single_quoted__state:
		success = OnDoctypePublicIdentifierSingleQuotedState();
	    break;
	case After_DOCTYPE_public_identifier_state:
		success = OnAfterDoctypePublicIdentifierState();
	    break;
	case Between_DOCTYPE_public_and_system_identifiers_state:
		success = OnBetweenDoctypePublicAndSystemIdentifiersState();
	    break;
	case After_DOCTYPE_system_keyword_state:
		success = OnAfterDoctypeSystemKeywordState();
	    break;
	case Before_DOCTYPE_system_identifier_state:
		success = OnBeforeDoctypeSystemIdentifierState();
	    break;
	case DOCTYPE_system_identifier__double_quoted__state:
		success = OnDoctypeSystemIdentifierDoubleQuotedState();
	    break;
	case DOCTYPE_system_identifier__single_quoted__state:
		success = OnDoctypeSystemIdentifierSingleQuotedState();
	    break;
	case After_DOCTYPE_system_identifier_state:
		success = OnAfterDoctypeSystemIdentifierState();
	    break;
	case Bogus_DOCTYPE_state:
		success = OnBogusDoctypeState();
	    break;
	case CDATA_section_state:
		success = OnCDataSectionState();
	    break;

	default:
		success = false;
		break;
	}

	return success;
}

char* Tokeniser::Consume(size_t count) {
	char* tmpCur = next;
	next += count;
	return tmpCur;
}

void Tokeniser::SwitchState(const TokeniserState& newState){
	state = newState;
}

void Tokeniser::InitLineVector() {

	lines.clear();

	size_t charNo = 0, lineBegin = 0;
	char* pszStart = const_cast<char*>(start);
	for(;pszStart < end; pszStart++) {

		switch(*pszStart)
		{
		case '\r':
			if( (*(pszStart+1)) == '\n' ) { pszStart++; charNo++; }
			lines.push_back( std::pair<size_t,size_t>(lineBegin,charNo) );
			charNo++;
			lineBegin = charNo;
			break;

		case '\n':
			if( (*(pszStart+1)) == '\r' ) { pszStart++; charNo++; }
			lines.push_back( std::pair<size_t,size_t>(lineBegin,charNo) );
			charNo++;
			lineBegin = charNo;
			break;

		default:
			charNo++;
			break;
		}
	}
}

void Tokeniser::GetCurLineCol(size_t& line,size_t& col) const {

	line = col = 0;

	size_t curCharNo = next - start;
	if(next > start)
		curCharNo -= 1;

	std::vector< std::pair<size_t,size_t> >::const_iterator iterLines = lines.begin();
	for(size_t lineNo = 0;iterLines != lines.end(); ++iterLines,lineNo++) {

		if(curCharNo >= iterLines->first && curCharNo <= iterLines->second){
			line = lineNo + 1; //start with line 1
			col  = curCharNo - iterLines->first + 1; //start with column 1
			return;
		}
	}
}

std::string Tokeniser::GetLineColumnString() const {

	size_t line=0,col=0;
	GetCurLineCol(line,col);
	std::ostringstream outString;
	outString << "line: "<< line << " column: " << col;
	return outString.str();
}

bool Tokeniser::IsAppropriateEndTag() const {
	return (tagToken.tagType == domparser::generic::TagToken::END_TAG && tagToken.name.compare(lastStartTagName) == 0 );
}

}

}
