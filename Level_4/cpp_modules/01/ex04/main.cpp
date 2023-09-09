#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int error_msg(std::string str)
{
	std::cout << str << std::endl;
	return (0);
}

std::string	loop(std::ifstream &is, std::string old, std::string new_w)
{
	std::string temp, str;
	int pos, start;

	std::getline(is, temp);
	start = 0;
	while (true)
	{
		pos = temp.find(old, start);
		if (pos < 0)
		{
			if (str.empty())
				return temp;
			return str;
		}
		str.append(temp, start, pos - start);
		str += new_w;
		pos += old.length();
		start = pos;
	}
	return NULL;
}

int main(int argc, char **argv)
{
	std::ifstream is;
	std::string new_file, file, old, new_w, str;
	std::ofstream os;
	//std::ostringstream ss;

	if (argc != 4)
		return (error_msg("Error: Correct usage : <filename> <str to replace> <str to add>"));
	file = argv[1];
	old = argv[2];
	new_w = argv[3];

	is.open(argv[1], std::ios::in);
	if (!is)
		return (error_msg("Error in opening the file"));

	str = loop(is, old, new_w);
	std::cout << str << std::endl;
	
	new_file = file + ".replace";
	os.open(new_file.c_str(), std::ios::trunc);
	if (!os)
	{
		is.close();
		return (error_msg("Error in opening the output file"));
	}
	os << str;

	os.close();
	is.close();
	return 0;
}