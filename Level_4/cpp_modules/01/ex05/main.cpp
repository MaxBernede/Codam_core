#include "Harl.hpp"

int main(void)
{
	Harl hello;

	std::cout << "[ WARNING ]" << std::endl;
	hello.complain("WARNING");

	std::cout << "[ ERROR ]" << std::endl;
	hello.complain("ERROR");

	std::cout << "[ INFO ]" << std::endl;
	hello.complain("INFO");

	std::cout << "a" << std::endl;
	hello.complain("a");
}
