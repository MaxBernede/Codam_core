#include "Classes.hpp"

Contact PhoneBook::ask_data()
{
	Contact new_c;
	std::string first, last, nick, phone, secret;

	while (first.empty()) {
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first);
	}

	while (last.empty()) {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last);
	}

	while (nick.empty()) {
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, nick);
	}

	while (phone.empty()) {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phone);
	}

	while (secret.empty()) {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, secret);
	}

	new_c.fill_contact(first, last, nick, phone, secret);
	return (new_c);
};

void PhoneBook::ADD(){
	if (size < 8)
	{
		contacts[size] = ask_data();
		++size;
	}
	else
	{
		for (int i = 0; i < (size - 1); ++i)
		{
			contacts[i] = contacts[i + 1];
		}
		contacts[size - 1] = ask_data();
	}
}

void Contact::print_line(){
	std::cout << std::setw(10) << std::right << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << " | ";
	std::cout << std::setw(10) << std::right << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << " | ";
	std::cout <<  std::setw(10) << std::right << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}


void PhoneBook::SEARCH(){
	std::cout << "   Index    | First Name |  Last Name |   Nickname " << std::endl;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "     " << i << "      | ";
		contacts[i].print_line();
	}
}

int PhoneBook::getsize(){
	return (this->size);
}

void Contact::print_contact(){
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;

}

void Contact::fill_contact(std::string first, std::string last, std::string nick, std::string phone, std::string s){
	first_name = first;
	last_name = last;
	nickname = nick;
	phone_number = phone;
	secret = s;
};
