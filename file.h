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
	static std::vector<std::string> list_directory(std::string path);
};