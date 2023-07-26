#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		for (int c = 0; argv[i][c]; ++c)
		{
			if (argv[i][c] <= 'z' && argv[i][c] >= 'a')
				argv[i][c] -= 32;
			std::cout << (argv[i][c]);
		}
	}
	std::cout << std::endl;
	return 0;
}
