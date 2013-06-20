/**
 *
 * @file NodeFactory.cpp
 * @author Moritz Wagner
 * @date 03.03.2013
 *
 */

#include "NodeFactory.h"

#include "generic/Token.h"

#include "Node.h"
#include "Document.h"
#include "DocumentType.h"
#include "Element.h"
#include "Comment.h"

namespace domparser {

NodeFactory::NodeFactory(Document* doc, DatabaseUrl* baseUrl, const domparser::generic::Token& token)
: doc(doc)
, baseUrl(baseUrl)
, token(token) {
}

NodeFactory::~NodeFactory() {
}

Node* NodeFactory::FromToken(Document* doc, DatabaseUrl* baseUrl, const domparser::generic::Token& token) {

	NodeFactory instance(doc,baseUrl,token);
	return instance.FromToken();
}

Node* NodeFactory::FromToken() {

	Node* newNode = 0;
	switch(token.type) {

	case domparser::generic::Token::TAG:
		newNode = CreateElement(dynamic_cast<const domparser::generic::TagToken&>(token));
		break;

	case domparser::generic::Token::COMMENT:
		newNode = CreateComment(dynamic_cast<const domparser::generic::CommentToken&>(token));
		break;

	case domparser::generic::Token::DOCTYPE:
		newNode = CreateDoctype(dynamic_cast<const domparser::generic::DocTypeToken&>(token));
		break;

	case domparser::generic::Token::CHAR:
	default:
		break;
	}

	if(!newNode)
		return 0;

	newNode->baseURI = baseUrl;
	return newNode;
}

Node* NodeFactory::CreateElement(const domparser::generic::TagToken& tagToken) {

	Element* pElement = doc->createElement(tagToken.name);

	std::vector<domparser::generic::AttributeToken>::const_iterator iterAttr = tagToken.attributes.begin();
	for(;iterAttr != tagToken.attributes.end();++iterAttr) {
		pElement->setAttribute(iterAttr->name,iterAttr->value); }

	return dynamic_cast<Node*>(pElement);
}

Node* NodeFactory::CreateComment(const domparser::generic::CommentToken& commentToken) {
	Comment* pComment = doc->createComment(commentToken.comment);
	return dynamic_cast<Node*>(pComment);
}

Node* NodeFactory::CreateDoctype(const domparser::generic::DocTypeToken& doctypeToken) {
	DocumentType* docType =
			doc->implementation.createDocumentType(
					doctypeToken.name,
					doctypeToken.public_identifier,
					doctypeToken.system_identifier);
	return dynamic_cast<Node*>(docType);
}

}
