#ifndef CONTACT_HPP
#define CONTACT_HPP

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
	void	set_contact(std::string first, std::string last, std::string nick, std::string phone, std::string s);
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
};

#endif
