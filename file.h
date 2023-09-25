#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <vector>

class File 
{
public:
	static void error(std::string message);
	static std::string getFileContents(std::string path);
	static std::vector<std::string> getContentsInDirectory(std::string path);
	static std::string getGitConfigFilePath(std::string path);
	static std::string getGithubRepoUrl(std::string path);
};
