#include "todo.h"

std::vector<std::string> todo::generate_todo_list_from_file(std::string path)
{
	std::vector<std::string> todo_list;

	std::string line;
	std::ifstream file;
	file.open(path);

	if(!file.is_open())
	{
		std::cout << "[Snitch]: There has been an issue." << std::endl;
	}

	while(std::getline(file, line))
	{
		todo_list.push_back(get_todo_item(line));
	}

	return todo_list;
}

std::string todo::get_todo_item(std::string text)
{
	if(text.find("//") != std::string::npos)
	{
		return text;
	}

	return "";
}
