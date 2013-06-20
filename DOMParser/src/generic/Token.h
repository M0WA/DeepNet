/**
 *
 * @file Token.h
 * @author Moritz Wagner
 * @date 03.03.2013
 *
 */

#pragma once

#include <string>
#include <vector>

namespace domparser {

namespace generic {

/**
 * @brief token representing an DOM node attribute
 * attributes are special,
 * @see domparser::Token for more generic tokens
 */
class AttributeToken {
public:
	/**
	 * name of the attribute
	 */
	std::string name;

	/**
	 * value of the attribute
	 */
	std::string value;

	/**
	 * reset this attribute token
	 */
	void Reset() {
		name.clear();
		value.clear();
	}
};

/**
 * @brief generic token
 * @see domparser::html5::Tokeniser
 */
class Token {
public:
	/**
	 * @enum TokenType
	 * type of token
	 */
	enum TokenType {
		/**
		 * tag token
		 */
		TAG,

		/**
		 * commentary token
		 */
		COMMENT,

		/**
		 * character token
		 */
		CHAR,

		/**
		 * doytype token
		 */
		DOCTYPE,
	};

public:
	/**
	 * constructs a token from it's type
	 */
	Token(const TokenType& type);
	virtual ~Token();

	/**
	 * resets this token
	 */
	virtual void Reset()=0;

	/**
	 * dumps token to string
	 * @return token as string
	 */
	virtual std::string ToString() const;

	/**
	 * dumps token to xml
	 * @return token as xml
	 */
	virtual std::string ToXML() const;

	/**
	 * type of token
	 */
	const TokenType type;
};

/**
 * @brief implements a token of the type TAG
 */
class TagToken : public Token {
public:
	/**
	 * @enum TagTokenType
	 * type of TAG token
	 */
	enum TagTokenType {

		/**
		 * invalid, do not use
		 */
		INVALID_TYPE,

		/**
		 * starting tag
		 */
		START_TAG,

		/**
		 * closing tag
		 */
		END_TAG,
	};

public:
	/**
	 * constructs an empty tag token
	 */
	TagToken() : Token(TAG) {}
	virtual ~TagToken() {}

	/**
	 * name of this tag
	 */
	std::string name;

	/**
	 * tag type
	 * @see domparser::TagToken::TagTokenType
	 */
	TagTokenType tagType;

	/**
	 * is token self closing
	 */
	bool selfClosingFlag;

	/**
	 * list of attributes for this tag
	 */
	std::vector<AttributeToken> attributes;

	/**
	 * current attribute token, needed while parsing
	 */
	AttributeToken curAttrib;

	/**
	 * resets tag token
	 */
	virtual void Reset() {
		name.clear();
		tagType = INVALID_TYPE;
		selfClosingFlag = false;
		attributes.clear();

		curAttrib.Reset();
	}
};

/**
 * @brief represents a CharacterToken
 */
class CharacterToken : public Token {
public:
	/**
	 * constructs empty character token
	 */
	CharacterToken() : Token(CHAR) { }
	virtual ~CharacterToken() {}

	/**
	 * containing text
	 */
	std::string text;

	/**
	 * appends text to character token
	 * @param p string to append
	 * @param s number of characters to append
	 */
	void Append(const char* p, size_t s) {
		text.append(p,s);
	}

	/**
	 * resets this token
	 */
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

}
