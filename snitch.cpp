#include "snitch.h"
#include "file.h"
#include "lexer.h"
#include "parser.h"
#include "token.h"

void initialize(char* argv)
{
	std::string config_file = file::get_git_config_file(argv);

	git_url = file::get_github_repo_url(config_file);
	git_token = file::get_file_contents("token.txt");
}

int main(int argc, char* argv[])
{	
	initialize(argv[1]);
	std::string phrase = "//";

	Lexer lexer = Lexer(phrase);
	Parser parser = Parser(lexer);

	parser.program();

	std::cout << "Parsing completed." << std::endl;

	return 0;
}
