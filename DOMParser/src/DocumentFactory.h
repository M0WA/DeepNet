/**
 *
 * @file src/DocumentFactory.h
 * @author Moritz Wagner
 * @date 03.03.2013
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

	namespace html5 {
		class Tokeniser;
	}

	namespace generic {
		class Token;
		class CommentToken;
		class CharacterToken;
		class DocTypeToken;
		class TagToken;
	}

	class Document;
	class HTMLElement;
	class HTMLHeadElement;
	class HTMLFormElement;

/**
 * @brief factory class for html documents
 * @see domparser::Document
 * @see toolbot::UnitTestDocumentFactory
 */
class DocumentFactory {

	friend class html5::Tokeniser;

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
	/**
	 * constructs a DocumentFactory object
	 * @param url url of the document
	 * @see domparser::DocumentFactory::FromHtmlData
	 */
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
	virtual bool OnToken(const domparser::generic::Token& token);
	virtual void SwitchMode(const InsertionMode& newInsertionMode);

protected:
	void ParseError() const;
	bool OnInsertion(const domparser::generic::Token& token, InsertionMode mode);
	bool OnForeignContent(const domparser::generic::Token& token);

protected:
	bool AppendComment(const domparser::generic::CommentToken& token);
	bool AppendDocType(const domparser::generic::DocTypeToken& token);
	bool AppendGenericRCDATA(const domparser::generic::TagToken& token);
	bool AppendGenericRawText(const domparser::generic::TagToken& token);
	bool AppendGenericRCDATAOrRawText(const domparser::generic::TagToken& token, bool isRCData);
	bool InsertCharacter(const domparser::generic::CharacterToken& token);

private:
	//dom algorithms/rules
	HTMLElement* InsertHtmlElement(const domparser::generic::TagToken& token);
	void ReconstructActiveFormatElements();
	void ResetInsertionMode();

protected:
	//handle insertion modes
	bool OnInitialInsertion(const domparser::generic::Token& token);
	bool OnBeforeHtmlInsertion(const domparser::generic::Token& token);
	bool OnBeforeHeadInsertion(const domparser::generic::Token& token);
	bool OnInHeadInsertion(const domparser::generic::Token& token);
	bool OnInHeadNoscriptInsertion(const domparser::generic::Token& token);
	bool OnAfterHeadInsertion(const domparser::generic::Token& token);
	bool OnInBodyInsertion(const domparser::generic::Token& token);
	bool OnTextInsertion(const domparser::generic::Token& token);
	bool OnInTableInsertion(const domparser::generic::Token& token);
	bool OnInTableTextInsertion(const domparser::generic::Token& token);
	bool OnInCaptionInsertion(const domparser::generic::Token& token);
	bool OnInColumnGroupInsertion(const domparser::generic::Token& token);
	bool OnInTableBodyInsertion(const domparser::generic::Token& token);
	bool OnInRowInsertion(const domparser::generic::Token& token);
	bool OnInCellInsertion(const domparser::generic::Token& token);
	bool OnInSelectInsertion(const domparser::generic::Token& token);
	bool OnInSelectInTableInsertion(const domparser::generic::Token& token);
	bool OnAfterBodyInsertion(const domparser::generic::Token& token);
	bool OnInFramesetInsertion(const domparser::generic::Token& token);
	bool OnAfterFramesetInsertion(const domparser::generic::Token& token);
	bool OnAfterAfterBodyInsertion(const domparser::generic::Token& token);
	bool OnAfterAfterFramesetInsertion(const domparser::generic::Token& token);

protected:
	bool OnInBodyStartTagInsertion(const domparser::generic::TagToken& tagToken);
	bool OnInBodyEndTagInsertion(const domparser::generic::TagToken& tagToken);

protected:
	static std::string InsertionModeToString(const InsertionMode& insertMode);

private:
	bool OnInitialInsertion_DOCTYPE(const domparser::generic::DocTypeToken& token);

private:
	bool IgnoreHtmlWhiteSpace(const domparser::generic::CharacterToken& token);

protected:
	const network::HttpUrl& url;
	Document* curDoc;
	html5::Tokeniser* tokeniser;

	InsertionMode insertionMode;
	InsertionMode orgInsertionMode;

	tools::Stack<Node*> openElementStack;

	HTMLHeadElement* headElement;
	HTMLFormElement* formElement;

private:
	bool scriptingFlag;
	bool framesetOk;
};

}
