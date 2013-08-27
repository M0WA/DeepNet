/**
 *
 * @file Relevance.h
 * @author Moritz Wagner
 * @date 16.06.2012
 *
 */

#pragma once

namespace queryserver {

/**
 * @brief implements relevance functionality for query results
 */
class Relevance
{
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
	bool operator==(const Relevance& rhs) const {
		return (this->GetWeightedRelevance() == rhs.GetWeightedRelevance());}

	bool operator<(const Relevance& rhs) const {
		return (this->GetWeightedRelevance() < rhs.GetWeightedRelevance()); }

	Relevance& operator+=(const Relevance& rhs) {
		this->relevance += rhs.relevance;
		this->weight += rhs.weight;
		return *this; }

public:
	double GetWeightedRelevance(void) const {
		return GetRelevance() * GetWeight(); }

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
