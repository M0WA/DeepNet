%option reentrant 
%option bison-bridge
%option yylineno
%option nounput
%option extra-type="ContentIndexerCtx*"

%{

#include <string>
#define YY_SKIP_YYWRAP
#define YY_DECL extern "C" int contentIndexer_yylex(YYSTYPE * yylval_param ,yyscan_t yyscanner)
#define YYSTYPE std::string*
#define COPY_TO_STD_STRING *yylval = new std::string(); (*(*yylval)) = yytext;
#define YY_INPUT(buf,result,max_size) { int pos = yyextra->indexer->Read(buf,max_size); result = (pos > 0) ? pos : YY_NULL; }

#include <iostream>
#include "content_parser.tab.hpp"
#include "../src/ContentIndexer.h"

static int yywrap(yyscan_t);

extern "C"
{
	int contentIndexer_yylex_init_extra(ContentIndexerCtx* yy_user_defined,yyscan_t* ptr_yy_globals );
	int contentIndexer_yylex_destroy(yyscan_t yyscanner);
	int contentIndexer_yyerror(ContentIndexerCtx*,const char*);
}

%}

%%
\d+(\.|,)\d+                                       { return FLOAT_NUMBER; }	                   //decimal number
\d+[^(\.|,)]                                       { return INT_NUMBER;   }                    //integer number
[A-Za-z\-_0-9]*                                    { COPY_TO_STD_STRING; return WORD; }        //normal word
&nbsp;											   { return TERMINATE_WORD; }
&[A-Za-z]{2,};                                     { COPY_TO_STD_STRING; return HTML_ENTITY; } //html entity
&#[0-9]{2,};                                       { COPY_TO_STD_STRING; return CHARACTER_REFERENCE; } //html character reference
.												   { return TERMINATE_WORD; }
%%
	
int contentIndexer_yyerror(ContentIndexerCtx*,const char*)
{
  return 0;
}

static int yywrap(yyscan_t)
{
	return 1;
}
