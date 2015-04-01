/**
 *
 * @file src/NodeFactory.h
 * @author Moritz Wagner
 * @date 03.03.2013
 *
 */

#pragma once

namespace domparser {

	namespace generic {
		class Token;
		class TagToken;
		class CommentToken;
		class DocTypeToken;
	}

	class Node;
	class DatabaseUrl;
	class Document;

/**
 * @brief factory class for generic DOM nodes
 */
class NodeFactory {
private:
	/**
	 * constructs a node factory instance
	 * @param doc parent document
	 * @param baseUrl url for this node
	 * @param token tag name/token of this node
	 * @see domparser::NodeFactory::FromToken
	 */
	NodeFactory(Document* doc, DatabaseUrl* baseUrl, const domparser::generic::Token& token);
public:
	virtual ~NodeFactory();

	/**
	 * constructs a node from a token
	 * @param doc parent document
	 * @param baseUrl base url of this node
	 * @param token tag token
	 * @return created node
	 */
	static Node* FromToken(Document* doc, DatabaseUrl* baseUrl, const domparser::generic::Token& token);

private:
	Node* FromToken();
	Node* CreateElement(const domparser::generic::TagToken& tagToken);
	Node* CreateComment(const domparser::generic::CommentToken& commentToken);
	Node* CreateDoctype(const domparser::generic::DocTypeToken& doctypeToken);

private:
	Document* doc;
	DatabaseUrl* baseUrl;
	const domparser::generic::Token& token;
};

}
