#ifndef CLASSES_HPP
#define CLASSES_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Zombie
{
public:
	Zombie(){
		std::cout << "Constructor Called" << std::endl;
		name = "Zombie";
	}
	Zombie(std::string n){
		std::cout << "Constructor n Called" << std::endl;
		name = n;
	}
	~Zombie(){
		std::cout << "Destructor Called" << std::endl;
	}
	void announce( void );
private:
	std::string name;
};

Zombie* newZombie(std::string name);

#endif
