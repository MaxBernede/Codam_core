#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class PhoneBook
{
public:
	PhoneBook(){
		size = 0;
		//std::cout << "Constructor called"<< std::endl;
	}
	void ADD();
	int getsize();
	void SEARCH();
private:
	Contact ask_data();
	Contact contacts[8];
	int size;
};

#endif
