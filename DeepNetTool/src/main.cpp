//============================================================================
// Name        : DeepNetTool.cpp
// Author      : Moritz Wagner (moritz.wagner@siridia.de)
// Version     :
// Copyright   : Copyright 2012, Moritz Wagner
// Description : DeepNet Tool Bot
//============================================================================

#include "DeepNetToolBot.h"

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/conf.h>
#include <libxml/parser.h>
#include <curl/curl.h>

#include <iostream>

#include <Exception.h>
#include <StdException.h>

using namespace std;

int main(int argc, char** argv) {

	curl_global_init(CURL_GLOBAL_ALL);
	xmlInitParser();
	SSL_library_init();
	SSL_load_error_strings();
	OpenSSL_add_all_algorithms();

	toolbot::DeepNetToolBot bot;

	bool success(false);
	try {
		success = bot.Run(argc,argv);
	}
	CATCH_EXCEPTION(errors::Exception,ex,1)
		bot.OnException( ex );
		return 1;
	}

	ENGINE_cleanup();
	CONF_modules_unload(1);
	ERR_free_strings();
	EVP_cleanup();
	CRYPTO_cleanup_all_ex_data();

	xmlCleanupParser();
	curl_global_cleanup();

	return success ? 0 : 1;
}
