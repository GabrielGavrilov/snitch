#include <iostream>
#include "file.h"

int main(int argc, char* argv[])
{

	file::list_directory(argv[1]);

	return 0;
}