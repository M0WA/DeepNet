%option reentrant 
%option bison-bridge
%option yylineno
%option nounput
%option extra-type="MetaIndexerCtx*"

%{
#include <string>
#define YY_SKIP_YYWRAP
#define YY_DECL extern "C" int metaIndexer_yylex(YYSTYPE * yylval_param ,yyscan_t yyscanner)
#define YYSTYPE std::string*
#define COPY_TO_STD_STRING *metaIndexer_yylval = new std::string(); (*(*metaIndexer_yylval)) = metaIndexer_yytext;
#define YY_INPUT(buf,result,max_size) { int pos = yyextra->indexer->Read(buf,max_size); result = (pos > 0) ? pos : YY_NULL; }

#include <iostream>
#include "meta_parser.tab.hpp"
#include "../src/MetaIndexer.h"

static int yywrap(yyscan_t);

extern "C"
{
	int metaIndexer_yyerror(MetaIndexerCtx*,const char*);
	int metaIndexer_yylex_init_extra(MetaIndexerCtx* yy_user_defined,yyscan_t* ptr_yy_globals );
	int metaIndexer_yylex_destroy(yyscan_t ptr_yy_globals );
};

%}

%%
ffsuggest\.js 						{ return FACTFINDER_FLAG;     }
\.google-analytics\.com\/ga\.js		{ return GOOGLEANALYTICS_FLAG; }
.                       
%%

int metaIndexer_yyerror(MetaIndexerCtx*,const char*)
{
  return 0;
}

static int yywrap(yyscan_t)
{
	return 1;
}