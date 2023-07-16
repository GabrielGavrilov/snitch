#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "file.h"
#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[])
{

	std::string phrase = "\n";
	Lexer lexer = Lexer(phrase);

	Token token = lexer.get_token();

	while(token.type != lexer.TOKEN_EOF)
	{
		std::cout << token.type << " :: " << token.value << std::endl;
		token = lexer.get_token();
	}

	return 0;
}