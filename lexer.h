#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "token.h"

class Lexer 
{
private:
	std::string source;
	int source_size;
	int curr_pos;
	char curr_char;

public:
	enum TokenEnum {
		TOKEN_EOF = -1,
		TOKEN_NEWLINE = 0
	};

	Lexer() = default;
	Lexer(std::string source);
	void advance();
	char peek();
	void skip_whitespace();
	Token get_token();

};