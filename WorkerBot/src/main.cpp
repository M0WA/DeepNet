/**
 * @file WorkerBot/src/main.cpp
 * @author Moritz Wagner
 * @date 12.03.2012
 */

#include "WorkerBot.h"

#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/conf.h>
#include <libxml/parser.h>
#include <curl/curl.h>

#include <Exception.h>

using namespace std;

int main(int argc, char** argv) {

	curl_global_init(CURL_GLOBAL_ALL);
	xmlInitParser();
	SSL_library_init();
	SSL_load_error_strings();
	OpenSSL_add_all_algorithms();

	workerbot::WorkerBot bot;

	try {
		bot.Run(argc,argv);
	}
	CATCH_EXCEPTION(errors::Exception,ex,1)
		bot.OnException( ex );
		return 1;
	}
	catch(...) {
		bot.OnException();
		return 1;
	}

	ENGINE_cleanup();
	CONF_modules_unload(1);
	ERR_free_strings();
	EVP_cleanup();
	CRYPTO_cleanup_all_ex_data();

	xmlCleanupParser();
	curl_global_cleanup();
	return 0;
}
