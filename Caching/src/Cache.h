/**
 * @file Cache.h
 * @author Moritz Wagner
 * @date 06.03.2012
 */

#pragma once

#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stdexcept>

#include <ReadWriteLock.h>
#include <Logging.h>

#include <Exception.h>

namespace caching
{

/**
 * @brief generic thread-safe caching class.
 * thread-safe class for caching generic items by key/value.
 */
template <class T, class V>
class Cache {

public:
	/**
	 * construct cache with size limit.
	 * @param limit maximum number of elements in cache.
	 * @param deleteOnGet true: deletes items when read from cache (act as a stack).
	 */
	Cache(size_t limit, bool deleteOnGet)
	: limit(limit)
	, deleteOnGet(deleteOnGet)
	, matches(0)
	, misses(0)
	{}

	virtual ~Cache() {}

	/**
	 * add an item to cache.
	 * @param key key of new item.
	 * @param value value of new item.
	 */
	void AddItem(const T& key, const V& value)
	{
		const size_t tmpLimit(GetLimit());

		while(tmpLimit) {
			if( GetSize() < tmpLimit ) {
				break; }
			else if(deleteOnGet) {
				usleep(250 * 1000); }
			else {
				//removes 25% of the cache
				RemoveItem(0, ( tmpLimit > 4 ? tmpLimit : tmpLimit /4 ) );
			}
		}

		rwLockEntries.WaitForWriteLock();
		mapEntries.insert(typename std::pair<T,V>(key,value));
		rwLockEntries.ReleaseLock();
	}

	/**
	 * deletes item from cache.
	 * @param key key to delete.
	 * @param locking true if cache locks while deleting.
	 * @return false on error, true on success.
	 */
	bool DeleteItem(const T& key, const bool locking = true)
	{
		if(locking)
			rwLockEntries.WaitForWriteLock();

		bool success(true);
		if(!mapEntries.count(key))
			success = false;
		else
			mapEntries.erase(key);

		if(locking)
			rwLockEntries.ReleaseLock();

		return success;
	}

	/**
	 * gets value by key.
	 * @param key key for value to get.
	 * @return value of given key.
	 */
	V GetItem(const T& key)
	{
		rwLockEntries.WaitForReadLock();
		if(mapEntries.count(key) > 0) {
			const V& value(mapEntries.at(key));
			rwLockEntries.ReleaseLock();
			AddMatches(1);
			return value;
		}
		else {
			rwLockEntries.ReleaseLock();
			AddMisses(1);
			throw std::range_error("V Cache::GetItem(const T&): invalid range");
		}
	}

	/**
	 * gets value by key.
	 * @param key key for value to get.
	 * @param value gets filled with value for given key.
	 * @return false if non-existent, true on success.
	 */
	bool GetItem(const T& key, V& value)
	{
		if(deleteOnGet)
			rwLockEntries.WaitForReadLock();
		else
			rwLockEntries.WaitForWriteLock();

		if(!mapEntries.count(key)) {
			rwLockEntries.ReleaseLock();
			AddMisses(1);
			return false; }

		value = mapEntries.at(key);

		AddMatches(1);

		if(deleteOnGet)
			DeleteItem(key,false);

		rwLockEntries.ReleaseLock();
		return true;
	}

	/**
	 * gets multiple items.
	 * @param list filled with keys and values.
	 * @param count maximum number of items to get.
	 * @return false if cache is empty, true on success.
	 */
	bool GetItem(std::map<T, V>& list, const int count)
	{
		if(!GetSize()) {
			AddMisses(list.size());
			return false;}

		if(!deleteOnGet)
			rwLockEntries.WaitForReadLock();
		else
			rwLockEntries.WaitForWriteLock();

		size_t copyCount = (count <= 0) ? 1 : (size_t)count;
		if(copyCount > mapEntries.size()) {
			copyCount = mapEntries.size(); }

		typename std::map<T, V>::iterator iterMap(mapEntries.begin());
		typename std::map<T, V>::iterator iterEnd(iterMap);
		std::advance(iterEnd,copyCount);
		list.insert(iterMap,iterEnd);

		AddMatches(list.size());

		if(deleteOnGet){
			mapEntries.erase(mapEntries.begin(),iterEnd);}
		rwLockEntries.ReleaseLock();

		return true;
	}

	/**
	 * removes multiple items from cache.
	 * @param startPos start position to delete from.
	 * @param count maximum number of items to delete.
	 */
	void RemoveItem(const size_t startPos, const size_t count)
	{
		rwLockEntries.WaitForWriteLock();
		typename std::map<T, V>::iterator iterStart(mapEntries.begin());
		if(startPos)
			std::advance(iterStart,startPos);

		typename std::map<T, V>::iterator iterEnd(mapEntries.begin());
		std::advance(iterEnd, ( (count>0 && count<mapEntries.size()) ? count : mapEntries.size()) );

		mapEntries.erase(iterStart,iterEnd);
		rwLockEntries.ReleaseLock();
	}

	/**
	 * removes all items from cache.
	 */
	void ClearItems()
	{
		rwLockEntries.WaitForWriteLock();
		mapEntries.clear();
		rwLockEntries.ReleaseLock();
	}

	/**
	 * gets items from cache by key and puts missing
	 * keys (no corresponding value found) in a separate list.
	 * @param check prefilled map with keys to get values for, available values will get filled.
	 * @param missing list of missing keys in cache.
	 */
	void GetMissingItems(std::map<T, V>& check, std::vector<T>& missing)
	{
		rwLockEntries.WaitForWriteLock();
		typename std::map<T,V>::iterator iterCheck(check.begin());
		for(;iterCheck != check.end();++iterCheck){
			if(!mapEntries.count(iterCheck->first))
				missing.push_back(iterCheck->first);
			else{
				iterCheck->second = mapEntries[iterCheck->first]; }
		}
		rwLockEntries.ReleaseLock();

		AddMisses(missing.size());
	}

	/**
	 * gets multiple items from cache by value and puts missing
	 * values (no corresponding key found) in a separate list.
	 * @param check prefilled map with values to get keys for, available keys will get filled.
	 * @param missing list of missing values in cache.
	 */
	void GetByValue(std::map<V,T>& check, std::vector<V>& missing) const
	{
		rwLockEntries.WaitForReadLock();
		typename std::map<V,T> checkTmp(check);
		typename std::map<V,T>::const_iterator iterCheckTmp(checkTmp.begin());
		for(;iterCheckTmp != checkTmp.end();++iterCheckTmp) {
			typename std::map<T,V>::const_iterator iterEntries = mapEntries.begin();
			bool found = false;
			for(;iterEntries != mapEntries.end();++iterEntries) {
				if(iterEntries->second == iterCheckTmp->first) {
					found = true;
					AddMatches(1);
					break; }
			}
			if(found) {
				check.erase(iterCheckTmp->first);
				typename std::pair<V,T> pairInsert(iterEntries->second,iterEntries->first);
				check.insert(pairInsert);
			} else {
				missing.push_back(iterCheckTmp->first);
			}
		}
		rwLockEntries.ReleaseLock();

		AddMisses(missing.size());
	}

	/**
	 * gets key by value.
	 * @param value value to search for.
	 * @param key gets filled with key if found.
	 * @return false if all non-existent, true on success.
	 */
	bool GetByValue(const V& value, T& key) const
	{
		rwLockEntries.WaitForReadLock();
		typename std::map<T,V>::const_iterator iterEntries(mapEntries.begin());
		for(;iterEntries != mapEntries.end();++iterEntries) {
			if(iterEntries->second == value) {
				key = iterEntries->first;
				rwLockEntries.ReleaseLock();
				AddMatches(1);
				return true;}
		}
		rwLockEntries.ReleaseLock();

		AddMisses(1);
		return false;
	}

	/**
	 * gets key by transformed value of type X.
	 * @param value value to search for.
	 * @param key gets filled with key if found.
	 * @return false if all non-existent, true on success.
	 */
	template <class X>
	bool GetByValue(const X& value, T& key) const {

		rwLockEntries.WaitForReadLock();
		typename std::map<T,V>::const_iterator iterEntries(mapEntries.begin());
		for(;iterEntries != mapEntries.end();++iterEntries) {
			if ( dynamic_cast<const X&>(iterEntries->second) == value ) {
				key = iterEntries->first;
				rwLockEntries.ReleaseLock();

				AddMatches(1);
				return true;
			}
		}
		rwLockEntries.ReleaseLock();

		AddMisses(1);
		return false;
	}

	/**
	 * get current match count of cache, clearing internal match counter.
	 * @return number of matches.
	 */
	size_t GetMatches() const {
		rwLockMatch.WaitForWriteLock();
		size_t tmp(matches); matches = 0;
		rwLockMatch.ReleaseLock();
		return tmp; }

	/**
	 * get current miss count of cache, clearing internal miss counter.
	 * @return number of misses.
	 */
	size_t GetMisses() const {
		rwLockMiss.WaitForWriteLock();
		size_t tmp(misses); misses = 0;
		rwLockMiss.ReleaseLock();
		return tmp; }

	/**
	 * get current limit of cache.
	 * @return maximum number of entries in cache.
	 */
	size_t GetLimit() const {
		rwLockLimit.WaitForReadLock();
		size_t ret(limit);
		rwLockLimit.ReleaseLock();
		return ret;
	}

	/**
	 * set current limit of cache.
	 * @param capacity maximum number of entries in cache.
	 */
	void SetLimit(const size_t capacity) {
		rwLockLimit.WaitForWriteLock();
		limit = capacity;
		rwLockLimit.ReleaseLock();}

	/**
	 * gets current number of entries in cache.
	 * @return current number of entries in cache.
	 */
	size_t GetSize() const {
		rwLockEntries.WaitForReadLock();
		size_t ret(mapEntries.size());
		rwLockEntries.ReleaseLock();
		return ret; }

private:
	void AddMisses(size_t n) const {
		rwLockMiss.WaitForWriteLock();
		misses += n;
		rwLockMiss.ReleaseLock();}

	void AddMatches(size_t n) const {
		rwLockMatch.WaitForWriteLock();
		matches += n;
		rwLockMatch.ReleaseLock();}

private:
	volatile size_t limit;
	mutable threading::ReadWriteLock rwLockLimit;

	volatile bool deleteOnGet;

	mutable size_t matches;
	mutable threading::ReadWriteLock rwLockMatch;

	mutable size_t misses;
	mutable threading::ReadWriteLock rwLockMiss;

	mutable threading::ReadWriteLock rwLockEntries;
	std::map<T,V> mapEntries;
};

}
