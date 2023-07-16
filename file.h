#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <vector>

class file 
{
public:
	static std::string get_file_contents(std::string path);
	static std::vector<std::string> get_contents_in_directory(std::string path);
};