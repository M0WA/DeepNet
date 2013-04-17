/**
 * @file SpellChecking.h
 * @author Moritz Wagner
 * @date 08.06.2012
 */

#pragma once

#include <hunspell/hunspell.hxx>
#include <string>
#include <vector>

namespace tools {

/**
 * @brief spell checking and suggestion generator.
 */
class SpellChecking
{
public:
	SpellChecking();
	virtual ~SpellChecking();

public:
	/**
	 * initialize spell checking dictionary.
	 * @param dictionaryFile dictionary filename.
	 * @param affixFile affix filename.
	 * @return false on error, true on success.
	 */
	bool InitSpellChecking(const std::string& dictionaryFile, const std::string& affixFile);

	/**
	 * generates suggestions based on keyword.
	 * @param keyword keyword.
	 * @param spelledCorrectly true if spelled correctly.
	 * @param proposals list of proposals.
	 * @return false on error, true on success.
	 */
	bool GenerateProposals(const std::string& keyword, bool& spelledCorrectly, std::vector<std::string>& proposals);

private:
	Hunspell* instanceHunspell;
};

}
