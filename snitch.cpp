#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "file.h"
#include "lexer.h"
#include "token.h"

int main(int argc, char* argv[])
{


	std::string phrase = "blah blah // TODO: Hello World\n blah blah";
	Lexer lexer = Lexer(phrase);

	Token token = lexer.get_token();

	while(token.type != lexer.TOKEN_EOF)
	{
		if(token.type != -99)
			std::cout << token.type << " :: " << token.value << std::endl;

		token = lexer.get_token();
	} 

	return 0;
}