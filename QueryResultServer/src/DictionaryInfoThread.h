/**
 *
 * @file DictionaryInfoThread.h
 * @author Moritz Wagner
 * @date 27.08.2013
 *
 */

#pragma once

#include <vector>
#include <map>
#include <string>

#include <Thread.h>

namespace database {
	class DatabaseConnection;
	class WhereConditionTableColumnCreateParam;
}

namespace queryserver {

	class Query;

/**
 * @brief helper class for queryserver::QueryThread classes that need infos from the dictionary
 */
class DictionaryInfoThread: public threading::Thread {

public:
	/**
	 * @brief enumeration type for different match types
	 */
	typedef enum {

		/**
		 * not a match at all
		 */
		INVALID_MATCH_TYPE,

		/**
		 * exact match
		 */
		EXACT_MATCH,

		/**
		 * case insensitive match
		 */
		CASEINSENSITIVE_MATCH,

		/**
		 * keyword is similar
		 */
		SIMILAR_MATCH,

	} KeywordMatchType;

public:
	/**
	 * create from database connection and associated query
	 * @param dbConn database connection
	 * @param query query
	 */
	DictionaryInfoThread(database::DatabaseConnection* dbConn,const Query& query);
	virtual ~DictionaryInfoThread();

public:
	/**
	 * gets match type for a certain dictionary id
	 * @param dictID dictionary id to lookup
	 * @return keyword match type
	 */
	KeywordMatchType GetMatchTypeForDictionaryID(const long long& dictID) const;

	/**
	 * gets keyword position for a given dict id
	 * @param dictID dictionary id
	 * @return position of keyword in query
	 */
	size_t GetPositionForDictionaryID(const long long& dictID) const;

public:
	/**
	 * maps DICT_ID and position of the keyword in the Query
	 */
	std::map<size_t, std::vector<long long> > exactMatchDictIDs;

	/**
	 * contains all case insensitve matches except the exact matches
	 */
	std::map<size_t, std::vector<long long> > caseInsensitiveDictIDs;

	/**
	 * contains all similar matches except above
	 */
	std::map<size_t, std::vector<long long> > similarDictIDs;

	/**
	 * contains all keyword ids (exact,case-insensitive and similar)
	 */
	std::vector<long long> allKeywordIDs;

private:
	bool IsInVector(const std::map<size_t, std::vector<long long> >& map,const long long& dictID) const;
	bool IsInVector(size_t& pos,const std::map<size_t, std::vector<long long> >& map,const long long& dictID) const;
	bool GetIDsForKeywords(
		const std::vector<std::string>& vecKey,
		database::WhereConditionTableColumnCreateParam& whereKeywordCreate,
		std::vector<long long>& excludeDictIDs,
		std::map<size_t, std::vector<long long> >& mapPositionDictIDs);

	bool GetIDsForKeywords(std::vector<long long>& excludeDictIDs);
	bool GetIDsForCaseInsensitiveKeywords(std::vector<long long>& excludeDictIDs);
	bool GetIDsForSimilarKeywords(std::vector<long long>& excludeDictIDs);

private:
	static void* DictionaryInfoThreadFunction(threading::Thread::THREAD_PARAM* threadParam);

private:
	database::DatabaseConnection* dbConn;
	const Query& query;
};

}

