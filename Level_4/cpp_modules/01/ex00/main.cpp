#include "Zombie.hpp"

int main() {
	Zombie zombie;
	Zombie z2("Alfredo");
	Zombie *z3 = newZombie("Keke");

	zombie.announce();
	z2.announce();
	z3->announce();

	randomChump("Chumpy");
	delete z3;
	return 0;
}
