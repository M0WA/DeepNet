/**
 * @file CompressionTools.cpp
 * @author Moritz Wagner
 * @date 22.12.2012
 */

#include "CompressionTools.h"

#include <cstdlib>
#include <zlib.h>

static const int ZLIB_DEFLATE_MODE = MAX_WBITS;
static const int ZLIB_GZIP_MODE    = (16+MAX_WBITS);
static const int ZLIB_RAW_MODE     = -MAX_WBITS;

namespace tools {

CompressionTools::CompressionTools() {
}

CompressionTools::~CompressionTools() {
}

bool CompressionTools::GZip(const char* in, const size_t& in_size, char** out, size_t& out_size) {

	return DeflateZLib(ZLIB_GZIP_MODE, in, in_size, out, out_size);
}

bool CompressionTools::GUnzip(const char* in, const size_t& in_size, char** out, size_t& out_size) {

	return InflateZLib(ZLIB_GZIP_MODE, in, in_size, out, out_size);
}

bool CompressionTools::Deflate(const char* in, const size_t& in_size, char** out, size_t& out_size) {

	return DeflateZLib(ZLIB_DEFLATE_MODE, in, in_size, out, out_size);
}

bool CompressionTools::Inflate(const char* in, const size_t& in_size, char** out, size_t& out_size) {

	return InflateZLib(ZLIB_DEFLATE_MODE, in, in_size, out, out_size);
}

bool CompressionTools::RawDeflate(const char* in, const size_t& in_size, char** out, size_t& out_size) {

	return DeflateZLib(ZLIB_RAW_MODE, in, in_size, out, out_size);
}

bool CompressionTools::RawInflate(const char* in, const size_t& in_size, char** out, size_t& out_size) {

	return InflateZLib(ZLIB_RAW_MODE, in, in_size, out, out_size);
}

bool CompressionTools::DeflateZLib(const int windowBits, const char* in, const size_t& in_size, char** out, size_t& out_size) {

	//compression
	*out = 0;

	z_stream strm;
	strm.next_in = reinterpret_cast<Bytef *>(const_cast<char*>(in));
	strm.avail_in = in_size;
	strm.total_out = out_size = 0;
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;

	int memLevel = 8;
	if(deflateInit2(&strm, Z_DEFAULT_COMPRESSION, Z_DEFLATED, windowBits, memLevel, Z_DEFAULT_STRATEGY) != Z_OK) {
		return false; }

	while(1) {

		 if (strm.total_out >= out_size ) {
			 if(*out == 0) {
				 *out = (char*)malloc(strm.total_out); }
			 else {
				 *out = (char*)realloc(*out,strm.total_out); }
			 out_size = strm.total_out;
		 }

		strm.next_out  = (Bytef *) (*out + strm.total_out);
		strm.avail_out = out_size - strm.total_out;

	    int err = deflate (&strm, Z_SYNC_FLUSH);
	    if (err == Z_STREAM_END) {
	    	break; }
	    else if (err != Z_OK)  {
	    	free(*out);
	    	return false; }
	}

	if (deflateEnd (&strm) != Z_OK) {
    	free(*out);
		return false;
	}

	return true;
}

bool CompressionTools::InflateZLib(const int windowBits, const char* in, const size_t& in_size, char** out, size_t& out_size) {

	//decompression
	*out = 0;

	const static size_t chunkSize = 255;

	z_stream strm;
	strm.next_in = reinterpret_cast<Bytef *>(const_cast<char*>(in));
	strm.avail_in = in_size;
	strm.total_out = 0;
	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;

	if (inflateInit2(&strm, windowBits) != Z_OK) {
    	out_size = 0;
		return false; }

	out_size = chunkSize;
	while(1) {

		 if(*out == 0) {
			 *out = (char*)malloc(out_size); }
		 else {
			 *out = (char*)realloc(*out,out_size); }

		strm.next_out  = (Bytef *) (*out + strm.total_out);
		strm.avail_out = out_size - strm.total_out;

	    int err = inflate (&strm, Z_SYNC_FLUSH);
	    if (err == Z_STREAM_END) {
	    	break; }
	    else if (err != Z_OK)  {
	    	free(*out);
	    	*out = 0;
	    	out_size = 0;
	    	return false; }

	    out_size += chunkSize;
	}
	out_size = strm.total_out;

	if (inflateEnd (&strm) != Z_OK) {
    	free(*out);
    	*out = 0;
    	out_size = 0;
		return false;
	}
	return true;
}

}
