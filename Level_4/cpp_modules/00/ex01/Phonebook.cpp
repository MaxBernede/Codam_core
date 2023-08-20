#include "Phonebook.hpp"
#include <csignal>

void PhoneBook::ADD(){
	if (size < 8){
		contacts[size] = ask_data();
		++size;
	}
	else{
		for (int i = 0; i < (size - 1); ++i)
			contacts[i] = contacts[i + 1];
		contacts[size - 1] = ask_data();
	}
}

Contact PhoneBook::ask_data()
{
	Contact new_c;
	std::string first, last, nick, phone, secret;

	while (first.empty()) {
		if (std::cin.eof()) {
			break;
		}
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first);
	}

	while (last.empty()) {
		if (std::cin.eof()) {
			break;
		}
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last);
	}

	while (nick.empty()) {
		if (std::cin.eof()) {
			break;
		}
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nick);
	}

	while (phone.empty()) {
		if (std::cin.eof()) {
			break;
		}
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phone);
	}

	while (secret.empty()) {
		if (std::cin.eof()) {
			break;
		}
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, secret);
	}

	if (secret.empty())
		exit(1);
	new_c.set_contact(first, last, nick, phone, secret);
	return (new_c);
};

void PhoneBook::SEARCH(){
	std::string index;
	int nb_index;

	std::cout << "   Index    | First Name |  Last Name |   Nickname " << std::endl;
	for (int i = 0; i < size; ++i){
		std::cout << "     " << i << "      | ";
		contacts[i].print_line();
	}
	std::cout << "Enter the index : " << std::endl;
	std::cin >> index;
	nb_index = index[0] - '0';
	if (index.size() == 1 && index[0] >= '0' && index[0] <= '7' && nb_index < getsize())
		contacts[nb_index].print_contact();
	else
		std::cout << "Invalid index" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int PhoneBook::getsize(){
	return (this->size);
}
