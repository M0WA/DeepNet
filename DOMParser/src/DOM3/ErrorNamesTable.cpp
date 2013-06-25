/**
 *
 * @file ErrorNamesTable.cpp
 * @author Moritz Wagner
 * @date 25.06.2013
 *
 */

#include "ErrorNamesTable.h"

#include <algorithm>

namespace domparser {

namespace dom3 {

std::vector<ErrorNamesTable::ErrorNamesTableEntry> ErrorNamesTable::errorNamesTable;
threading::Mutex ErrorNamesTable::initTableMutex;

ErrorNamesTable::ErrorNamesTableEntry::ErrorNamesTableEntry(
	const std::string& name,
	const std::string& description,
	const DOMErrorCode& code)
: name(name)
, description(description)
, code(code)
{
}

bool ErrorNamesTable::ErrorNamesTableEntry::operator==(const std::string& rhsName) const {
	return name.compare(rhsName) == 0;
}

bool ErrorNamesTable::ErrorNamesTableEntry::IsValidEntry() const {
	bool isValid = !name.empty();
	isValid &= code != MAX_ERROR_CODE;
	return isValid;
}

ErrorNamesTable::ErrorNamesTableEntry GetInvalidEntry() {
	return ErrorNamesTable::ErrorNamesTableEntry("","",ErrorNamesTable::MAX_ERROR_CODE);
}

ErrorNamesTable::ErrorNamesTable() {
}

ErrorNamesTable::~ErrorNamesTable() {
}

void ErrorNamesTable::InitTable() {

	threading::AutoMutex lock(initTableMutex);
	if(errorNamesTable.size() > 0)
		return; //is already initialized

	errorNamesTable.push_back(ErrorNamesTableEntry("IndexSizeError","The index is not in the allowed range.",INDEX_SIZE_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("HierarchyRequestError","The operation would yield an incorrect node tree.",HIERARCHY_REQUEST_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("WrongDocumentError","The object is in the wrong document.",WRONG_DOCUMENT_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("InvalidCharacterError","The string contains invalid characters.",INVALID_CHARACTER_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("NoModificationAllowedError","The object can not be modified.",NO_MODIFICATION_ALLOWED_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("NotFoundError","The object can not be found here.",NOT_FOUND_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("NotSupportedError","The operation is not supported.",NOT_SUPPORTED_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("InvalidStateError","The object is in an invalid state.",INVALID_STATE_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("SyntaxError","The string did not match the expected pattern.",SYNTAX_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("InvalidModificationError","The object can not be modified in this way.",INVALID_MODIFICATION_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("NamespaceError","The operation is not allowed by Namespaces in XML.",NAMESPACE_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("InvalidAccessError","The object does not support the operation or argument.",INVALID_ACCESS_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("SecurityError","The operation is insecure.",SECURITY_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("NetworkError","A network error occurred.",NETWORK_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("AbortError","The operation was aborted.",ABORT_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("URLMismatchError","The given URL does not match another URL.",URL_MISMATCH_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("QuotaExceededError","The quota has been exceeded.",QUOTA_EXCEEDED_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("TimeoutError","The operation timed out.",TIMEOUT_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("InvalidNodeTypeError","The supplied node is incorrect or has an incorrect ancestor for this operation.",INVALID_NODE_TYPE_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("DataCloneError","The object can not be cloned.",DATA_CLONE_ERR));
	errorNamesTable.push_back(ErrorNamesTableEntry("EncodingError","The encoding operation (either encoded or decoding) failed.",MAX_ERROR_CODE));
}

ErrorNamesTable::ErrorNamesTableEntry ErrorNamesTable::GetEntryByName(const std::string& name) {

	ErrorNamesTable::InitTable();

	std::vector<ErrorNamesTableEntry>::const_iterator i = std::find(errorNamesTable.begin(),errorNamesTable.end(),name);
	if(i == errorNamesTable.end())
		return ErrorNamesTableEntry::GetInvalidEntry();
	else
		return *i;
}

}

}
