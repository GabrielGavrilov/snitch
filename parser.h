#pragma once

#include <iostream>
#include "token.h"
#include "node.h"
#include "lexer.h"

class Parser 
{
private:
	Lexer lexer;
	Token current_token;
	Token peek_token;
public:
	Parser() = default;
	Parser(Lexer lexer);
	bool check(int token_numb);
	bool check_peek(int token_numb);
	void advance();
	void program();
	Node statement();
	Node expression();
	void newline();
};