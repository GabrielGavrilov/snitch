#include "snitch.h"
#include "file.h"
#include "lexer.h"
#include "node.h"
#include "parser.h"
#include "token.h"

void initialize(char* argv)
{
	std::string configFile = File::getGitConfigFile(argv);

	gitUrl = File::getGithubRepoUrl(config_file);
	gitToken = File::getFileContents("token.txt");
}

int main(int argc, char* argv[])
{
	initialize(argv[1]);
	std::cout << git_url << std::endl;
	std::cout << git_token << std::endl;
}
