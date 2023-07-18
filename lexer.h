#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "token.h"

class Lexer 
{
private:
	std::string source;
	int source_size;
	int curr_pos;
	char curr_char;
	bool is_comment;

public:
	enum TokenEnum {
		TOKEN_EOF = -1,
		TOKEN_NEWLINE = 0,
		TOKEN_TODO_TEXT = 1,
		TOKEN_IGNORE = 99,

		TOKEN_COMMENT = 100,
		TOKEN_COLON = 101,

		TOKEN_TODO = 200
	};

	Lexer() = default;
	Lexer(std::string source);
	void advance();
	char peek();
	void skip_whitespace();
	void clear_stream();
	std::string type_to_keyword(TokenEnum type);
	TokenEnum keyword_to_type(std::string keyword);
	Token get_token();

};