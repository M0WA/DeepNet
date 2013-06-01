/**
 *
 * @file Token.h
 * @author Moritz Wagner
 * @date Mar 3, 2013
 *
 * TODO: description for this file
 *
 */

#pragma once

#include <string>
#include <vector>

namespace domparser {

class AttributeToken {
public:
	std::string name;
	std::string value;

	void Reset() {
		name.clear();
		value.clear();
	}
};

class Token {
public:
	enum TokenType {
		TAG,
		COMMENT,
		CHAR,
		DOCTYPE,
	};

public:
	Token(const TokenType& type);
	virtual ~Token();

	virtual void Reset()=0;
	virtual std::string ToString() const;
	virtual std::string ToXML() const;

	const TokenType type;
};

class TagToken : public Token {
public:
	enum TagTokenType {
		INVALID_TYPE,
		START_TAG,
		END_TAG,
	};

public:
	TagToken() : Token(TAG) {}
	virtual ~TagToken() {}

	std::string name;
	TagTokenType tagType;
	bool selfClosingFlag;
	std::vector<AttributeToken> attributes;
	AttributeToken curAttrib;

	virtual void Reset() {
		name.clear();
		tagType = INVALID_TYPE;
		selfClosingFlag = false;
		attributes.clear();

		curAttrib.Reset();
	}
};

class CharacterToken : public Token {
public:
	CharacterToken() : Token(CHAR) { }
	virtual ~CharacterToken() {}

	std::string text;

	void Append(const char* p, size_t s) {
		text.append(p,s);
	}

	virtual void Reset() {
		text.clear();
	}
};

class CommentToken : public Token {
public:
	CommentToken() : Token(COMMENT) {}
	virtual ~CommentToken() {}

	std::string comment;

	virtual void Reset() {
		comment.clear();
	}
};

class DocTypeToken : public Token {

public:
	DocTypeToken()
	: Token(DOCTYPE)
	, pName(0)
	, pPublicIdentifier(0)
	, pSystemIdentifier(0)
	{ }
	virtual ~DocTypeToken() {}

	std::string* pName;
	std::string* pPublicIdentifier;
	std::string* pSystemIdentifier;
	bool force_quirks;

	virtual void Reset() {

		pName = 0;
		pPublicIdentifier = 0;
		pSystemIdentifier = 0;

		name.clear();
		public_identifier.clear();
		system_identifier.clear();

		force_quirks = false;
	}

	std::string name;
	std::string public_identifier;
	std::string system_identifier;
};

}
