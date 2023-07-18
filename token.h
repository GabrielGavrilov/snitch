#pragma once

#include <iostream>

class Token 
{
public:
	int type;
	std::string value;
	
	Token() = default;
	Token(int token_type, std::string token_value) 
	{
		type = token_type;
		value = token_value;
	}
};