#include <vector>
#include "snitch.h"
#include "file.h"
#include "token.h"
#include "lexer.h"

/**
 * Initializes snitch
 */
void initialize(char* argv)
{
	std::string git_config_file = file::get_git_config_file_path(argv);

	github_url = file::get_github_repo_url(git_config_file);
	github_token = file::get_file_contents("token.txt");
}

int main(int argc, char* argv[])
{
	initialize(argv[1]);

	std::cout << github_url << std::endl;
	std::cout << github_token << std::endl;

	return EXIT_SUCCESS;
}
