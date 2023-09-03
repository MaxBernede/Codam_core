#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	return (new Zombie(name));
}

Zombie *zombieHorde(int N, std::string name){
	Zombie *zombies[N];

	for (int i = 0; i < N; i++){
		zombies[i] = newZombie(name);
	}
	return zombies[0];
}

