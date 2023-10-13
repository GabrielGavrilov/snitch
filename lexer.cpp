#include "lexer.h"

Lexer::Lexer(std::string source)
{
	this->src = source + "\n";
	this->src_size = this->src.size();
	this->curr_pos = -1;
	this->lexer_advance();
}

void Lexer::lexer_advance()
{
	this->curr_pos++;
	if(this->curr_pos >= this->src_size)
	{
		this->curr_char = '\0';
	}
	else
	{
		this->curr_char = this->src[this->curr_pos];
	}
}

char Lexer::lexer_peek()
{
	if(this->curr_pos + 1 >= this->src_size) {
		return '\0';
	}

	return this->src[this->curr_pos + 1];
}

void Lexer::lexer_skip_whitespace()
{
	while(this->curr_char == ' ' || this->curr_char == '\t')
	{
		this->lexer_advance();
	}
}

Token Lexer::lexer_generate_token()
{
	this->lexer_skip_whitespace();
	Token token;

	if(this->curr_char == '\n')
	{
		token = Token(TokenType::TOKEN_NEWLINE, &this->curr_char);
	}

	else if(this->curr_char == '/')
	{
		token = Token(TokenType::TOKEN_TEST, &this->curr_char);
	}

	else if(this->curr_char == '\0')
	{
		token = Token(TokenType::TOKEN_EOF, &this->curr_char);
	}

	this->lexer_advance();
	return token;
}