#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <filesystem>

class file 
{
public:
	static std::string get_file_contents(std::string path);
	static void list_directory(std::string path);
};