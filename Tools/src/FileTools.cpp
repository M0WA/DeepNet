/**
 * @file FileTools.cpp
 * @author Moritz Wagner
 * @date 30.11.2012
 */

#include "FileTools.h"

#include <cstdio>
#include <cstring>
#include <dirent.h>

#include "StringTools.h"
#include "PCRERegex.h"

namespace tools {

FileTools::FileTools() {
}

FileTools::~FileTools() {
}

bool FileTools::FileExists(const std::string& fileName) {
	bool success = false;
	FILE *fp = fopen(fileName.c_str(), "r");
	if (fp != NULL) {
		success = true;
		fclose(fp);}
	return success;
}

bool FileTools::ReadFile(const std::string& fileName, std::string& fileContents) {

	std::vector<std::string> lines;
	if(!ReadFile(fileName, lines))
		return false;

	std::vector<std::string>::iterator iterLines = lines.begin();
	for(;iterLines != lines.end();++iterLines) {
		fileContents.append(*iterLines + '\n');	}
	return true;
}

bool FileTools::ReadFile(const std::string& fileName,std::vector<std::string>& lines) {

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(fileName.c_str(), "r");
	if (fp == NULL)
		return false;

	while ((read = getline(&line, &len, fp)) != -1)	{
		std::string sLine = std::string(line);
		StringTools::ReplaceString("\r","",sLine);
		StringTools::ReplaceString("\n","",sLine);
		StringTools::ReplaceString("\t","",sLine);
		lines.push_back(sLine);
		free(line);
		line = 0;
	}
	if(line)
		free(line);

	fclose(fp);
	return (lines.size() > 0);
}

bool FileTools::WriteFile(const std::string& fileName, const std::string& fileContents, const bool append) {

	FILE *fp;
	fp = fopen(fileName.c_str(), ( append ? "w" : "a") );
	if (fp == NULL)
		return false;

	fputs(fileContents.c_str(),fp);
	fclose(fp);
	return true;
}

void FileTools::ListDirectory(std::vector<std::string>& files, const std::string& directory, const bool onlyFiles)
{
	ListDirectory(files, directory, ".*", onlyFiles);
}

void FileTools::ListDirectory(std::vector<std::string>& files, const std::string& directory, const std::string& matchString, const bool onlyFiles)
{
	DIR* dirHandle = opendir(directory.c_str());
	if (dirHandle) {

		tools::PCRERegex regexFileName(matchString,true);

		struct dirent * dirEntry = 0;
		while ( (dirEntry = readdir(dirHandle)) != 0 ) {

			//only normal files, not dots (. and ..)
			if ( strcmp(dirEntry->d_name, ".") &&
				 strcmp(dirEntry->d_name, "..")   )
			{
				switch(dirEntry->d_type) {

				case DT_DIR: //directory
					if (!onlyFiles){
						if(regexFileName.Match(dirEntry->d_name))
							files.push_back(dirEntry->d_name);
					}
					break;
				case DT_REG: //regular file
					if(regexFileName.Match(dirEntry->d_name))
						files.push_back(dirEntry->d_name);
					break;

				case DT_FIFO: 		//named pipe, or FIFO
				case DT_SOCK: 		//local-domain socket
				case DT_CHR: 		//character device
				case DT_BLK:		//block device
				case DT_UNKNOWN: 	//type is unknown. On some systems this is the only value returned
				default:
					break;
				}
			}
		}

		closedir(dirHandle);
	}
}

bool FileTools::DeleteFile(const std::string& fileName) {

	return (remove(fileName.c_str()) == 0);
}

bool FileTools::CompareFiles(const std::string& file1,const std::string& file2) {

	std::string content1, content2;
	if(!FileTools::ReadFile(file1,content1))
		return false;
	if(!FileTools::ReadFile(file2,content2))
		return false;
	return (content1.compare(content2) == 0);
}

}
