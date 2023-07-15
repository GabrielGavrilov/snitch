#include <iostream>
#include <vector>

#include "file.h"

int main(int argc, char* argv[])
{

	if(!argv[1])
	{
		std::cout << "[Snitch]: Directory was not provided." << std::endl;
		exit(1);
	} 

	std::vector<std::string> d = file::list_directory(argv[1]);

	for(int i = 0; i < d.size(); i++) {
		std::cout << i << " " << d[i] << std::endl;
	}


	return 0;
}