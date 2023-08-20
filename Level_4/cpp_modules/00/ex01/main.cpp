#include "Phonebook.hpp"

int main() {
	PhoneBook	phonebook;
	std::string	cmd;

	std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "ADD" || cmd == "add")
			phonebook.ADD();
		else if (cmd == "SEARCH" || cmd == "search")
			phonebook.SEARCH();
		else if (cmd == "EXIT" || cmd == "exit")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
	}
	std::cout << "Exit" << std::endl;
	return 0;
}
