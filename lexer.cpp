#include "lexer.h"

Lexer::Lexer(std::string source) 
{
	this->source = source + "\n";
	this->curr_pos = -1;
	this->source_size = source.size()+1;
	this->curr_char = NULL;
	advance();
}

void Lexer::advance()
{
	this->curr_pos++;

	if(this->curr_pos >= this->source_size)
		this->curr_char = '\0';

	else
		this->curr_char = this->source[this->curr_pos];
}

char Lexer::peek() 
{
	if(this->curr_pos+1 >= this->source_size)
		return '\0';

	return this->source[this->curr_pos+1];
}

void Lexer::skip_whitespace()
{
	while(this->curr_char == ' ' || this->curr_char == '\t')
		advance();
}

Token Lexer::get_token()
{
	skip_whitespace();
	Token token;

	if(this->curr_char == '\n')
	{
		token = Token(TOKEN_NEWLINE, &this->curr_char);
	}

	else if(this->curr_char == '\0')
	{
		token = Token(TOKEN_EOF, &this->curr_char);
	}

	advance();
	return token;
}