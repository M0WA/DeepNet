/**
 *
 * @file QueryXmlResponse.h
 * @author Moritz Wagner
 * @date 13.08.2013
 *
 */

#pragma once

#include <vector>
#include <map>

#include <FastCGIResponse.h>

namespace database {
	class DatabaseConnection;
}

namespace queryserver {

	class QueryThreadManager;
	class QueryXmlRequest;
	class QueryThreadResultEntry;

/**
 * @brief encapsulates a xml query request
 */
class QueryXmlResponse: public fastcgiserver::FastCGIResponse {
public:
	QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest);
	virtual ~QueryXmlResponse();

private:
	virtual bool Process(FCGX_Request& request);

private:
	void AssembleXMLResult(const std::vector<QueryThreadResultEntry*>& results);
	void MergeDuplicates(std::vector<QueryThreadResultEntry*>& results);

private:
	/**
	 * @brief functor to group results vector by secondlevel domain id
	 */
	struct SecondLevelDomainGroupByFunc : public std::unary_function<QueryThreadResultEntry*,bool> {

		SecondLevelDomainGroupByFunc(database::DatabaseConnection* db,std::vector< std::vector<QueryThreadResultEntry*> >& groupedResults);

		bool operator() (QueryThreadResultEntry*& entry);

		database::DatabaseConnection* db;
		std::vector< std::vector<QueryThreadResultEntry*> >& groupedResults;
		std::map<long long,size_t> mapSecondlevelDomainPos;
	};

	/**
	 * @brief functor to select the first item of a result vector and put it into another vector
	 */
	struct SelectFirstGroupedResultsFunc : public std::unary_function< const std::vector<QueryThreadResultEntry*>& ,bool> {

		SelectFirstGroupedResultsFunc(std::vector<QueryThreadResultEntry*>& results);

		bool operator() (const std::vector<QueryThreadResultEntry*>& entry);

		std::vector<QueryThreadResultEntry*>& results;
	};

private:
	QueryThreadManager& queryManager;
	QueryXmlRequest* xmlQueryRequest;
};

}

