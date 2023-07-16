#include "file.h"

std::string file::get_file_contents(std::string path)
{
	std::ifstream file(path);

	if(file)
	{
		file.seekg(0, std::ios::end);
		uint8_t size = file.tellg();

		std::string contents(size, ' ');
		file.seekg(0);
		file.read(&contents[0], size);

		file.close();
		return contents;
	}

	else 
	{
		std::cout << "[Snitch]: File does not exist." << std::endl;
		exit(1);
	}
}

std::vector<std::string> file::get_contents_in_directory(std::string path)
{

	std::vector<std::string> directory_list;

	for(std::filesystem::directory_entry entry : std::filesystem::directory_iterator(path)) 
	{
		std::string dir_path = entry.path();
		
		if(dir_path.find(".git") != std::string::npos)
			continue;

		else 
			directory_list.push_back(dir_path);
	}

	return directory_list;
}