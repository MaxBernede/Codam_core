#include "ScalarConverter.hpp"


int main(int argc, char **argv){
	//ScalarConverter a;
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Usage: ./convert [value]" << std::endl;
	return 0;
}
