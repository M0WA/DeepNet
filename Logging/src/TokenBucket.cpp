/**
 * @file TokenBucket.cpp
 * @author Moritz Wagner
 * @date 07.02.2013
 */

#include "TokenBucket.h"

#include <unistd.h>

namespace tools {

TokenBucket::TokenBucket()
: threading::Thread(reinterpret_cast<threading::Thread::ThreadFunction>(&TokenBucket::RefillThreadFunc),true)
, curToken(0)
, maxToken(0)
, refillToken(0)
, refillFreq(1)
, isOverflowing(true){
}

TokenBucket::~TokenBucket() {

	Stop();
}

void TokenBucket::Start(const size_t& maxToken, const size_t& refillToken) {

	Reset();

	this->maxToken = maxToken;
	this->curToken = maxToken;
	this->refillToken = refillToken;

	StartThread(this);
}

void TokenBucket::Stop() {

	if(IsRunning()) {
		SetShallEnd();
		WaitForThread();
	}

	curToken = 0;
	maxToken = 0;
	refillToken = 0;
}

void TokenBucket::Reset() {

	Stop();
}

void* TokenBucket::RefillThreadFunc(threading::Thread::THREAD_PARAM* params) {

	TokenBucket* pInstance = reinterpret_cast<TokenBucket*>(params->pParam);

	while(!pInstance->ShallEnd()) {

		pInstance->lock.Lock();
		pInstance->curToken += pInstance->refillToken;
		if(pInstance->isOverflowing && pInstance->curToken > pInstance->maxToken) {
			pInstance->curToken = pInstance->maxToken; }
		pInstance->lock.Unlock();

		sleep(pInstance->refillFreq);
	}

	return 0;
}

bool TokenBucket::RemoveTokens(size_t tokenCount){

	if(!IsRunning())
		return false;

	size_t retryTimer = (refillFreq * 1000000) / 4;
	if( retryTimer <= 1000 )
		retryTimer = 1000;

	while(tokenCount>0){

		size_t requestTokens = tokenCount;
		if(isOverflowing && tokenCount > maxToken){
			requestTokens = maxToken; }

		requestTokens = TryRemoveTokens(requestTokens);
		tokenCount   -= requestTokens;

		usleep( retryTimer );
	}

	return true;
}

size_t TokenBucket::TryRemoveTokens(size_t tokenCount) {

	if(!IsRunning())
		return 0;

	lock.Lock();
	tokenCount = tokenCount > curToken ? curToken : tokenCount;
	curToken -= tokenCount;
	lock.Unlock();

	return tokenCount;
}

}
