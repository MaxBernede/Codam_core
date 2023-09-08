#include "Zombie.hpp"

int main() {
	int N = 10;
	Zombie *horde = zombieHorde(N, "John");

	for (int i = 0; i < N; i++){
		horde[i].announce();
	}

	for (int i = 0; i < N; i++){
		delete &horde[i];
	}
	return 0;
}
