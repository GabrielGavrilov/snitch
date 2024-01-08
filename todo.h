#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class todo 
{
public:
	static std::vector<std::string> generate_todo_list_from_file(std::string path);
private: 
	static std::string get_todo_item(std::string text);
};