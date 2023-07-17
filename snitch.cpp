#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "file.h"
#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[])
{

	std::string conf = file::get_git_config_file(argv[1]);
	file::get_github_repo_url(conf);	

	return 0;
}
