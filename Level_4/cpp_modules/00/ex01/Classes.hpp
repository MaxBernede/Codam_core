#ifndef CLASSES_HPP
#define CLASSES_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Contact
{
public:
	Contact(){
		//std::cout << "Contact Constructor called"<< std::endl;
	}
	void print_contact();
private:
	std::string first_name;
	std::string last_name;
	std::string phone_number;
	std::string darkest_secret;
};

class PhoneBook
{
public:
	PhoneBook(){
		size = 0;
		//std::cout << "Constructor called"<< std::endl;
	}
	void ADD();
	void SEARCH();
	int getsize();
private:
	Contact contacts[8];
	int size;
};

#endif
