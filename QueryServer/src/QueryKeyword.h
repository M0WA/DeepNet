/**
 *
 * @file QueryKeyword.h
 * @author Moritz Wagner
 * @date 14.08.2013
 *
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace database {
	class DatabaseConnection;
	class WhereConditionTableColumnCreateParam;
}

namespace queryserver {

/**
 * @brief encapsulates a single keyword in a QueryKeywordGroup
 */
class QueryKeyword {
public:
	typedef enum {

		/**
		 * invalid match type
		 */
		INVALID_MATCH_TYPE = 0,

		/**
		 * matches exactly
		 */
		EXACT_MATCH 			= 0x01,

		/**
		 * matches case insensitive
		 */
		CASEINSENSITIVE_MATCH	= 0x02,

		/**
		 * is similar to keyword
		 */
		SIMILAR_MATCH	        = 0x04,
	} QueryKeywordType;

private:
	typedef struct _QueryKeyWordEntry {
		_QueryKeyWordEntry();
		_QueryKeyWordEntry(const std::string& keyword, const long long& id = -1, const long long& occurrence = -1);

		bool operator== (const std::string &keyword) const {
		    return (this->keyword.compare(keyword) == 0); }

		std::string keyword;
		long long id;
		long long occurrence;
	} QueryKeyWordEntry;

	typedef struct _QueryKeywordEntryToDictID : public std::unary_function<QueryKeyWordEntry,bool> {
		_QueryKeywordEntryToDictID(std::vector<long long>& ids) : ids(ids) {}

		bool operator() (const QueryKeyWordEntry& e) {
			ids.push_back(e.id);
			return true;}

	private:
		std::vector<long long>& ids;
	} QueryKeywordEntryToDictID;

	typedef struct _QueryKeywordEntryToKeyword : public std::unary_function<QueryKeyWordEntry,bool> {
		_QueryKeywordEntryToKeyword(std::vector<std::string>& keywords) : keywords(keywords) {}

		bool operator() (const QueryKeyWordEntry& e) {
			keywords.push_back(e.keyword);
			return true;}

	private:
		std::vector<std::string>& keywords;
	} QueryKeywordEntryToKeyword;

private:
	QueryKeyword();

public:
	/**
	 * constructs keywords from string and match type
	 * @param keyword keyword string
	 */
	QueryKeyword(const std::string& keyword);
	virtual ~QueryKeyword();

public:
	/**
	 * initialize keyword
	 * @param db database connection
	 * @param types types to initialize
	 * @return true on success, false on error
	 */
	bool Init(
			database::DatabaseConnection *db,
			QueryKeyword::QueryKeywordType types);

	/**
	 * gets dictionary ids by keyword types
	 * @param types keyword types
	 * @param dictIDs dictionary ids
	 */
	void GetDictIDByType(
			QueryKeywordType types,
			std::map<QueryKeywordType, std::vector<long long> >& dictIDs) const;

	/**
	 * gets keywords by keyword types
	 * @param types keyword types
	 * @param keywords keywords
	 */
	void GetKeywordsByType(
			QueryKeywordType types,
			std::map<QueryKeywordType, std::vector<std::string> >& keywords) const;

private:
	bool InitExactKeywords(void);
	bool InitCaseInsensitiveKeywords(void);
	bool InitSimilarKeywords(void);

	bool InitIDsForKeywords(
			database::DatabaseConnection *db,
			std::vector<QueryKeyWordEntry>& entries,
			database::WhereConditionTableColumnCreateParam& where,
			std::vector<long long>& excludeDictIDs);

private:
	static void GetWhereForType(
			QueryKeyword::QueryKeywordType type,
			database::WhereConditionTableColumnCreateParam& where);

private:
	std::string keyword;

private:
	std::map< QueryKeywordType, std::vector<QueryKeyWordEntry>  > map;
};

}

