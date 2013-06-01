/**
 *
 * @file MutationRecord.cpp
 * @author Moritz Wagner
 * @date Mar 6, 2013
 *
 * TODO: description for this file
 *
 */

#include "MutationRecord.h"

namespace domparser {

MutationRecord::MutationRecord()
: target(0)
, previousSibling(0)
, nextSibling(0){
}

MutationRecord::~MutationRecord() {
}

}
