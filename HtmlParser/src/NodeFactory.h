/**
 *
 * @file NodeFactory.h
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

namespace htmlparser {
	class Token;
	class TagToken;
	class CommentToken;
	class DocTypeToken;
	class Node;
	class DatabaseUrl;
	class Document;

class NodeFactory {
private:
	NodeFactory(Document* doc, DatabaseUrl* baseUrl, const Token& token);
public:
	virtual ~NodeFactory();

	static Node* FromToken(Document* doc, DatabaseUrl* baseUrl, const Token& token);

private:
	Node* FromToken();
	Node* CreateElement(const TagToken& tagToken);
	Node* CreateComment(const CommentToken& commentToken);
	Node* CreateDoctype(const DocTypeToken& doctypeToken);

private:
	Document* doc;
	DatabaseUrl* baseUrl;
	const Token& token;
};

}
