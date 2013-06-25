/**
 *
 * @file ErrorNamesTable.h
 * @author Moritz Wagner
 * @date 25.06.2013
 *
 */

#pragma once

#include <vector>
#include <string>

#include <Mutex.h>

namespace domparser {

namespace dom3 {

class ErrorNamesTable {
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

		SECURITY_ERR,
		NETWORK_ERR,
		ABORT_ERR,
		URL_MISMATCH_ERR,
		QUOTA_EXCEEDED_ERR,
		TIMEOUT_ERR,
		INVALID_NODE_TYPE_ERR,
		DATA_CLONE_ERR,

		MAX_ERROR_CODE
	} DOMErrorCode;

	class ErrorNamesTableEntry {
	public:
		ErrorNamesTableEntry(
			const std::string& name,
			const std::string& description,
			const DOMErrorCode& code)
		: name(name)
		, description(description)
		, code(code)
		{}

	public:
		bool operator==(const std::string& rhsName) const {
			return name.compare(rhsName) == 0; }

	public:
		bool IsValidEntry() const {
			bool isValid = !name.empty();
			isValid &= code != MAX_ERROR_CODE;
			return isValid;	}

	public:
		static ErrorNamesTableEntry GetInvalidEntry() {
			return ErrorNamesTableEntry("","",MAX_ERROR_CODE); }

	public:
		std::string name;
		std::string description;
		DOMErrorCode code;
	};

private:
	ErrorNamesTable();
public:
	virtual ~ErrorNamesTable();

public:
	static ErrorNamesTableEntry GetEntryByName(const std::string& name);

private:
	static void InitTable();

private:
	static std::vector<ErrorNamesTableEntry> errorNamesTable;
	static threading::Mutex initTableMutex;
};

}

}
