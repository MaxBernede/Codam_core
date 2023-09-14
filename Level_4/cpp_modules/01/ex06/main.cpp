#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl hello;

	if (argc != 2)
	{
		std::cout << "Arg Error: ./harlFilter [msg_type]" << std::endl;
		return 0;
	}
	hello.complain(argv[1]);
}
