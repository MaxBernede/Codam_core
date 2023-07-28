#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie *zp = new Zombie(name);
	return (zp);
}
