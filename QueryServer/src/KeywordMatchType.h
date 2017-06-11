#pragma once

namespace queryserver {
	/**
	 * @brief enumeration type for different match types
	 */
	typedef enum _KeywordMatchType {

		/**
		 * not a match at all
		 */
		INVALID_MATCH_TYPE = 0,

		/**
		 * exact match
		 */
		EXACT_MATCH = 1,

		/**
		 * case insensitive match
		 */
		CASEINSENSITIVE_MATCH = 2,

		/**
		 * keyword is similar
		 */
		SIMILAR_MATCH = 3,

		/**
		 * do not use
		 */
		MAX_MATCH_TYPE,

	} KeywordMatchType;
}
