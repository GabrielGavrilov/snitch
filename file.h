#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <filesystem>
#include <vector>

class file
{
public:
	static void error(std::string message);
	static std::string get_file_contents(std::string path);
	static std::vector<std::string> get_contents_in_directory(std::string path);
	static std::string get_git_config_file_path(std::string path);
	static std::string get_github_repo_url(std::string path);
};
