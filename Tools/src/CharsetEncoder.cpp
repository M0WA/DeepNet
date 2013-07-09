/**
 * @file CharsetEncoder.cpp
 * @author Moritz Wagner
 * @date 20.03.2012
 */

#include "CharsetEncoder.h"
#include <unicode/utypes.h>
#include <unicode/ucnv.h>
#include <unicode/ucsdet.h>
#include <algorithm>
#include <libxml/HTMLtree.h>

#include "Logging.h"

namespace tools
{

CharsetEncoder::CharsetEncoder()
{
}

CharsetEncoder::~CharsetEncoder()
{
}

bool CharsetEncoder::Detect( const char* pszBuffer, const int lenBuffer, DetectMatch& match )
{
	match.encodingName = "";
	match.encodingHintCorrect = false;
	match.encodingConfidence = 0;

	UErrorCode status = U_ZERO_ERROR;
	UCharsetDetector* detector = ucsdet_open(&status);
	if( U_FAILURE(status) ) {
		return false; }
	status = U_ZERO_ERROR;

	UBool filterOn = 1;
	ucsdet_enableInputFilter(detector,filterOn);

	if( !match.encodingHint.empty() ) {
		status = U_ZERO_ERROR;
		ucsdet_setDeclaredEncoding( detector, match.encodingHint.c_str(), match.encodingHint.size(), &status );
		if( U_FAILURE(status) ) {
			match.encodingHintCorrect = false;
			match.encodingHint = "";
		}
	}

	status = U_ZERO_ERROR;
	ucsdet_setText(detector,pszBuffer,lenBuffer,&status);
	if( U_FAILURE(status) ) {
		ucsdet_close(detector);
		return false; }

	int32_t matchesFound = -1;
	const UCharsetMatch** charsetMatches = ucsdet_detectAll(detector, &matchesFound, &status);
	if( U_FAILURE(status) || matchesFound <= 0 ) {
		ucsdet_close(detector);
		return false; }

	const UCharsetMatch* charsetMatch = 0;
	long  tmpMaxConfidence = -1;
	UErrorCode tmpStatus = U_ZERO_ERROR;
	for( int32_t i = 0; i < matchesFound; i++) {

		tmpStatus = U_ZERO_ERROR;
		long tmpConfidence = ucsdet_getConfidence( charsetMatches[i], &tmpStatus );
		if( U_FAILURE( tmpStatus ) ) {
			continue; }

		tmpStatus = U_ZERO_ERROR;
		const char* encodingNameCharTmp = ucsdet_getName( charsetMatches[i], &tmpStatus );
		if( U_FAILURE( tmpStatus ) ) {
			continue; }

		//encoding from hint is in detected charset so break here
		if( IsCharsetAlias( encodingNameCharTmp, match.encodingHint.c_str() ) ){
			charsetMatch = charsetMatches[i];
			break; }

		if( tmpMaxConfidence < tmpConfidence ) {
			tmpMaxConfidence = tmpConfidence;
			charsetMatch = charsetMatches[i]; }
	}

	if(charsetMatch == 0) {
		ucsdet_close(detector);
		return false;
	}

	const char* encodingNameChar = ucsdet_getName(charsetMatch, &status);
	if( U_FAILURE(status) || !encodingNameChar ) {
		match.encodingName = "";
		ucsdet_close(detector);
		return false; }
	match.encodingName = encodingNameChar;

	match.encodingConfidence = ucsdet_getConfidence(charsetMatch,&status);
	if( U_FAILURE(status) ) {
		ucsdet_close(detector);
		return false; }

	const char* lang = ucsdet_getLanguage(charsetMatch,&status);
	if( !U_FAILURE(status) && lang ) {
		match.language = lang; }

	/*
	if(confidence < minConfidence){
		match.isValidEncoding = false;
		match.encodingHintCorrect = false;
		ucsdet_close(detector);
		return false; }
	*/

	match.encodingHintCorrect = CharsetEncoder::IsCharsetAlias( match.encodingHint.c_str(), match.encodingName.c_str() );

	ucsdet_close(detector);
	return true;
}

bool CharsetEncoder::IsValidEncodingName(std::string& encodingName)
{
	UErrorCode status = U_ZERO_ERROR;
	UCharsetDetector* detector = ucsdet_open(&status);
	if( U_FAILURE(status) ) {
		if(detector)
			ucsdet_close(detector);
		return false; }

	UEnumeration* enumValid = ucsdet_getAllDetectableCharsets(detector,&status);
	if( U_FAILURE(status) ) {
		if(enumValid)
			uenum_close(enumValid);
		ucsdet_close(detector);
		return false; }

	int32_t len = 0;
	while( 1 ) {
		const char* validName = uenum_next(enumValid,&len,&status);
		if(validName == 0)
			break;
		if( status == U_INVARIANT_CONVERSION_ERROR )
			continue;

		if ( CharsetEncoder::IsCharsetAlias(validName,encodingName.c_str()) ){
			encodingName = validName;
			uenum_close(enumValid);
			ucsdet_close(detector);
			return true;
		}
	}

	uenum_close(enumValid);
	ucsdet_close(detector);
	return true;
}

bool CharsetEncoder::IsCharsetAlias(const char* name1, const char* name2)
{
	return ( ucnv_compareNames(name1, name2) == 0 );
}

std::string CharsetEncoder::GetHostCharsetName() {

	return std::string(ucnv_getDefaultName());
}

bool CharsetEncoder::Convert(const char* pInput, const int len, const std::string& inEnc, std::string& sOutput)
{
	//TODO: use pivot buffer (ucnv_convertEx)

	const char* charDefaultConverter = ucnv_getDefaultName();
	if ( CharsetEncoder::IsCharsetAlias(charDefaultConverter, inEnc.c_str()) ){
		sOutput.append(pInput,len);
		return true; }

	UErrorCode status = U_ZERO_ERROR;
	UConverter *convIn = ucnv_open(charDefaultConverter, &status);
	if( U_FAILURE(status) ) {
		if(convIn)
			ucnv_close(convIn);
		return false; }

	status = U_ZERO_ERROR;
	UConverter *convOut = ucnv_open(inEnc.c_str(), &status);
	if( U_FAILURE(status) ) {
		ucnv_close(convIn);
		if(convOut)
			ucnv_close(convOut);
		return false; }

	int32_t capacity = len + 1;
	char* targetStart = (char*)malloc(capacity);
	char* targetPos   = targetStart;
	const char* source = pInput;
	status = U_ZERO_ERROR;

	ucnv_convertEx( convOut, convIn,
					&targetPos, targetStart+capacity,
					&source, pInput+len,
					NULL, NULL, NULL, NULL,
					TRUE, TRUE,
					&status);

	if( U_FAILURE(status) ) {
		free(targetStart);
		ucnv_close(convOut);
		ucnv_close(convIn);
		return false; }

	int timesRealloc = 1;
	while(status == U_BUFFER_OVERFLOW_ERROR)
	{
		status = U_ZERO_ERROR;
		timesRealloc++;

		int advanced = targetStart - targetPos;
		capacity     = len*timesRealloc;
		targetStart  = (char*)realloc(targetStart,capacity);
		targetPos    = targetStart + advanced;

		ucnv_convertEx( convOut, convIn,
						&targetPos, targetStart+capacity,
						&source, pInput+len,
						NULL, NULL, NULL, NULL,
						TRUE, TRUE,
						&status);
	}
	if(U_STRING_NOT_TERMINATED_WARNING == status)
	{
		//ihre dreckigen arschgeigen...
		capacity += 2;
		targetStart = (char*)realloc(targetStart,capacity);
		targetStart[capacity-1] = 0;
		targetStart[capacity-2] = 0;
	}
	if( U_FAILURE(status) ) {
		free(targetStart);
		ucnv_close(convOut);
		ucnv_close(convIn);
		return false; }

	sOutput = std::string(targetStart);

	free(targetStart);
	ucnv_close(convOut);
	ucnv_close(convIn);
	return true;
}

bool CharsetEncoder::EncodeHtmlEntities(const std::string& in, std::string& out) {
	return CharsetEncoder::EncodeHtmlEntities(reinterpret_cast<const unsigned char*>(in.c_str()), in.length(), out);
}

bool CharsetEncoder::EncodeHtmlEntities(const unsigned char* pszIn, const int inSize, std::string& out) {

	int bufSize  = (inSize*4)+1;
	unsigned char* buf = new unsigned char[bufSize];

	int outlen = bufSize;
	int inlen = inSize;
	int ret = UTF8ToHtml(buf,&outlen,pszIn,&inlen);

	if(ret != 0) {
		int pos = (outlen <= 20) ? 0 : outlen - 20;
		int end = ((inSize-1) < (outlen + 20) ) ? inSize-1 : outlen + 20;
		unsigned char tmp = buf[end];
		buf[end] = 0;
		log::Logging::LogError("an error occured while transforming to html entities: %s",&buf[pos]);
		buf[end] = tmp;
		delete [] buf;
		return false;}

	buf[outlen] = 0;
	out = std::string(reinterpret_cast<const char*>(buf));
	delete [] buf;
	return true;
}

}
