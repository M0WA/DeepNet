/*
 * Word.h
 *
 *  Created on: 11.03.2012
 *      Author: Moritz Wagner
 */

#pragma once

#include <string>
#include <vector>
#include <map>

namespace indexing {

class Word {

public:
	Word(const std::string& word);
	virtual ~Word();

	bool operator==(const Word& rhs) const
	{
		return (this->word.compare(rhs.word)==0);
	}

	bool operator<(const Word& rhs) const
	{
		return (this->word.compare(rhs.word)<0);
	}

	inline const char* const GetChars() const { return word.c_str(); }
	inline const std::string& GetString() const { return word; }
	inline long long GetOccurrences() const { return occurrences; }
	inline void IncrementOccurrences(const long long occurrences = 1) const { this->occurrences += occurrences;}
	inline void AddPosition(const std::pair<long long,long long>& position) const { paragraphPositions.push_back(position); }
	inline const std::vector<std::pair<long long,long long> >& GetPositions() const { return paragraphPositions; }

private:
	std::string word;
	mutable std::vector<std::pair<long long,long long> > paragraphPositions;
	mutable long long occurrences;
};

}
