#pragma once

#include <iostream>

class Node
{
public:
	enum NodeTypes
	{
		NODE_TITLE
	};

	Node::NodeTypes type;
	std::string data;

	Node() = default;
	Node(NodeTypes node_type, std::string node_data) 
	{
		type = node_type;
		data = node_data;
	}
};