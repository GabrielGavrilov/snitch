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
	std::string git_config_file = File::get_git_config_file_path(argv);

	github_url = File::get_github_repo_url(git_config_file);
	github_token = File::get_file_contents("token.txt");
}

int main(int argc, char* argv[])
{
	initialize(argv[1]);

	std::string src = "//";
	Lexer lexer = Lexer(src);

	Token token = lexer.lexer_generate_token();
	while(token.type != -1) {
		std::cout << token.type << " :: " << token.value << std::endl;
		token = lexer.lexer_generate_token();
	}
}
