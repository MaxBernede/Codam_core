#include "Harl.hpp"

int	input_search(int i, std::string level){
	std::string search[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++)
    {
        if (search[i] == level)
            break;
	}
	return (i);
}

void Harl::complain(std::string level){
	int i = 0;
	void  (Harl::*table[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = input_search(i, level);
	switch (i)
	{
		case 0: (this->*table[i])();
			i++;
		case 1: (this->*table[i])();
			i++;
		case 2: (this->*table[i])();
			i++;
		case 3 : (this->*table[i])();
			return;
	}
	std::cout << "Error, the argument doesn't exist" << std::endl;
}

void Harl::debug(void){
	std::cout << "[ DEBUG ]" <<std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]" <<std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]" <<std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]" <<std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}