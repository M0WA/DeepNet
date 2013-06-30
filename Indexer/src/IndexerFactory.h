/**
 *
 * @file IndexerFactory.h
 * @author Moritz Wagner
 * @date 30.06.2013
 *
 */

#pragma once

namespace indexing {

class IndexerParam;
class Indexer;

class IndexerFactory {
private:
	IndexerFactory();
public:
	virtual ~IndexerFactory();

public:
	static Indexer* CreateGenericWebIndexer(const IndexerParam* param);
	static Indexer* CreateDataminingIndexer(const IndexerParam* param);
};

}
