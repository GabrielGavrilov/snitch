#include "file.h"

std::string file::get_file_contents(std::string path)
{
	std::ifstream file(path);

	if(file)
	{
		file.seekg(0, std::ios::end);
		const auto size = file.tellg();

		std::string contents(size, ' ');
		file.seekg(0);
		file.read(&contents[0], size);

		file.close();
		return contents;
	}

	else 
	{
		std::cout << "[Snitch]: File does not exist!" << std::endl;
		exit(1);
	}
}

void file::list_directory(std::string path)
{
	for(const auto & entry : std::filesystem::directory_iterator(path)) 
	{
		std::string dir_path = entry.path();
		// std::cout << dir_path << std::endl;

		if(entry.is_directory())
			file::list_directory(dir_path);
		
		else 
		{
			std::string content = file::get_file_contents(dir_path);
			std::cout << content << std::endl;
			std::cout << std::endl;
		}
		
	}
}

