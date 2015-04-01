GENERATED_DIR = ../generated

all: indexer

clean:
	rm -f $(GENERATED_DIR)/* log/*

generic:
	make clean
	mkdir -p $(GENERATED_DIR) log

indexer:
	make debug

debug:
	make generic
	bison -v --name-prefix=contentIndexer_yy -t --report-file=log/content_parser.log -d parser/content_parser.ypp -o $(GENERATED_DIR)/content_parser.tab.cpp
	flex -d --prefix=contentIndexer_yy -o $(GENERATED_DIR)/content_lexer.yy.cpp lexer/content_lexer.l
	cat log/content_parser.log	
	bison -v --name-prefix=metaIndexer_yy -t --report-file=log/meta_parser.log -d parser/meta_parser.ypp -o $(GENERATED_DIR)/meta_parser.tab.cpp
	flex -d --prefix=metaIndexer_yy -o $(GENERATED_DIR)/meta_lexer.yy.cpp lexer/meta_lexer.l
	cat log/meta_parser.log

release:
	make generic
	bison --name-prefix=contentIndexer_yy  -v -t --report-file=log/content_parser.log -d parser/content_parser.ypp -o $(GENERATED_DIR)/content_parser.tab.cpp
	flex --prefix=contentIndexer_yy -f -8 -o $(GENERATED_DIR)/content_lexer.yy.cpp lexer/content_lexer.l
	bison --name-prefix=metaIndexer_yy -v -t --report-file=log/meta_parser.log -d parser/meta_parser.ypp -o $(GENERATED_DIR)/meta_parser.tab.cpp
	flex -d --prefix=metaIndexer_yy -f -8 -o $(GENERATED_DIR)/meta_lexer.yy.cpp lexer/meta_lexer.l

.PHONY: clean

?:
	make all
