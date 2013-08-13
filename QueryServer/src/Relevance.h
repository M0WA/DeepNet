/*
 * Relevance.h
 *
 *  Created on: 16.06.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <list>

namespace queryserver {

class Relevance
{
public:
	typedef struct _RelevancePointerComparator {
	  bool operator() (const Relevance* i,const Relevance* j) {
		  return ((*i)<(*j));
	  }
	} RelevancePointerComparator;

public:
	Relevance(const Relevance& rhs)
	: relevance(rhs.relevance)
	, weight(rhs.weight) { }

	Relevance(const double& relevance)
	: relevance(relevance)
	, weight(1.0) { }

	Relevance(const double& relevance, const double& weight)
	: relevance(relevance)
	, weight(weight) { }

private:
	Relevance()
	: relevance(1.0)
	, weight(1.0) { }

public:
	bool operator==(const Relevance& rhs)     const { return (GetWeightedRelevance() == rhs.GetWeightedRelevance());      }
	bool operator<(const Relevance& rhs)      const { return (this->GetWeightedRelevance() < rhs.GetWeightedRelevance()); }
	Relevance operator+(const Relevance& rhs) const { return Relevance(this->GetWeightedRelevance() + rhs.GetWeightedRelevance(), this->weight * rhs.weight); }
	Relevance operator*(const Relevance& rhs) const { return Relevance(this->relevance * rhs.relevance, this->weight * rhs.weight); }

public:
	double GetWeightedRelevance(void) const { return GetRelevance() * GetWeight(); }

public:
	const double& GetRelevance(void) const { return relevance; }
	const double& GetWeight(void)    const { return weight;    }

	void SetRelevance(const double& in) { relevance = in; }
	void SetWeight(const double& in)    { weight    = in; }

private:
	double relevance;
	double weight;
};

}
