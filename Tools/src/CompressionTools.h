/**
 * @file CompressionTools.h
 * @author Moritz Wagner
 * @date 22.12.2012
 */

#pragma once

#include <cstddef>

namespace tools {

/**
 * @brief wrapper class for compression algorithms.
 * this class wraps all kind of compression functionalities.
 */
class CompressionTools {

private:
	CompressionTools();
public:
	virtual ~CompressionTools();

public:
	/**
	 * compress buffer using gzip.
	 * @param in input buffer.
	 * @param in_size input buffer size.
	 * @param out output buffer.
	 * @param out_size gets filled with size of output buffer.
	 * @return false on error, true on success.
	 */
	static bool GZip(const char* in, const size_t& in_size, char** out, size_t& out_size);

	/**
	 * decompress buffer using gzip.
	 * @param in input buffer.
	 * @param in_size input buffer size.
	 * @param out output buffer.
	 * @param out_size gets filled with size of output buffer.
	 * @return false on error, true on success.
	 */
	static bool GUnzip(const char* in, const size_t& in_size, char** out, size_t& out_size);

	/**
	 * compress buffer using deflate.
	 * @param in input buffer.
	 * @param in_size input buffer size.
	 * @param out output buffer.
	 * @param out_size gets filled with size of output buffer.
	 * @return false on error, true on success.
	 */
	static bool Deflate(const char* in, const size_t& in_size, char** out, size_t& out_size);

	/**
	 * decompress buffer using deflate.
	 * @param in input buffer.
	 * @param in_size input buffer size.
	 * @param out output buffer.
	 * @param out_size gets filled with size of output buffer.
	 * @return false on error, true on success.
	 */
	static bool Inflate(const char* in, const size_t& in_size, char** out, size_t& out_size);

	/**
	 * compress buffer using raw deflate.
	 * @param in input buffer.
	 * @param in_size input buffer size.
	 * @param out output buffer.
	 * @param out_size gets filled with size of output buffer.
	 * @return false on error, true on success.
	 */
	static bool RawDeflate(const char* in, const size_t& in_size, char** out, size_t& out_size);

	/**
	 * decompress buffer using raw deflate.
	 * @param in input buffer.
	 * @param in_size input buffer size.
	 * @param out output buffer.
	 * @param out_size gets filled with size of output buffer.
	 * @return false on error, true on success.
	 */
	static bool RawInflate(const char* in, const size_t& in_size, char** out, size_t& out_size);

private:
	static bool DeflateZLib(const int windowBits, const char* in, const size_t& in_size, char** out, size_t& out_size);
	static bool InflateZLib(const int windowBits, const char* in, const size_t& in_size, char** out, size_t& out_size);
};

}
