#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

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

#endif
