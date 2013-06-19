/**
 *
 * @file DocumentFactory.cpp
 * @author Moritz Wagner
 * @date 03.03.2013
 *
 */

#include "DocumentFactory.h"

#include <HtmlData.h>
#include <Logging.h>
#include <StringTools.h>
#include <HttpUrl.h>

#include "Token.h"
#include "Tokeniser.h"
#include "Document.h"
#include "DocumentType.h"
#include "Element.h"
#include "HTMLElement.h"
#include "Comment.h"
#include "Node.h"
#include "NodeFactory.h"
#include "StringConstants.h"

namespace domparser {

DocumentFactory::DocumentFactory(const network::HttpUrl& url)
: url(url)
, curDoc(0)
, tokeniser(0)
, insertionMode(initial)
, orgInsertionMode(initial)
, scriptingFlag(false)
, framesetOk(true){
}

DocumentFactory::~DocumentFactory() {
}

Document* DocumentFactory::FromHtmlData(const network::HttpUrl& url, const network::HtmlData& data) {

	DocumentFactory instance(url);
	Tokeniser tokeniserImpl(instance);
	instance.curDoc = new Document(url, "utf-8", data.GetContentType().c_str());
	instance.tokeniser = &tokeniserImpl;
	tokeniserImpl.Parse(data.GetBuffer(),data.GetBufferSize());
	return instance.curDoc;
}

void DocumentFactory::ParseError() const {

	std::ostringstream ssLog;
	ssLog << "parser error at " << tokeniser->GetLineColumnString();
	log::Logging::LogInfo(ssLog.str());
}

bool DocumentFactory::AppendComment(const CommentToken& token) {
	Comment* pComment = dynamic_cast<Comment*>(NodeFactory::FromToken(curDoc,0,token));
	curDoc->appendChild(dynamic_cast<Node*>(pComment));
	return true;
}

bool DocumentFactory::AppendGenericRCDATA(const TagToken& token) {

	return AppendGenericRCDATAOrRawText(token, true);
}

bool DocumentFactory::AppendGenericRawText(const TagToken& token) {

	return AppendGenericRCDATAOrRawText(token, false);
}

bool DocumentFactory::AppendDocType(const DocTypeToken& token) {

	DocumentType* docType = curDoc->implementation.createDocumentType(token.name,token.public_identifier,token.system_identifier);
	curDoc->appendChild(dynamic_cast<Node*>(docType));
	return true;
}

HTMLElement* DocumentFactory::AppendHtmlElement(const TagToken& token) {

	HTMLElement* newElement = dynamic_cast<HTMLElement*>(NodeFactory::FromToken(curDoc,0,token));
	curDoc->appendChild(newElement);
	openElementStack.Push(newElement);
	return newElement;
}

bool DocumentFactory::AppendGenericRCDATAOrRawText(const TagToken& token, bool isRCData) {

	AppendHtmlElement(token);

	if(isRCData) {
		tokeniser->SwitchState(RCDATA_state); }
	else {
		tokeniser->SwitchState(RAWTEXT_state); }

	orgInsertionMode = insertionMode;
	insertionMode = text;

	return true;
}

bool DocumentFactory::IgnoreHtmlWhiteSpace(const CharacterToken& token) {

	std::string::const_iterator iterText = token.text.begin();
	for(;iterText != token.text.end();++iterText) {
		switch(*iterText) {
		case '\r':
		case '\n':
		case '\t':
		case '\f':
		case ' ':
			break;
		default:
			return false;
		}
	}
	return true;
}

std::string DocumentFactory::InsertionModeToString(const InsertionMode& insertMode) {

	switch(insertMode) {
	case initial:
	    return "initial";
	case before_html:
	    return "before_html";
	case before_head:
	    return "before_head";
	case in_head:
	    return "in_head";
	case in_head_noscript:
	    return "in_head_noscript";
	case after_head:
	    return "after_head";
	case in_body:
	    return "in_body";
	case text:
	    return "text";
	case in_table:
	    return "in_table";
	case in_table_text:
	    return "in_table_text";
	case in_caption:
	    return "in_caption";
	case in_column_group:
	    return "in_column_group";
	case in_table_body:
	    return "in_table_body";
	case in_row:
	    return "in_row";
	case in_cell:
	    return "in_cell";
	case in_select:
	    return "in_select";
	case in_select_in_table:
	    return "in_select_in_table";
	case after_body:
	    return "after_body";
	case in_frameset:
	    return "in_frameset";
	case after_frameset:
	    return "after_frameset";
	case after_after_body:
	    return "after_after_body";
	case after_after_frameset:
	    return "after_after_frameset";
	default:
		return "INVALID MODE";
	}
}

void DocumentFactory::SwitchMode(const InsertionMode& newInsertionMode) {
	insertionMode = newInsertionMode;
}

bool DocumentFactory::OnToken(const Token& token) {

	bool success = false;
	if( 1 ) {
		success = OnInsertion(token,insertionMode);
	}
	else {
		success = OnForeignContent(token);
	}
	return success;
}

bool DocumentFactory::OnInsertion(const Token& token, InsertionMode mode) {

	bool success = false;
	switch(mode) {
	case initial:
		success = OnInitialInsertion(token);
	    break;
	case before_html:
		success = OnBeforeHtmlInsertion(token);
	    break;
	case before_head:
		success = OnBeforeHeadInsertion(token);
	    break;
	case in_head:
		success = OnInHeadInsertion(token);
	    break;
	case in_head_noscript:
		success = OnInHeadNoscriptInsertion(token);
	    break;
	case after_head:
		success = OnAfterHeadInsertion(token);
	    break;
	case in_body:
		success = OnInBodyInsertion(token);
	    break;
	case text:
		success = OnTextInsertion(token);
	    break;
	case in_table:
		success = OnInTableInsertion(token);
	    break;
	case in_table_text:
		success = OnInTableTextInsertion(token);
	    break;
	case in_caption:
		success = OnInCaptionInsertion(token);
	    break;
	case in_column_group:
		success = OnInColumnGroupInsertion(token);
	    break;
	case in_table_body:
		success = OnInTableBodyInsertion(token);
	    break;
	case in_row:
		success = OnInRowInsertion(token);
	    break;
	case in_cell:
		success = OnInCellInsertion(token);
	    break;
	case in_select:
		success = OnInSelectInsertion(token);
	    break;
	case in_select_in_table:
		success = OnInSelectInTableInsertion(token);
	    break;
	case after_body:
		success = OnAfterBodyInsertion(token);
	    break;
	case in_frameset:
		success = OnInFramesetInsertion(token);
	    break;
	case after_frameset:
		success = OnAfterFramesetInsertion(token);
	    break;
	case after_after_body:
		success = OnAfterAfterBodyInsertion(token);
	    break;
	case after_after_frameset:
		success = OnAfterAfterFramesetInsertion(token);
	    break;
	default:
		return false;
	}
	return success;
}

bool DocumentFactory::OnForeignContent(const Token& token) {

	//TODO: not fully implemented

	return false;
}

bool DocumentFactory::OnInitialInsertion(const Token& token) {

	switch(token.type) {

	case Token::CHAR:
		if(IgnoreHtmlWhiteSpace(dynamic_cast<const CharacterToken&>(token)))
			return true;
		break;

	case Token::COMMENT:
		return AppendComment(dynamic_cast<const CommentToken&>(token));

	case Token::DOCTYPE:
		return OnInitialInsertion_DOCTYPE(dynamic_cast<const DocTypeToken&>(token));

	case Token::TAG:
		ParseError();
		break;
	}

	//
	//TODO: not fully implemented
	//
	SwitchMode(before_html);
	return OnToken(token);
}

bool DocumentFactory::OnInitialInsertion_DOCTYPE(const DocTypeToken& token) {

	bool isParseError = (token.name.compare("html") != 0);
	isParseError |= (token.pPublicIdentifier != 0);
	isParseError |= (token.pSystemIdentifier != 0);
	isParseError |= (token.system_identifier.compare("about:legacy-compat") != 0);

	if(isParseError) {
		if((token.name.compare("html") == 0)) {

			const char* compareSysIdent = 0;
			if(token.public_identifier.compare(public_identifier_html_40) == 0) {
				compareSysIdent = system_identifier_html_strict_40;	}
			else if(token.public_identifier.compare(public_identifier_html_401) == 0) {
				compareSysIdent = system_identifier_html_strict_401; }
			else if(token.public_identifier.compare(public_identifier_xhtml_10) == 0) {
				compareSysIdent = system_identifier_xhtml_strict_10; }
			else if(token.public_identifier.compare(public_identifier_xhtml_11) == 0) {
				compareSysIdent = system_identifier_xhtml_strict_11; }

			isParseError = !(token.pSystemIdentifier == 0);
			if(isParseError && compareSysIdent) {
				isParseError = !(token.system_identifier.compare(compareSysIdent) == 0); }
		}
	}

	if(isParseError) {
		ParseError(); }

	bool success = AppendDocType(token);

	//
	//TODO: not fully implemented
	//

	SwitchMode(before_html);
	return success;
}

bool DocumentFactory::OnBeforeHtmlInsertion(const Token& token) {

	switch(token.type) {

	case Token::CHAR:
		if(IgnoreHtmlWhiteSpace(dynamic_cast<const CharacterToken&>(token)))
			return true;
		break;

	case Token::COMMENT:
		AppendComment(dynamic_cast<const CommentToken&>(token));
		return true;

	case Token::DOCTYPE:
		ParseError();
		return true;

	case Token::TAG:
		{
			const TagToken& tagToken = dynamic_cast<const TagToken&>(token);
			if(	tagToken.name.compare("html") == 0 &&
				tagToken.tagType == TagToken::START_TAG
			) {
				AppendHtmlElement(tagToken);
				SwitchMode(before_head);
				return true;
			}
			else if ( tagToken.tagType == TagToken::END_TAG &&
					  tools::StringTools::IsOneOf(tagToken.name, head_body_html_br ) ) {
				ParseError();
				break;
			}
			else if ( tagToken.tagType == TagToken::END_TAG ){
				ParseError();
				return true;
			}
		}
		break;
	}

	TagToken tagHtmlToken;
	tagHtmlToken.name = "html";
	tagHtmlToken.tagType = TagToken::START_TAG;
	OnToken(tagHtmlToken);

	SwitchMode(before_head);
	return OnToken(token);
}

bool DocumentFactory::OnBeforeHeadInsertion(const Token& token) {

	switch(token.type) {

	case Token::CHAR:
		if(IgnoreHtmlWhiteSpace(dynamic_cast<const CharacterToken&>(token)))
			return true;
		break;

	case Token::COMMENT:
		return AppendComment(dynamic_cast<const CommentToken&>(token));

	case Token::DOCTYPE:
		ParseError();
		return true;

	case Token::TAG:
		{
			const TagToken& tagToken = dynamic_cast<const TagToken&>(token);
			if(	tagToken.name.compare("html") == 0 &&
				tagToken.tagType == TagToken::START_TAG )
			{
				return OnInsertion(token, in_body);
			}
			else if(tagToken.name.compare("head") == 0 &&
					tagToken.tagType == TagToken::START_TAG )
			{
				curDoc->headElement = dynamic_cast<HTMLHeadElement*>(AppendHtmlElement(tagToken));
				SwitchMode(in_head);
				return true;
			}
			else if ( tagToken.tagType == TagToken::END_TAG &&
				  !tools::StringTools::IsOneOf(tagToken.name, head_body_html_br ) )	{
				ParseError();
				return true;
			}
		}
		break;
	}

	TagToken tagHeadToken;
	tagHeadToken.name = "head";
	tagHeadToken.tagType = TagToken::START_TAG;

	if(!OnToken(tagHeadToken))
		return false;
	return OnToken(token);
}

bool DocumentFactory::OnInHeadInsertion(const Token& token) {

	switch(token.type) {

	case Token::CHAR:
		if(IgnoreHtmlWhiteSpace(dynamic_cast<const CharacterToken&>(token))) {
			return InsertCharacter(dynamic_cast<const CharacterToken&>(token)); }
		break;

	case Token::COMMENT:
		return AppendComment(dynamic_cast<const CommentToken&>(token));

	case Token::DOCTYPE:
		ParseError();
		return true;

	case Token::TAG:
		{
			const TagToken& tagToken = dynamic_cast<const TagToken&>(token);

			if( tagToken.tagType == TagToken::START_TAG &&
			    tagToken.name.compare("html") == 0 )
			{
				return OnInsertion(token, in_body);
			}
			else if( tagToken.tagType == TagToken::START_TAG &&
					 tools::StringTools::IsOneOf(tagToken.name, base_basefont_bgsound_link ) )
			{
				AppendHtmlElement(tagToken);
				openElementStack.Pop();
				if(!tagToken.selfClosingFlag)
					ParseError();
				return true;
			}
			else if( tagToken.tagType == TagToken::START_TAG &&
				    tagToken.name.compare("meta") == 0 )
			{
				AppendHtmlElement(tagToken);
				openElementStack.Pop();
				if(!tagToken.selfClosingFlag)
					ParseError();

				//TODO: not fully implemented
				return true;
			}
			else if( tagToken.tagType == TagToken::START_TAG &&
				    tagToken.name.compare("title") == 0 )
			{
				return AppendGenericRCDATA(tagToken);
			}
			else if ( tagToken.tagType == TagToken::START_TAG &&
					( (tagToken.name.compare("noscript") == 0 && scriptingFlag) ||
					  tools::StringTools::IsOneOf(tagToken.name, noframes_style)
					) )
			{
				return AppendGenericRawText(tagToken);
			}
			else if ( tagToken.tagType == TagToken::START_TAG &&
					(tagToken.name.compare("noscript") == 0 && !scriptingFlag) ) {

				AppendHtmlElement(tagToken);
				SwitchMode(in_head_noscript);
				return true;
			}
			else if ( tagToken.tagType == TagToken::START_TAG &&
					tagToken.name.compare("script") == 0 ) {

				HTMLScriptElement* scriptElement = dynamic_cast<HTMLScriptElement*>(NodeFactory::FromToken(curDoc,0,token));
				scriptElement->async = false;
				scriptElement->defer = true; //TODO: check if this is correct

				//
				//TODO: not fully implemented
				//

				curDoc->appendChild(scriptElement);
				openElementStack.Push(scriptElement);

				tokeniser->SwitchState(Script_data_state);
				orgInsertionMode = insertionMode;
				SwitchMode(text);
				return true;
			}
			else if ( tagToken.tagType == TagToken::END_TAG &&
					tagToken.name.compare("head") == 0 ) {
				openElementStack.Pop();
				SwitchMode(after_head);
				return true;
			}
			else if (
				(tagToken.tagType == TagToken::END_TAG && !tools::StringTools::IsOneOf(tagToken.name,body_html_br)) ||
				(tagToken.tagType == TagToken::START_TAG && tagToken.name.compare("head"))
				) {
				ParseError();
				return true;
			}
		}
		break;
	}

	TagToken endHead;
	endHead.name = "head";
	endHead.tagType = TagToken::END_TAG;
	OnToken(endHead);
	return OnToken(token);
}

bool DocumentFactory::OnInHeadNoscriptInsertion(const Token& token) {

	if(token.type == Token::DOCTYPE) {
		return true;
	}

	bool isTagToken = (token.type == Token::TAG);
	bool isStartToken = isTagToken && dynamic_cast<const TagToken&>(token).tagType == TagToken::START_TAG;
	bool isEndToken = isTagToken && dynamic_cast<const TagToken&>(token).tagType == TagToken::END_TAG;
	if(isTagToken) {
		const TagToken& tagToken = dynamic_cast<const TagToken&>(token);
		if(isStartToken && tagToken.name.compare("html")) {
			return OnInsertion(token,in_body);
		}
		if(isEndToken && tagToken.name.compare("noscript")) {
			openElementStack.Pop();
			SwitchMode(in_head);
			return true;
		}
	}

	bool test = (token.type == Token::COMMENT);
	test |= (token.type == Token::CHAR && IgnoreHtmlWhiteSpace( dynamic_cast<const CharacterToken&>(token) ));
	test |= (isStartToken && tools::StringTools::IsOneOf(dynamic_cast<const TagToken&>(token).name,basefont_bgsound_link_meta_noframes_style) );
	if(test) {
		return OnInsertion(token,in_head);
	}

	test = ( isEndToken && dynamic_cast<const TagToken&>(token).name.compare("br") != 0 );
	test |= ( isStartToken && tools::StringTools::IsOneOf(dynamic_cast<const TagToken&>(token).name,head_noscript) );
	if(test) {
		ParseError();
		return true;
	}

	TagToken endNoscript;
	endNoscript.name = "noscript";
	endNoscript.tagType = TagToken::END_TAG;
	OnToken(endNoscript);

	return OnToken(token);
}

bool DocumentFactory::OnAfterHeadInsertion(const Token& token) {

	switch(token.type){

	case Token::COMMENT:
		return AppendComment(dynamic_cast<const CommentToken&>(token));

	case Token::DOCTYPE:
		ParseError();
		return true;

	case Token::CHAR:
		if( IgnoreHtmlWhiteSpace(dynamic_cast<const CharacterToken&>(token)) ) {
			return InsertCharacter(dynamic_cast<const CharacterToken&>(token)); }
		break;

	case Token::TAG:
		break;
	}

	if(token.type == Token::TAG) {

		const TagToken& tagToken = dynamic_cast<const TagToken&>(token);
		if(tagToken.tagType == TagToken::START_TAG) {

			if(tagToken.name.compare("html") == 0) {
				return OnInsertion(token,in_body); }

			if(tagToken.name.compare("body") == 0) {
				AppendHtmlElement(tagToken);
				framesetOk = false;
				SwitchMode(in_body);
				return true; }

			if(tagToken.name.compare("frameset") == 0) {
				AppendHtmlElement(tagToken);
				SwitchMode(in_frameset);
				return true; }

			if(tools::StringTools::IsOneOf(tagToken.name,base_basefont_bgsound_link_meta_noframes_script_style_title)) {
				ParseError();
				openElementStack.Push(curDoc->headElement);
				OnInsertion(token,in_head);
				openElementStack.Pop();
				return true; }

			if(tagToken.name.compare("head") == 0) {
				ParseError();
				return true; }

		}
		else if(tagToken.tagType == TagToken::END_TAG) {
			if(!tools::StringTools::IsOneOf(tagToken.name,body_html_br)) {
				ParseError();
				return true;
			}
		}
	}

	TagToken bodyToken;
	bodyToken.name = "body";
	bodyToken.tagType = TagToken::START_TAG;
	OnToken(bodyToken);

	framesetOk = true;
	return OnToken(token);
}

bool DocumentFactory::OnInBodyInsertion(const Token& token) {

	switch(token.type) {

	case Token::CHAR:
		ReconstructActiveFormatElements();
		InsertCharacter(dynamic_cast<const CharacterToken&>(token));
		if( !IgnoreHtmlWhiteSpace(dynamic_cast<const CharacterToken&>(token)) ) {
			framesetOk = false; }
		return true;

	case Token::COMMENT:
		return AppendComment(dynamic_cast<const CommentToken&>(token));

	case Token::DOCTYPE:
		ParseError();
		return true;

	case Token::TAG:
		break;

	}

	const TagToken& tagToken = dynamic_cast<const TagToken&>(token);
	switch(tagToken.tagType)
	{
	case TagToken::START_TAG:
		return OnInBodyStartTagInsertion(tagToken);

	case TagToken::END_TAG:
		return OnInBodyEndTagInsertion(tagToken);

	case TagToken::INVALID_TYPE:
	default:
		return false;
	}
}

bool DocumentFactory::OnInTableInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInTableTextInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInCaptionInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInColumnGroupInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInTableBodyInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInRowInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInCellInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInSelectInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInSelectInTableInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnAfterBodyInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnInFramesetInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnAfterFramesetInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnAfterAfterBodyInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::OnAfterAfterFramesetInsertion(const Token& token) {
    return false;

	/*
	switch(token.type) {

	case Token::CHAR:
		return true;

	case Token::COMMENT:
		return true;

	case Token::DOCTYPE:
		return true;

	case Token::TAG:
		return true;

	default:
		return false;
	}
	*/
}

bool DocumentFactory::InsertCharacter(const CharacterToken& token) {
	return false;
}

void DocumentFactory::ResetInsertionMode() {

}

void DocumentFactory::ReconstructActiveFormatElements() {

}

bool DocumentFactory::OnTextInsertion(const Token& token) {

	//
	//TODO: not fully implemented
	//

	switch(token.type) {

	case Token::CHAR:
		return InsertCharacter(dynamic_cast<const CharacterToken&>(token));

	case Token::TAG:
		if(dynamic_cast<const TagToken&>(token).tagType == TagToken::END_TAG)
			break;
		return false;

	case Token::COMMENT:
	case Token::DOCTYPE:
		return false;
	}

	const TagToken& tagToken = dynamic_cast<const TagToken&>(token);
	if(tagToken.tagType != TagToken::END_TAG)
		return false;

	if(tagToken.name.compare("script") == 0) {
		//
		//TODO: not fully implemented
		//
		openElementStack.Pop();
		SwitchMode(orgInsertionMode);
	}
	else {
		openElementStack.Pop();
		SwitchMode(orgInsertionMode);
	}
	return true;
}

bool DocumentFactory::OnInBodyStartTagInsertion(const TagToken& tagToken) {

	if(tagToken.name.compare("html") == 0) {
		ParseError();
		std::vector<AttributeToken>::const_iterator iterAttr = tagToken.attributes.begin();
		for( ; iterAttr != tagToken.attributes.end(); ++iterAttr) {
			Element* currentNode = dynamic_cast<Element*>(openElementStack.Peek());
			if( !currentNode->hasAttribute(iterAttr->name) ) {
				currentNode->setAttribute(iterAttr->name,iterAttr->value); }
		}
		return true;
	}

	if(tools::StringTools::IsOneOf(tagToken.name,base_basefont_bgsound_link_menuitem_meta_noframes_script_style_title)) {
		return OnInsertion(tagToken, in_head);
	}

	if(tagToken.name.compare("body") == 0) {
		HTMLElement* bodyElement = ((openElementStack.Size() <= 2) ? 0 : dynamic_cast<HTMLElement*>(openElementStack.Peek(1)));
		if( bodyElement && bodyElement->GetHtmlTagType() != HTMLElement::bodyTag ) {
			ParseError();
		}
		else {
			framesetOk = false;
			std::vector<AttributeToken>::const_iterator iterAttr = tagToken.attributes.begin();
			for(;iterAttr != tagToken.attributes.end();++iterAttr) {
				if(!bodyElement->hasAttribute(iterAttr->name)) {
					bodyElement->setAttribute(iterAttr->name,iterAttr->value); }
			}
		}
		return true;
	}

	if(tagToken.name.compare("frameset") == 0) {
		HTMLElement* bodyElement = ((openElementStack.Size() <= 2) ? 0 : dynamic_cast<HTMLElement*>(openElementStack.Peek(1)));
		if( !framesetOk || (bodyElement && bodyElement->GetHtmlTagType() != HTMLElement::bodyTag) )	{
			ParseError(); }
		else {
			Node* parentNode = bodyElement->GetParentNode();
			if(parentNode) {
				parentNode->removeChild(bodyElement); }
			for(size_t i = openElementStack.Size() - 1; i <= 0; --i) {
				const HTMLElement* element = dynamic_cast<const HTMLElement*>(openElementStack.ConstPeek(i));
				if(element->GetHtmlTagType() != HTMLElement::htmlTag) {
					openElementStack.Pop();	}
				else {
					break; }
			}
			AppendHtmlElement(tagToken);
			SwitchMode(in_frameset);
		}
		return true;
	}

	if(tools::StringTools::IsOneOf(tagToken.name,address_article_aside_blockquote_center_details_dialog_dir_div_dl_fieldset_figcaption_figure_footer_header_hgroup_main_menu_nav_ol_p_section_summary_ul)) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name,hTags)) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name,pre_listing)) {

	}

	if(tagToken.name.compare("form") == 0) {

	}

	if(tagToken.name.compare("li") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name,dd_dt)) {

	}

	if(tagToken.name.compare("plaintext") == 0) {

	}

	if(tagToken.name.compare("button") == 0) {

	}

	if(tagToken.name.compare("a") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, b_big_code_em_font_i_s_small_strike_strong_tt_u)) {

	}

	if(tagToken.name.compare("nobr") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, applet_marquee_object)) {

	}

	if(tagToken.name.compare("table") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, area_br_embed_img_keygen_wbr)) {

	}

	if(tagToken.name.compare("input") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, param_source_track)) {

	}

	if(tagToken.name.compare("hr") == 0) {

	}

	if(tagToken.name.compare("image") == 0) {
		ParseError();
		TagToken corrected(tagToken);
		corrected.name = "img";
		return OnToken(corrected);
	}

	if(tagToken.name.compare("isindex") == 0) {

	}

	if(tagToken.name.compare("textarea") == 0) {

	}

	if(tagToken.name.compare("xmp") == 0) {

	}

	if(tagToken.name.compare("iframe") == 0) {

	}

	if(tagToken.name.compare("noembed") == 0 ||
	   (tagToken.name.compare("noscript") == 0 && scriptingFlag)
	) {

	}

	if(tagToken.name.compare("select") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, optgroup_option)) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, rp_rt)) {

	}

	if(tagToken.name.compare("math") == 0) {

	}

	if(tagToken.name.compare("svg") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, caption_col_colgroup_frame_head_tbody_td_tfoot_th_thead_tr)) {

	}

    return false;
}

bool DocumentFactory::OnInBodyEndTagInsertion(const TagToken& tagToken) {

	if(tagToken.name.compare("body") == 0) {
		size_t i = openElementStack.Size() - 1;
		const HTMLElement* element = 0;
		bool isParseError = true;
		for(; i <= 0; --i) {
			const HTMLElement* tmpElement = dynamic_cast<const HTMLElement*>(openElementStack.ConstPeek(i));
			switch(tmpElement->GetHtmlTagType()) {
			case HTMLElement::bodyTag:
				isParseError = false;
				element = tmpElement;
				break;
			case HTMLElement::ddTag:
			case HTMLElement::aTag:
			case HTMLElement::liTag:
			case HTMLElement::optgroupTag:
			case HTMLElement::optionTag:
			case HTMLElement::pTag:
			case HTMLElement::rpTag:
			case HTMLElement::rtTag:
			case HTMLElement::tbodyTag:
			case HTMLElement::tdTag:
			case HTMLElement::tfootTag:
			case HTMLElement::thTag:
			case HTMLElement::theadTag:
			case HTMLElement::trTag:
			case HTMLElement::htmlTag:
				isParseError = false;
				break;
			default:
				break;
			}
		}
		if(!element) {
			ParseError();
			return true; }
		if(isParseError) {
			ParseError(); }
		SwitchMode(after_body);
		return true;
	}

	if(tagToken.name.compare("html") == 0) {
		TagToken bodyTag;
		bodyTag.name = "body";
		bodyTag.tagType = TagToken::END_TAG;
		OnToken(bodyTag);
		//
		//TODO: not fully implemented
		//
		return true;
	}

	if(tools::StringTools::IsOneOf(tagToken.name,address_article_aside_blockquote_button_center_details_dialog_dir_div_dl_fieldset_figcaption_figure_footer_header_hgroup_listing_main_menu_nav_ol_pre_section_summary_ul)) {

	}

	if(tagToken.name.compare("form") == 0) {

	}

	if(tagToken.name.compare("p") == 0) {

	}

	if(tagToken.name.compare("li") == 0) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name,dd_dt)) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name,hTags)) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, a_b_big_code_em_font_i_nobr_s_small_strike_strong_tt_u)) {

	}

	if(tools::StringTools::IsOneOf(tagToken.name, applet_marquee_object)) {

	}

	if(tagToken.name.compare("br") == 0) {
		ParseError();
		TagToken startBR(tagToken);
		startBR.tagType = TagToken::START_TAG;
		return OnToken(startBR);
	}

	return false;
}

}
