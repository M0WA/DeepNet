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

class QueryXmlResponse: public fastcgiserver::FastCGIResponse {
public:
	QueryXmlResponse(QueryThreadManager& queryManager,QueryXmlRequest* xmlQueryRequest);
	virtual ~QueryXmlResponse();

	virtual bool Process(FCGX_Request& request);

private:
	void AssembleXMLResult(const std::vector<QueryThreadResultEntry*>& results);
	void MergeDuplicates(std::vector<QueryThreadResultEntry*>& results);

private:
	struct SecondLevelDomainGroupByFunc : public std::unary_function<QueryThreadResultEntry*,bool> {

		SecondLevelDomainGroupByFunc(database::DatabaseConnection* db,std::vector< std::vector<QueryThreadResultEntry*> >& groupedResults);

		bool operator() (QueryThreadResultEntry*& entry);

		database::DatabaseConnection* db;
		std::vector< std::vector<QueryThreadResultEntry*> >& groupedResults;
		std::map<long long,size_t> mapSecondlevelDomainPos;
	};

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

