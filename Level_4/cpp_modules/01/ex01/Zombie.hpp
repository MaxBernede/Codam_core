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
	void set_name(std::string n);
private:
	std::string name;
};

Zombie *zombieHorde(int n, std::string name);

#endif
