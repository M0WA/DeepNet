/**
 * @file TokenBucket.h
 * @author Moritz Wagner
 * @date 07.02.2013
 */

#pragma once

#include <cstddef>

#include <Thread.h>
#include <Mutex.h>

namespace tools {

/**
 * @brief implements a token bucket pattern.
 * used for bandwidth measuring. for more info
 * check http://en.wikipedia.org/wiki/Token_bucket
 */
class TokenBucket : private threading::Thread {
public:
	TokenBucket();
	virtual ~TokenBucket();

	/**
	 * start the token bucket.
	 * @param maxToken maximum items in token bucket.
	 * @param refillToken items to refill per second.
	 */
	void Start(const size_t& maxToken, const size_t& refillToken);

	/**
	 * stop the token bucket.
	 */
	void Stop();

	/**
	 * reset the token bucket.
	 */
	void Reset();

	/**
	 * waits till a certain number of tokens have been removed.
	 * @param tokenCount number of tokens to remove.
	 * @return false on error, true on success.
	 */
	bool RemoveTokens(size_t tokenCount);

	/**
	 * tries to remove a certain number of tokens.
	 * @param tokenCount number of tokens to remove.
	 * @return number of tokens actually removed.
	 */
	size_t TryRemoveTokens(size_t tokenCount);

private:
	static void* RefillThreadFunc(threading::Thread::THREAD_PARAM* params);

private:
	size_t curToken;
	size_t maxToken;
	size_t refillToken;
	size_t refillFreq; //in seconds

	bool isOverflowing;

	threading::Mutex lock;
};

}
