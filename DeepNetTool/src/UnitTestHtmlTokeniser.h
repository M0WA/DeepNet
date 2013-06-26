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

#include <html5/Tokeniser.h>
#include <html5/TokeniserStates.h>

namespace toolbot {
	class UnitTestHtmlDocumentFactory;

class UnitTestHtmlTokeniser : public domparser::html5::Tokeniser {
public:
	UnitTestHtmlTokeniser(UnitTestHtmlDocumentFactory& factory);
	virtual ~UnitTestHtmlTokeniser();

protected:
	virtual void EmitCharacter(const char charToEmit);
	virtual void EmitComment();
	virtual void EmitTag();
	virtual void EmitDocType();
	virtual void SwitchState(const domparser::html5::TokeniserState& newState);
	virtual void ParseError() const;

private:
	static std::string NameFromState(const domparser::html5::TokeniserState& stateIn);
};

}
