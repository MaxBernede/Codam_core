#include "Classes.hpp"

Contact PhoneBook::ask_data()
{
	Contact new_c;
	std::string first, last, phone, secret;

	while (first.empty()) {
		std::cout << "Enter First Name: ";
		std::getline(std::cin, first);
	}

	while (last.empty()) {
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, last);
	}

	while (phone.empty()) {
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, phone);
	}

	while (secret.empty()) {
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, secret);
	}

	new_c.fill_contact(first, last, phone, secret);
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

void PhoneBook::SEARCH(){
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Contact " << i << std::endl;
		contacts[i].print_contact();
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

void Contact::fill_contact(std::string first, std::string last, std::string phone, std::string s){
	first_name = first;
	last_name = last;
	phone_number = phone;
	secret = s;
};
