/**
 *
 * @file NodeFactory.cpp
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#include "NodeFactory.h"

#include "Token.h"
#include "Node.h"
#include "Document.h"
#include "DocumentType.h"
#include "Element.h"
#include "Comment.h"

namespace htmlparser {

NodeFactory::NodeFactory(Document* doc, DatabaseUrl* baseUrl, const Token& token)
: doc(doc)
, baseUrl(baseUrl)
, token(token) {
}

NodeFactory::~NodeFactory() {
}

Node* NodeFactory::FromToken(Document* doc, DatabaseUrl* baseUrl, const Token& token) {

	NodeFactory instance(doc,baseUrl,token);
	return instance.FromToken();
}

Node* NodeFactory::FromToken() {

	Node* newNode = 0;
	switch(token.type) {

	case Token::TAG:
		newNode = CreateElement(dynamic_cast<const TagToken&>(token));
		break;

	case Token::COMMENT:
		newNode = CreateComment(dynamic_cast<const CommentToken&>(token));
		break;

	case Token::DOCTYPE:
		newNode = CreateDoctype(dynamic_cast<const DocTypeToken&>(token));
		break;

	case Token::CHAR:
	default:
		break;
	}

	if(!newNode)
		return 0;

	newNode->baseURI = baseUrl;
	return newNode;
}

Node* NodeFactory::CreateElement(const TagToken& tagToken) {

	Element* pElement = doc->createElement(tagToken.name);

	std::vector<AttributeToken>::const_iterator iterAttr = tagToken.attributes.begin();
	for(;iterAttr != tagToken.attributes.end();++iterAttr) {
		pElement->setAttribute(iterAttr->name,iterAttr->value); }

	return dynamic_cast<Node*>(pElement);
}

Node* NodeFactory::CreateComment(const CommentToken& commentToken) {
	Comment* pComment = doc->createComment(commentToken.comment);
	return dynamic_cast<Node*>(pComment);
}

Node* NodeFactory::CreateDoctype(const DocTypeToken& doctypeToken) {
	DocumentType* docType =
			doc->implementation.createDocumentType(
					doctypeToken.name,
					doctypeToken.public_identifier,
					doctypeToken.system_identifier);
	return dynamic_cast<Node*>(docType);
}

}
