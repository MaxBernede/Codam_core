#ifndef CLASSES_HPP
#define CLASSES_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Zombie
{
public:
	Zombie();
	Zombie(std::string n);
	~Zombie();
	void announce( void );
private:
	std::string name;
};

Zombie* newZombie(std::string name);
Zombie *zombieHorde(int n, std::string name);

#endif
