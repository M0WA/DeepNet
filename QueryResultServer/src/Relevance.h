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
	Relevance(const double& relevance)
	: relevance(relevance)
	, weight(1.0) { }

	Relevance(const double& relevance, const double& weight)
	: relevance(relevance)
	, weight(weight) { }

public:
	/**
	 * compares values of two relevances
	 * @param rhs relevance to compare to
	 * @return true if smaller, else false
	 */
	bool operator<(const Relevance& rhs) const {
		return (this->GetWeightedRelevance() < rhs.GetWeightedRelevance()); }

	/**
	 * sums up to relevances storing result in current instance
	 * @param rhs relevance to add
	 * @return new relevance
	 */
	Relevance& operator+=(const Relevance& rhs) {
		this->relevance += rhs.relevance;
		this->weight += rhs.weight;
		return *this; }

public:
	/**
	 * gets calculated relevance value
	 * @return calculated relevance
	 */
	double GetWeightedRelevance(void) const {
		return GetRelevance() * GetWeight(); }

	/**
	 * gets relevance value
	 * @return relevance
	 */
	const double& GetRelevance(void) const { return relevance; }

	/**
	 * gets weight value
	 * @return weight
	 */
	const double& GetWeight(void) const { return weight; }

private:
	double relevance;
	double weight;
};

}
