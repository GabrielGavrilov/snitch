#include "todo.h"

std::vector<std::string> todo::generate_todo_list_from_file(std::string path)
{
	std::vector<std::string> todo_list;

	std::string line;
	std::ifstream file;
	file.open(path);

	if(!file.is_open())
	{
		std::cout << "[Snitch]: File does not exist." << std::endl;
	}

	while(std::getline(file, line))
	{
		std::cout << line << std::endl;
		todo_list.push_back(todo::check_for_comment(line));
	}

	return todo_list;
}

std::string todo::check_for_comment(std::string text)
{
	if(text.find("//") != std::string::npos)
	{
		todo::check_for_todo_item(text);
	}
}

std::string todo::check_for_todo_item(std::string text)
{
	if(text.find("TODO") != std::string::npos)
	{
		std::string todo_item = text.substr(text.find("TODO:")+6, text.length());
		return todo_item;
	}
}