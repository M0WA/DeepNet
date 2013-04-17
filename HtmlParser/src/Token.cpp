/**
 *
 * @file Token.cpp
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#include "Token.h"

#include <sstream>

#include <StringTools.h>

namespace htmlparser {

Token::Token(const TokenType& type)
:type(type){
}

Token::~Token() {
}

std::string Token::ToString() const {

	std::ostringstream ssStream;
	std::string tmp;

	switch(type)
	{
	case COMMENT:
		ssStream << "Token::COMMENT ";
		ssStream << "text: \"" << dynamic_cast<const htmlparser::CommentToken&>(*this).comment << "\"";
		break;
	case CHAR:
		ssStream << "Token::CHAR ";
		tmp = dynamic_cast<const htmlparser::CharacterToken&>(*this).text;
		tools::StringTools::ReplaceString("\r","\\r",tmp);
		tools::StringTools::ReplaceString("\n","\\n",tmp);
		ssStream << "text: \"" << tmp << "\"";
		break;
	case DOCTYPE:
		ssStream << "Token::DOCTYPE ";
		ssStream << "name: \"" << dynamic_cast<const htmlparser::DocTypeToken&>(*this).name << "\" ";
		ssStream << "public_identifier: \"" << dynamic_cast<const htmlparser::DocTypeToken&>(*this).public_identifier << "\" ";
		ssStream << "system_identifier: \"" << dynamic_cast<const htmlparser::DocTypeToken&>(*this).system_identifier << "\"";
		break;
	case TAG:
		{
			std::string tokenType;
			switch(dynamic_cast<const htmlparser::TagToken&>(*this).tagType){
			case TagToken::START_TAG:
				tokenType = "TagToken::START_TAG";
				break;
			case TagToken::END_TAG:
				tokenType = "TagToken::END_TAG";
				break;
			case TagToken::INVALID_TYPE:
				tokenType = "TagToken::INVALID_TYPE";
				break;
			}
			ssStream << "Token::TAG ";
			ssStream << "type: \"" << tokenType << "\" ";
			ssStream << "name: \"" << dynamic_cast<const htmlparser::TagToken&>(*this).name << "\" ";
			ssStream << "selfClosing: \"" << (dynamic_cast<const htmlparser::TagToken&>(*this).selfClosingFlag ? "1" : "0" ) << "\"";
		}
		break;
	}

	return ssStream.str();
}

std::string Token::ToXML() const {

	std::string tokenName = "", tmp = "";
	std::ostringstream ssAttributes;
	std::ostringstream ssContent;

	switch(type)
	{
	case COMMENT:
		tokenName = "COMMENT";
		ssContent << dynamic_cast<const htmlparser::CommentToken&>(*this).comment;
		break;
	case CHAR:
		tokenName = "CHAR";
		tmp = dynamic_cast<const htmlparser::CharacterToken&>(*this).text;
		tools::StringTools::ReplaceString("\r","\\r",tmp);
		tools::StringTools::ReplaceString("\n","\\n",tmp);
		ssContent << tmp;
		break;
	case DOCTYPE:
		tokenName = "DOCTYPE";
		ssAttributes << " name=\"" << dynamic_cast<const htmlparser::DocTypeToken&>(*this).name << "\"";
		ssAttributes << " public_identifier=\"" << dynamic_cast<const htmlparser::DocTypeToken&>(*this).public_identifier << "\"";
		ssAttributes << " system_identifier=\"" << dynamic_cast<const htmlparser::DocTypeToken&>(*this).system_identifier << "\"";
		break;
	case TAG:
		tokenName = "TAG";
		std::string tokenType;
		switch(dynamic_cast<const htmlparser::TagToken&>(*this).tagType){
		case TagToken::START_TAG:
			tokenType = "START_TAG";
			break;
		case TagToken::END_TAG:
			tokenType = "END_TAG";
			break;
		case TagToken::INVALID_TYPE:
			tokenType = "INVALID_TYPE";
			break;
		}
		ssAttributes << " name=\"" << dynamic_cast<const htmlparser::TagToken&>(*this).name << "\"";
		ssAttributes << " type=\"" << tokenType << "\"";
		ssAttributes << " selfClosing=\"" << (dynamic_cast<const htmlparser::TagToken&>(*this).selfClosingFlag ? "1" : "0" ) << "\"";
		break;
	}

	std::ostringstream ssStream;
	ssStream << "<" << tokenName << ssAttributes.str() << ">"
			 << ssContent.str()
			 << "</" << tokenName << ">";
	return ssStream.str();
}

}
