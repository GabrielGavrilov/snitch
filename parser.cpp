#include "parser.h"

Parser::Parser(Lexer lexer)
{
	this->lexer = lexer;
	advance();
	advance();
}

bool Parser::check(int token_type)
{
	return token_type == this->current_token.type;
}

bool Parser::check_peek(int token_type)
{
	return token_type == this->peek_token.type;
}

void Parser::advance()
{
	this->current_token = this->peek_token;
	this->peek_token = this->lexer.get_token();
}

void Parser::program()
{
	while(check(this->lexer.TOKEN_NEWLINE))
		advance();

	while(!check(this->lexer.TOKEN_EOF))
	{
		Node node;
		node = statement();
		std::cout << node.type << " :: " << node.data << std::endl;
	}
}

Node Parser::statement()
{
	Node node = expression();

	if(this->current_token.type == this->lexer.TOKEN_COMMENT)
	{
		advance();
	}

	newline();
	return node;
}

Node Parser::expression()
{
	if(this->current_token.type == this->lexer.TOKEN_TODO)
	{
		advance();
		return Node(Node::NODE_TITLE, "TODO");
	}
}

void Parser::newline()
{
	while(check(this->lexer.TOKEN_NEWLINE))	
		advance();
}