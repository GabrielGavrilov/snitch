#include "parser.h"

Parser::Parser(Lexer lexer)
{
	this->lexer = lexer;
	this->current_token = NULL;
	this->peek_token = NULL;
	advance();
	avance();
}

bool Parser::check(int token_type)
{
	return token_numb == this->current_token.type;
}

bool Parser::check_peek(int token_type)
{
	return token_numb == this->peek_token.type;
}

void Parser::advance()
{
	this->current_token = this->peek_token;
	this->peek_token = this->lexer.get_token();
}

void Parser::program()
{
	std::cout << "{SNITCH PROGRAM}" << std::endl;

	while(check(this->lexer.TOKEN_NEWLINE))
		advance();

	while(!check(this->lexer.TOKEN_EOF))
		statement();
}

void Parser::statement()
{
	if(this->current_token.type == this->lexer.TOKEN_COMMENT)
	{
		std::cout << "{COMMENT STATEMENT}" << std::endl;
		advance()
	}


	newline();
}

void Parser::newline()
{
	std::cout << "{COMMENT STATEMENT OVER}" << std::endl;

	while(check(this->lexer.TOKEN_NEWLINE))	
		advance();
}