#ifndef CLASSES_HPP
#define CLASSES_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact
{
public:
	Contact(){
		//std::cout << "Contact Constructor called"<< std::endl;
	}
	void	print_contact();
	void	print_line();
	int		exist();
	void	fill_contact(std::string first, std::string last, std::string nick, std::string phone, std::string s);
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
};

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
