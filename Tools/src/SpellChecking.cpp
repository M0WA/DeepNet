/**
 * @file SpellChecking.cpp
 * @author Moritz Wagner
 * @date 08.06.2012
 */

#include "SpellChecking.h"
#include "StringTools.h"

#include "Logging.h"

namespace tools {

SpellChecking::SpellChecking()
: instanceHunspell(NULL)
{
}

SpellChecking::~SpellChecking()
{
	if(instanceHunspell)
		delete instanceHunspell;
	instanceHunspell = NULL;
}

bool SpellChecking::InitSpellChecking(const std::string& dictionaryFile, const std::string& affixFile)
{
	instanceHunspell = new Hunspell(dictionaryFile.c_str(), affixFile.c_str());
	instanceHunspell->add_dic(dictionaryFile.c_str());
	return true;
}

bool SpellChecking::GenerateProposals(const std::string& keyword, bool& spelledCorrectly, std::vector<std::string>& proposals)
{
	if(!instanceHunspell)
		throw;

	spelledCorrectly = (instanceHunspell->spell(keyword.c_str()) > 0);

	char ** wlst = 0;
	int ns = instanceHunspell->suggest(&wlst,keyword.c_str());
	for (int i=0; i < ns; i++) {
		proposals.push_back(wlst[i]);}
	if(wlst)
		instanceHunspell->free_list(&wlst, ns);
	return (bool)ns;
}

}
