/**
 * @file StringTools.cpp
 * @author Moritz Wagner
 * @date 23.03.2012
 */

#include "StringTools.h"

#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

#include <algorithm>

namespace tools
{

StringTools::StringTools()
{
}

StringTools::~StringTools()
{
}

void StringTools::ReplaceString(const std::string& oldstr, const std::string& newstr, std::string& target)
{
   size_t x = 0;
   while((x = target.find(oldstr,x)) != std::string::npos) {
	   target.replace(x,oldstr.length(),newstr);
	   x += newstr.length();}
}

void StringTools::RemoveEmptyLines(std::vector<std::string>& fileContent)
{
	std::vector<std::string> tmpLines;
	std::vector<std::string>::iterator iterLines = fileContent.begin();
	for(; iterLines != fileContent.end(); ++iterLines) {
		std::string tmpLine = *iterLines;
		ReplaceString("\n", "", tmpLine);
		ReplaceString("\r", "", tmpLine);
		ReplaceString("\t", "", tmpLine);
		if( !tmpLine.empty() ) {
			tmpLines.push_back(tmpLine);
		}
	}
	fileContent = tmpLines;
}

void StringTools::Trim (std::string &s)
{
	RightTrim(s);
	LeftTrim(s);
}

void StringTools::LeftTrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void StringTools::RightTrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

std::string& StringTools::ToLowerIP(std::string& s)
{
	std::transform(s.begin(), s.end(), s.begin(), tolower);
	return s;

}

std::string StringTools::ToLowerNP(const std::string& s)
{
	std::string sOut = s;
	std::transform(sOut.begin(), sOut.end(), sOut.begin(), tolower);
	return sOut;
}

void StringTools::RemoveComments(std::vector<std::string>& fileContent) {

	std::vector<std::string>::iterator iterLines = fileContent.begin();
	for(;iterLines != fileContent.end(); ++iterLines){

		size_t pos = iterLines->find('#');
		if(pos != std::string::npos) {

			std::string::iterator posStart = iterLines->begin();
			std::advance(posStart,pos);
			iterLines->erase(posStart, iterLines->end());
		}
	}
	StringTools::RemoveEmptyLines(fileContent);
}

void StringTools::SplitBy(const std::string & text, const std::string & separators, std::vector<std::string> & words) {

	int n = text.length();
	int start, stop;
	start = text.find_first_not_of(separators);
	while ((start >= 0) && (start < n))	{
		stop = text.find_first_of(separators, start);
		if ((stop < 0) || (stop > n))
			stop = n;
		words.push_back(text.substr(start, stop - start));
		start = text.find_first_not_of(separators, stop+1);
	}
}

void StringTools::FormatString(std::string& outString, const char* fmt, ...) {

	outString.clear();

	int n, size = 100;
	char *p = 0, *np = 0;
	va_list ap;

	if ((p = (char*)malloc (size)) == NULL)
		return;

	while (1) {

		va_start(ap, fmt);
		n = vsnprintf (p, size, fmt, ap);
		va_end(ap);
		if (n > -1 && n < size) {
		    break; }

		if (n > -1) {  // glibc 2.1
		   size = n+1; }
		else           // glibc 2.0
		   size *= 2;

		if ((np = (char*)realloc(p, size)) == NULL) {
		   free(p);
		   p = 0;
		   break;
		} else {
		   p = np;
		}
	}

	if(p) {
		outString = p;
		free(p); }
	else
		return;
}

//
//http://creativyst.com/Doc/Articles/SoundEx1/SoundEx1.htm
//
/*
int StringTools::SoundEx(char *SoundEx, char *WordString, int LengthOption, int CensusOption)
{
    int  InSz = 31;
    char WordStr[32];     // one bigger than InSz
    int  SoundExLen, WSLen, i;
    char FirstLetter, *p, *p2;

    SoundExLen = WSLen = 0;
    SoundEx[0] = 0;

    if(CensusOption) {
      LengthOption = 4; }

    if(LengthOption) {
        SoundExLen = LengthOption;
    }
    if(SoundExLen > 10) {
        SoundExLen = 10; }
    if(SoundExLen < 4) {
        SoundExLen = 4; }

    if(!WordString) {
        return(0); }

    // Copy WordString to WordStr without
    // using funcs from other libraries.
    for(p = WordString,p2 = WordStr,i = 0;(*p);p++,p2++,i++) {
      if(i >= InSz) break;
      (*p2) = (*p);
    }
    (*p2) = 0;

    // Convert WordStr to upper-case, without
    // using funcsfrom other libraries
    for(p = WordStr;(*p);p++) {
      if( (*p) >= 'a' && (*p) <= 'z' ) {
          (*p) -= 0x20;
      }
    }

    // convert all non-alpha chars to spaces
    for(p = WordStr;(*p);p++) {
      if( (*p) < 'A' || (*p) > 'Z' ) {
          (*p) = ' ';
      }
    }

    // Remove leading spaces
    for(i = 0, p = p2 = WordStr;(*p);p++) {
        if(!i) {
            if( (*p) != ' ' ) {
                (*p2) = (*p);
                p2++;
                i++;
            }
        }
        else {
            (*p2) = (*p);
            p2++;
        }
    }
    (*p2) = 0;

    // Get length of WordStr
    for(i = 0,p = WordStr;(*p);p++) i++;

    // Remove trailing spaces
    for(;i;i--) {
        if(WordStr[i] == ' ') {
          WordStr[i] = 0;
        }
        else {
            break;
        }
    }

    // Get length of WordStr
    for(WSLen = 0,p = WordStr;(*p);p++) WSLen++;

    if(!WSLen) {
      return(0);
    }

    // Perform our own multi-letter improvements
 	// underscore placeholders (_) will be
    // removed below.
    if(!CensusOption) {
        if(WordStr[0] == 'P' && WordStr[1] == 'S') {
            WordStr[0] = '_';
        }
        if(WordStr[0] == 'P' && WordStr[1] == 'F') {
            WordStr[0] = '_';
        }

        for(i = 0;i < WSLen;i++) {
            if(WordStr[i] == 'D' && WordStr[i+1] == 'G') {
                WordStr[i] = '_';
                i++;
                continue;
            }
            if(WordStr[i] == 'G' && WordStr[i+1] == 'H') {
                WordStr[i] = '_';
                i++;
                continue;
            }
            if(WordStr[i] == 'K' && WordStr[i+1] == 'N') {
                WordStr[i] = '_';
                i++;
                continue;
            }
            if(WordStr[i] == 'G' && WordStr[i+1] == 'N') {
                WordStr[i] = '_';
                i++;
                continue;
            }
            if(WordStr[i] == 'M' && WordStr[i+1] == 'B') {
                WordStr[i+1] = '_';
                i++;
                continue;
            }

            if(WordStr[i] == 'P' && WordStr[i+1] == 'H') {
                WordStr[i] = 'F';
                WordStr[i+1] = '_';
                i++;
                continue;
            }
            if(WordStr[i]  ==  'T'  &&
               WordStr[i+1] == 'C' &&
               WordStr[i+2] == 'H'
              ) {

                WordStr[i] = '_';
                i++; i++;
                continue;
            }
            if(WordStr[i] == 'M' && WordStr[i+1] == 'P'
               && (WordStr[i+2] == 'S' ||
                   WordStr[i+2] == 'T' ||
                   WordStr[i+2] == 'Z')
              ) {
                WordStr[i+1] = '_';
                i++;
            }
        }
    } // end if(!CensusOption)

    // squeeze out underscore characters
    // added as a byproduct of above process
    // (only needed in c styled replace)
    for(p = p2 = WordStr;(*p);p++) {
      (*p2) = (*p);
      if( (*p2) != '_' ) {
          p2++;
      }
    }
    (*p2) = 0;

    // This must be done AFTER our
    // multi-letter replacements
    // since they could change
    // the first letter
    FirstLetter = WordStr[0];


    // In case we're in CensusOption
    // 1 and the word starts with
    // an 'H' or 'W'
    // (v1.0c djr: add test for H or W)
    if(FirstLetter == 'H' || FirstLetter == 'W') {
        WordStr[0] = '-';
    }

    // In properly done census
    // SoundEx, the H and W will
    // be squezed out before
    // performing the test
    // for adjacent digits
    // (this differs from how
    // 'real' vowels are handled)
    if(CensusOption == 1) {
        for(p = &(WordStr[1]);(*p);p++) {
           if((*p) == 'H' || (*p) == 'W') {
               (*p) = '.';
           }
        }
    }

    // Perform classic SoundEx
    // replacements.
    for(p = WordStr;(*p);p++) {
        if( (*p) == 'A'   ||
            (*p) == 'E'   ||
            (*p) == 'I'   ||
            (*p) == 'O'   ||
            (*p) == 'U'   ||
            (*p) == 'Y'   ||
            (*p) == 'H'   ||
            (*p) == 'W'
          ){
            (*p) = '0';   // zero
        }
        if( (*p) == 'B'   ||
            (*p) == 'P'   ||
            (*p) == 'F'   ||
            (*p) == 'V'
          ){
            (*p) = '1';
        }
        if( (*p) == 'C'   ||
            (*p) == 'S'   ||
            (*p) == 'G'   ||
            (*p) == 'J'   ||
            (*p) == 'K'   ||
            (*p) == 'Q'   ||
            (*p) == 'X'   ||
            (*p) == 'Z'
          ){
            (*p) = '2';
        }
        if( (*p) == 'D'   ||
            (*p) == 'T'
          ){
            (*p) = '3';
        }
        if( (*p) == 'L' ) {
            (*p) = '4';
        }

        if( (*p) == 'M'   ||
            (*p) == 'N'
          ){
            (*p) = '5';
        }
        if( (*p) == 'R' ) {
            (*p) = '6';
        }
    }
    // soundex replacement loop done

    // In properly done census
    // SoundEx, the H and W will
    // be squezed out before
    // performing the test
    // for adjacent digits
    // (this differs from how
    // 'real' vowels are handled)
    if(CensusOption == 1) {
        // squeeze out dots
        for(p = p2 = &WordStr[1];(*p);p++) {
          (*p2) = (*p);
          if( (*p2) != '.' ) {
              p2++;
          }
        }
        (*p2) = 0;
    }

    // squeeze out extra equal adjacent digits
    // (don't include first letter)
    // v1.0c djr (now includes first letter)
    for(p = p2 = &(WordStr[0]);(*p);p++) {
      (*p2) = (*p);
      if( (*p2) != p[1] ) {
          p2++;
      }
    }
    (*p2) = 0;

    // squeeze out spaces and zeros
    // Leave the first letter code
    // to be replaced below.
    // (In case it made a zero)
    for(p = p2 = &WordStr[1];(*p);p++) {
      (*p2) = (*p);
      if( (*p2) != ' ' && (*p2) != '0' ) {
          p2++;
      }
    }
    (*p2) = 0;

    // Get length of WordStr
    for(WSLen = 0,p = WordStr;(*p);p++) WSLen++;

    // Right pad with zero characters
    for(i = WSLen;i < SoundExLen;i++ ) {
        WordStr[i] = '0';
    }

    // Size to taste
    WordStr[SoundExLen] = 0;

    // Replace first digit with
    // first letter.
    WordStr[0] = FirstLetter;

    // Copy WordStr to SoundEx
    for(p2 = SoundEx,p = WordStr;(*p);p++,p2++) {
        (*p2) = (*p);
    }
    (*p2) = 0;

    return(SoundExLen);
}
*/

int StringTools::ExecuteCommand( const std::string& cmd, std::string& output, const int maxOutputSize)
{
    FILE* fp;
    bool once = true;
    int nBufferSize = maxOutputSize;
    if(maxOutputSize <= 0){
    	once = false;
    	nBufferSize = 255;}
    char* result = new char[nBufferSize];

    fp = popen(cmd.c_str(),"r");
    size_t outputSize = 0;
    std::stringstream ssOutput;
    do {
    	 outputSize = fread(result,1,nBufferSize-1,fp);
    	 if(outputSize){
    		 result[outputSize] = 0;
    		 ssOutput << result;}
    }
    while( !once && outputSize );
    fclose (fp);
    delete [] result;

    output = ssOutput.str();
    return output.length();
}

bool StringTools::IsNumeric(const std::string& in) {

	std::string::const_iterator iter = in.begin();
	for(;iter != in.end();++iter) {
		if(!isdigit(*iter))
			return false;
	}
	return true;
}

}
