#include <vector>
#include "snitch.h"
#include "file.h"
#include "todo.h"

/**
 * Initializes snitch
 */
void initialize(char* argv)
{
	std::string git_config_file = file::get_git_config_file_path(argv);

	github_url = file::get_github_repo_url(git_config_file);
	github_token = file::get_file_contents("token.txt");
}

// TODO: Add comments
int main(int argc, char* argv[])
{
	initialize(argv[1]);

	std::vector<std::string> directory_list = file::get_contents_in_directory(argv[1]);
	std::vector<std::string> todo_list = todo::generate_todo_list_from_file("./snitch.cpp");

	for(int i = 0; i < todo_list.size(); i++) 
	{
		std::cout << todo_list[i] << std::endl;
	}

	return EXIT_SUCCESS;
}
