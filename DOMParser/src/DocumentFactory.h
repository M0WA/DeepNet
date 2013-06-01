/**
 *
 * @file DocumentFactory.h
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <Stack.h>

#include "Node.h"

namespace network {
	class HttpUrl;
}

namespace htmlparser {
	class DatabaseUrl;
}

namespace network {
	class HtmlData;
}

namespace domparser {
	class Document;
	class Token;
	class CommentToken;
	class CharacterToken;
	class DocTypeToken;
	class TagToken;
	class Tokeniser;
	class HTMLElement;

class DocumentFactory {

	friend class Tokeniser;

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

protected:
	DocumentFactory(const network::HttpUrl& url);
public:
	virtual ~DocumentFactory();

public:
	/**
	 * creates an HtmlDocument from data string
	 * @param url url of document.
	 * @param data html data.
	 * @return NULL on error, document on success.
	 */
	static Document* FromHtmlData(const network::HttpUrl& url, const network::HtmlData& data);

protected:
	bool ParseFromString(const char* content, const size_t& size);

protected:
	virtual bool OnToken(const Token& token);
	virtual void SwitchMode(const InsertionMode& newInsertionMode);

protected:
	void ParseError() const;
	bool OnInsertion(const Token& token, InsertionMode mode);
	bool OnForeignContent(const Token& token);

protected:
	bool AppendComment(const CommentToken& token);
	bool AppendDocType(const DocTypeToken& token);
	bool AppendGenericRCDATA(const TagToken& token);
	bool AppendGenericRawText(const TagToken& token);
	bool AppendGenericRCDATAOrRawText(const TagToken& token, bool isRCData);
	HTMLElement* AppendHtmlElement(const TagToken& token);
	bool InsertCharacter(const CharacterToken& token);
	void ResetInsertionMode();
	void ReconstructActiveFormatElements();

protected:
	//handle insertion modes
	bool OnInitialInsertion(const Token& token);
	bool OnBeforeHtmlInsertion(const Token& token);
	bool OnBeforeHeadInsertion(const Token& token);
	bool OnInHeadInsertion(const Token& token);
	bool OnInHeadNoscriptInsertion(const Token& token);
	bool OnAfterHeadInsertion(const Token& token);
	bool OnInBodyInsertion(const Token& token);
	bool OnTextInsertion(const Token& token);
	bool OnInTableInsertion(const Token& token);
	bool OnInTableTextInsertion(const Token& token);
	bool OnInCaptionInsertion(const Token& token);
	bool OnInColumnGroupInsertion(const Token& token);
	bool OnInTableBodyInsertion(const Token& token);
	bool OnInRowInsertion(const Token& token);
	bool OnInCellInsertion(const Token& token);
	bool OnInSelectInsertion(const Token& token);
	bool OnInSelectInTableInsertion(const Token& token);
	bool OnAfterBodyInsertion(const Token& token);
	bool OnInFramesetInsertion(const Token& token);
	bool OnAfterFramesetInsertion(const Token& token);
	bool OnAfterAfterBodyInsertion(const Token& token);
	bool OnAfterAfterFramesetInsertion(const Token& token);

protected:
	bool OnInBodyStartTagInsertion(const TagToken& tagToken);
	bool OnInBodyEndTagInsertion(const TagToken& tagToken);

protected:
	static std::string InsertionModeToString(const InsertionMode& insertMode);

private:
	bool IgnoreHtmlWhiteSpace(const CharacterToken& token);

protected:
	//const htmlparser::DatabaseUrl& url;
	const network::HttpUrl& url;
	Document* curDoc;
	Tokeniser* tokeniser;

	InsertionMode insertionMode;
	InsertionMode orgInsertionMode;

	tools::Stack<Node*> openElementStack;

private:
	bool scriptingFlag;
	bool framesetOk;
};

}
