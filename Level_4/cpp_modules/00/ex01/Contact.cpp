#include "Contact.hpp"

void Contact::print_line(){
	std::cout << std::setw(10) << std::right << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) << " | ";
	std::cout << std::setw(10) << std::right << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) << " | ";
	std::cout <<  std::setw(10) << std::right << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname) << std::endl;
}

void Contact::print_contact(){
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << secret << std::endl;
}

void Contact::set_contact(std::string first, std::string last, std::string nick, std::string phone, std::string s){
	first_name = first;
	last_name = last;
	nickname = nick;
	phone_number = phone;
	secret = s;
};
