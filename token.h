#pragma once

#include <iostream>

class Token 
{
public:
	int type;
	const char* value;
	
	Token() = default;
	Token(int token_type, const char* token_value) 
	{
		type = token_type;
		value = token_value;
	}
};