/**
 * @file ContainerTools.h
 * @author Moritz Wagner
 * @date 24.09.2012
 */

#pragma once

#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <sstream>

namespace tools {

/**
 * @brief wrapper class to deal with stl types
 */
class ContainerTools {
private:
	ContainerTools();
	virtual ~ContainerTools();

public:
	/**
	 * removes duplicate entries from toUnique.
	 * @param toUnique vector to make unique.
	 * @param sort true if output should be sorted, false if not.
	 */
	template <class T>
	static inline void MakeUniqueVector(std::vector<T>& toUnique, bool sort = false) {
		MakeUniqueVector<T>(toUnique, toUnique, sort);
	}

	/**
	 * removes duplicate entries from in and copies them to unique.
	 * @param in vector to make unique.
	 * @param unique vector containing unique items.
	 * @param sort true if output should be sorted, false if not.
	 */
	template <class T>
	static inline void MakeUniqueVector(const std::vector<T>& in, std::vector<T>& unique, bool sort = false) {
		//TODO: this could be done much more performant...
		std::vector<T> tmpUnique = in;
		std::sort(tmpUnique.begin(),tmpUnique.end());

		std::vector<T> tmpUniqueSorted;
		tmpUniqueSorted.insert(tmpUniqueSorted.begin(),tmpUnique.begin(),std::unique(tmpUnique.begin(),tmpUnique.end()));

		std::map<T,bool> mapInserted;
		typename std::vector<T>::const_iterator iterUnique = tmpUniqueSorted.begin();
		for(;iterUnique != tmpUniqueSorted.end(); ++iterUnique) {
			mapInserted[*iterUnique] = false; }

		std::vector<T> uniqueUnsorted;
		iterUnique = in.begin();
		for(;iterUnique != in.end(); ++iterUnique) {

			if(!mapInserted[*iterUnique]) {
				uniqueUnsorted.push_back(*iterUnique);
				mapInserted[*iterUnique] = true; }
		}

		unique = uniqueUnsorted;
	}

	/**
	 * converts std::list to std::vector
	 * @param in list to be converted.
	 * @param out converted vector.
	 */
	template <class T>
	static void ListToVector(const std::list<T>& in,std::vector<T>& out) {
		typename std::list<T>::const_iterator iterTrans = in.begin();
		for(;iterTrans != in.end();++iterTrans){
			out.push_back(*iterTrans); }
	}

	/**
	 * converts first entry(key) of std::map to std::vector
	 * @param mapIn map to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T, class V>
	static void Map1ToVector(const std::map<T,V> mapIn,std::vector<T>& vecOut) {
		typename std::map<T,V>::const_iterator iterMap = mapIn.begin();
		for(; iterMap != mapIn.end(); ++iterMap) {
			vecOut.push_back(iterMap->first); }
	}

	/**
	 * converts second entry(value) of std::map to std::vector
	 * @param mapIn map to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T, class V>
	static void Map2ToVector(const std::map<T,V> mapIn,std::vector<V>& vecOut) {
		typename std::map<T,V>::const_iterator iterMap = mapIn.begin();
		for(; iterMap != mapIn.end(); ++iterMap) {
			vecOut.push_back(iterMap->second); }
	}

	/**
	 * converts first entry(value) of std::vector< std::pair<> > to std::vector
	 * @param vecIn vector to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T, class V>
	static void VectorPair1ToVector(const std::vector< std::pair<T,V> >& vecIn, std::vector< T >& vecOut) {
		typename std::vector< std::pair<T,V> >::const_iterator iterVec = vecIn.begin();
		for(; iterVec != vecIn.end(); ++iterVec) {
			vecOut.push_back(iterVec->first); }
	}

	/**
	 * converts second entry(value) of std::vector< std::pair<> > to std::vector
	 * @param vecIn vector to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T, class V>
	static void VectorPair2ToVector(const std::vector< std::pair<T,V> >& vecIn, std::vector< T >& vecOut) {
		typename std::vector< std::pair<T,V> >::const_iterator iterVec = vecIn.begin();
		for(; iterVec != vecIn.end(); ++iterVec) {
			vecOut.push_back(iterVec->first); }
	}

	/**
	 * creates a vector of const entries from another vector.
	 * @param vecIn vector to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T>
	static void ToConstVector(const std::vector<T>& vecIn, std::vector<const T>& vecOut) {
		typename std::vector<T>::const_iterator iterIn = vecIn.begin();
		for(;iterIn != vecIn.end();++iterIn) {
			vecOut.push_back(const_cast<const T>(*iterIn)); }
	}

	/**
	 * creates a vector of const pointers from another vector of pointers.
	 * @param vecIn vector to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T>
	static void ToConstVector(const std::vector<T*>& vecIn, std::vector<const T*>& vecOut) {
		typename std::vector<T*>::const_iterator iterIn = vecIn.begin();
		for(;iterIn != vecIn.end();++iterIn) {
			vecOut.push_back(const_cast<const T*>(*iterIn)); }
	}

	/**
	 * creates a vector of non-const entries from another vector.
	 * @param vecIn vector to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T>
	static void ToNonConstVector(const std::vector<const T>& vecIn, std::vector<T>& vecOut) {
		typename std::vector<const T>::const_iterator iterIn = vecIn.begin();
		for(;iterIn != vecIn.end();++iterIn) {
			vecOut.push_back(const_cast<T>(*iterIn)); }
	}

	/**
	 * creates a vector of non-const pointers from another vector of pointers.
	 * @param vecIn vector to be converted.
	 * @param vecOut converted vector.
	 */
	template <class T>
	static void ToNonConstVector(const std::vector<const T*>& vecIn,std::vector<T*>& vecOut) {
		typename std::vector<const T*>::const_iterator iterIn = vecIn.begin();
		for(;iterIn != vecIn.end();++iterIn) {
			vecOut.push_back(const_cast<T*>(*iterIn)); }
	}

	/**
	 * compares entries of two vectors.
	 * @param comp1 vector to compare.
	 * @param comp2 vector to compare.
	 * @return true if identical, false if different.
	 */
	template <class T>
	static bool CompareVector(const std::vector<T>& comp1,const std::vector<T>& comp2){
		if(comp1.size() != comp2.size())
			return false;
		if(comp1.size() == 0)
			return true;

		typename std::vector<T>::const_iterator iter1 = comp1.begin(), iter2 = comp2.begin();
		for(;iter1 != comp1.end() && iter2 != comp2.end();++iter1,++iter2){
			if(*iter1 != *iter2)
				return false;
		}
		return true;
	}

	/**
	 * dumps contents of vector as a string
	 * @param in vector to be dumped.
	 * @param dump string containing dumped vector.
	 */
	template <class T>
	static void DumpVector(const std::vector<T>& in,std::string& dump){
		std::ostringstream ssOut;
		DumpVecFunc<T> dumpFunc(ssOut);
		std::for_each(in.begin(),in.end(),dumpFunc);
		dump = ssOut.str();
	}

	/**
	 * dumps contents of map as a string
	 * @param in map to be dumped.
	 * @param dump string containing dumped map.
	 */
	template <class T, class V>
	static void DumpMap(const std::map<T,V>& in,std::string& dump){
		std::ostringstream ssOut;
		DumpMapFunc<T,V> dumpFunc(ssOut);
		std::for_each(in.begin(),in.end(),dumpFunc);
		dump = ssOut.str();
	}

private:
	template <class T>
	struct DumpVecFunc : public std::unary_function<T,bool> {
		DumpVecFunc(std::ostringstream& dump) : itemNo(0), dump(dump) {}
		bool operator() (const T& item) {
			dump << "element " << itemNo << ": " << item << std::endl;
			itemNo++;
			return true;}
	private:
		int itemNo;
		std::ostringstream& dump;
	};

	template <class T, class V>
	struct DumpMapFunc : public std::binary_function<T,V,bool> {
		DumpMapFunc(std::ostringstream& dump) : itemNo(0), dump(dump) {}
		bool operator() (const std::pair<T,V>& item) {
			dump << "element " << itemNo << ": \"" << item.first << "\" -> \"" << item.second << "\"" << std::endl;
			itemNo++;
			return true;}
	private:
		int itemNo;
		std::ostringstream& dump;
	};
};

}

