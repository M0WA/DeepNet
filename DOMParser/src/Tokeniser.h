/**
 * @file Tokeniser.h
 * @author Moritz Wagner
 * @date 02.03.2013
 *
 */

#pragma once

#include <stdint.h>
#include <vector>
#include <map>

#include <Stack.h>

#include "TokeniserStates.h"
#include "Token.h"

namespace toolbot {
	class UnitTestHtmlTokeniser;
}

namespace database {
	class DatabaseConnection;
}

namespace network {
	class HtmlData;
}

namespace domparser {
	class DatabaseUrl;
	class DocumentFactory;

/**
 * @brief standard compliant html5 tokeniser
 */
class Tokeniser {

	friend class DocumentFactory;
	friend class toolbot::UnitTestHtmlTokeniser;

private:
	Tokeniser(DocumentFactory& factory);
public:
	virtual ~Tokeniser();

public:
	/**
	 * parses html document from a string.
	 * @param pData raw html buffer.
	 * @param size size of html buffer.
	 * @param logVerbose true to produce heavily verbose output.
	 * @return false on error, true on success.
	 */
	bool Parse(const char* pData,const size_t& size, const bool logVerbose = false);

public:
	/**
	 * gets position in document (before comments etc. where removed)
	 * @param pos position in "cleaned" document
	 * @return original position
	 */
	uintptr_t MapToOriginalPosition(const uintptr_t& pos) const;

	void GetCurLineCol(size_t& line,size_t& col) const;

	/**
	 * initializes internal column/line tracking
	 */
	void InitLineVector();

	/**
	 * gets preformated column and line string for current position
	 * @return preformated column and line string
	 */
	std::string GetLineColumnString() const;

protected:
	//used by unit tests
	virtual void EmitCharacter(const char charToEmit);
	virtual void EmitComment();
	virtual void EmitTag();
	virtual void EmitDocType();
	virtual void SwitchState(const TokeniserState& newState);
	virtual void ParseError() const;

private:
	//state handler functions
	bool OnDataState();
	bool OnCharacterReferenceInDataState();
	bool OnTagOpenState();
	bool OnMarkupDeclarationOpenState();
	bool OnEndTagOpenState();
	bool OnBogusCommentState();
	bool OnTagNameState();
	bool OnCommentStartState();
	bool OnDoctypeState();
	bool OnCDataSectionState();
	bool OnBeforeAttributeNameState();
	bool OnSelfClosingStartTagState();
	bool OnCommentStartDashState();
	bool OnCommentState();
	bool OnBeforeDoctypeNameState();
	bool OnAttributeNameState();
	bool OnCommentEndDashState();
	bool OnDoctypeNameState();
	bool OnAfterAttributeNameState();
	bool OnBeforeAttributeValueState();
	bool OnCommentEndState();
	bool OnAfterDoctypeNameState();
	bool OnAttributeValueDoubleQuotedState();
	bool OnAttributeValueSingleQuotedState();
	bool OnAttributeValueUnquotedState();
	bool OnCommentEndBangState();
	bool OnBogusDoctypeState();
	bool OnAfterDoctypePublicKeywordState();
	bool OnAfterDoctypeSystemKeywordState();
	bool AfterAttributeValueQuotedState();
	bool CharacterReferenceInAttributeValueState();
	bool OnBeforeDoctypePublicIdentifierState();
	bool OnDoctypePublicIdentifierDoubleQuotedState();
	bool OnDoctypePublicIdentifierSingleQuotedState();
	bool OnBeforeDoctypeSystemIdentifierState();
	bool OnDoctypeSystemIdentifierDoubleQuotedState();
	bool OnDoctypeSystemIdentifierSingleQuotedState();
	bool OnAfterDoctypePublicIdentifierState();
	bool OnAfterDoctypeSystemIdentifierState();
	bool OnBetweenDoctypePublicAndSystemIdentifiersState();

	bool OnRCDATAState();
	bool OnCharacterReferenceInRCDATAState();
	bool OnRCDATALessThanSignState();
	bool OnRCDATAEndTagOpenState();
	bool OnRCDATAEndTagNameState();

	bool OnScriptDataState();
	bool OnScriptDataLessThanSignState();
	bool OnScriptDataEndTagOpenState();
	bool OnScriptDataEscapeStartState();
	bool OnScriptDataEndTagNameState();
	bool OnScriptDataEscapeStartDashState();
	bool OnScriptDataEscapedDashDashState();
	bool OnScriptDataEscapedLessThanSignState();
	bool OnScriptDataEscapedState();
	bool OnScriptDataEscapedDashState();
	bool OnScriptDataEscapedEndTagOpenState();
	bool OnScriptDataEscapedEndTagNameState();
	bool OnScriptDataDoubleEscapeStartState();
	bool OnScriptDataDoubleEscapedState();
	bool OnScriptDataDoubleEscapedDashState();
	bool OnScriptDataDoubleEscapedDashDashState();
	bool OnScriptDataDoubleEscapedLessThanSignState();
	bool OnScriptDataDoubleEscapeEndState();

	bool OnRAWTEXTState();
	bool OnRAWTEXTLessThanSignState();
	bool OnRAWTEXTEndTagOpenState();
	bool OnRAWTEXTEndTagNameState();

	bool OnPLAINTEXTState();

private:
	bool ProcessState();
	void EmitCharacter(const char* charToEmit, const size_t size = 1);
	std::string ConsumeCharacterReference(const char* additionalCharacterAllowed = NULL);
	size_t ConsumeNamedCharacterReference(char* tmpCur) const;
	size_t ConsumeNumericCharacterReference(char* tmpCur) const;
	bool IsAppropriateEndTag() const;
	void ResetAllTokens();
	char* Consume(size_t count = 1);

protected:
	TokeniserState state;

private:
	DocumentFactory& factory;
	char* next;
	const char* start;
	const char* end;
	size_t size;
	database::DatabaseConnection* db;
	bool logVerbose;

	TagToken tagToken;
	CommentToken commentToken;
	DocTypeToken doctypeToken;

	TokeniserState preCharRefInAttribState;
	char charRefInAttribValAddChar;

	std::string temporaryBuffer;
	std::string lastStartTagName;

	std::vector< std::pair<size_t,size_t> > lines;
};

}
