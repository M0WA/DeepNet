/**
 *
 * @file UnitTestHtmlTokeniser.h
 * @author Moritz Wagner
 * @date Mar 9, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <Tokeniser.h>
#include <TokeniserStates.h>

namespace toolbot {
	class UnitTestHtmlDocumentFactory;

class UnitTestHtmlTokeniser : public htmlparser::Tokeniser {
public:
	UnitTestHtmlTokeniser(UnitTestHtmlDocumentFactory& factory);
	virtual ~UnitTestHtmlTokeniser();

protected:
	virtual void EmitCharacter();
	virtual void EmitComment();
	virtual void EmitTag();
	virtual void EmitDocType();
	virtual void SwitchState(const htmlparser::TokeniserState& newState);
	virtual void ParseError() const;

private:
	static std::string NameFromState(const htmlparser::TokeniserState& stateIn);
};

}
