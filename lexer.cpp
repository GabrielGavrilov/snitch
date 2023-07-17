#include "lexer.h"

Lexer::Lexer(std::string source) 
{
	this->source = source + "\n";
	this->curr_pos = -1;
	this->source_size = source.size()+1;
	this->curr_char = NULL;
	this->is_comment = false;
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

void Lexer::clear_stream()
{
	this->temp.str(std::string());
}

std::string Lexer::type_to_keyword(TokenEnum type)
{
	switch(type)
	{
	case 200:
		return "TODO";
		break;
	}
}

Lexer::TokenEnum Lexer::keyword_to_type(std::string keyword)
{
	if(keyword == "TODO")
		return TOKEN_TODO;

	else
		return TOKEN_TODO_TEXT;
}

Token Lexer::get_token()
{
	skip_whitespace();
	clear_stream();
	Token token;

	if(this->curr_char == '\n')
	{
		token = Token(TOKEN_NEWLINE, std::string{this->curr_char});
		this->is_comment = false;
	}	

	else if(this->curr_char == '\0')
	{
		token = Token(TOKEN_EOF, std::string{this->curr_char});
	}

	else if(this->curr_char == '/')
	{
		
		this->temp.put(this->curr_char);
		if(peek() == '/')
		{
			advance();
			this->temp.put(this->curr_char);
			token = Token(TOKEN_COMMENT, this->temp.str());
			this->is_comment = true;
		}
	}

	else if(this->curr_char == ':' && this->is_comment)
	{
		token = Token(TOKEN_COLON, std::string{this->curr_char});
	}

	else if(isalpha(this->curr_char) && this->is_comment) 
	{
		this->temp.put(this->curr_char);
		
		while(isalpha(peek()))
		{
			advance();
			this->temp.put(this->curr_char);
		}

		TokenEnum token_type = keyword_to_type(this->temp.str());
		token = Token(token_type, this->temp.str());
	}

	else if(!this->is_comment)
	{
		token = Token(TOKEN_IGNORE, "NULL");
	}

	advance();
	return token;
}