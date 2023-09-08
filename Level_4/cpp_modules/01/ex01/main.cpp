#include "Zombie.hpp"

int main() {
	int N = 10;
	Zombie *horde = zombieHorde(N, "John");

	for (int i = 0; i < N; i++){
		horde[i].announce();
	}

	std::cout << "Free the Zombies!" << std::endl;
	delete[] horde;
	// system("leaks zombiehorde");
	return 0;
}
