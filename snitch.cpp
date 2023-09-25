#include <vector>
#include "snitch.h"
#include "file.h"
#include "token.h"

/**
 * Initializes snitch
 */
void initialize(char* argv)
{
	std::string configFile = File::getGitConfigFile(argv);

	gitUrl = File::getGithubRepoUrl(configFile);
	gitToken = File::getFileContents("token.txt");
}

int main(int argc, char* argv[])
{
	initialize(argv[1]);
	std::cout << gitUrl << std::endl;
	std::cout << gitToken << std::endl;
}
