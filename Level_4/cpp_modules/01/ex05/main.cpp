#include "Harl.hpp"

int main(void)
{
	Harl hello;

	std::cout << "Harl just lost a brain cell" << std::endl;
	hello.complain("ERROR");

	std::cout << "HARL INFO" << std::endl;
	hello.complain("INFO");

	std::cout << "HARL ON A WHOLE OTHER LEVEL" << std::endl;
	hello.complain("a");
}
