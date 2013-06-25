/**
 *
 * @file DOMException.h
 * @author Moritz Wagner
 * @date 21.06.2013
 *
 */

#pragma once

#include <Exception.h>

namespace domparser {

namespace dom3 {

class DOMException : public errors::Exception {

public:
	typedef enum  {
		INDEX_SIZE_ERR                 = 1,
		DOMSTRING_SIZE_ERR             = 2,
		HIERARCHY_REQUEST_ERR          = 3,
		WRONG_DOCUMENT_ERR             = 4,
		INVALID_CHARACTER_ERR          = 5,
		NO_DATA_ALLOWED_ERR            = 6,
		NO_MODIFICATION_ALLOWED_ERR    = 7,
		NOT_FOUND_ERR                  = 8,
		NOT_SUPPORTED_ERR              = 9,
		INUSE_ATTRIBUTE_ERR            = 10,
		INVALID_STATE_ERR              = 11,
		SYNTAX_ERR                     = 12,
		INVALID_MODIFICATION_ERR       = 13,
		NAMESPACE_ERR                  = 14,
		INVALID_ACCESS_ERR             = 15,
		VALIDATION_ERR                 = 16,
		TYPE_MISMATCH_ERR              = 17,
	} ExceptionCode;

public:
	DOMException(
			const std::string& file,
			const int line,
			const std::string& function,
			const ExceptionCode& error);
	virtual ~DOMException();

public:
	const ExceptionCode& code() const { return error; }

private:
	ExceptionCode error;
};

}

}
