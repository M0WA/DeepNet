/*
 * Word.cpp
 *
 *  Created on: 11.03.2012
 *      Author: Moritz Wagner
 */

#include "Word.h"

namespace indexing {

Word::Word(const std::string& word)
: word(word)
, occurrences(1)
{
}

Word::~Word() {
}

}
