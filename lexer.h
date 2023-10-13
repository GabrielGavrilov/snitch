#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "token.h"

class Lexer {
private:
	std::vector<std::string> temp;
	std::string src;
	int src_size;
	char curr_char;
	int curr_pos;
public:
	enum TokenType {
		TOKEN_EOF = -1,
		TOKEN_NEWLINE = 0,
		TOKEN_TEST = 1
	};

	Lexer() = default;
	Lexer(std::string source);
	void lexer_advance();
	char lexer_peek();
	void lexer_skip_whitespace();
	Token lexer_generate_token();
};