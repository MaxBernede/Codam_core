#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap Zeke("Zeke");

    Zeke.attack("Ennemy");
    Zeke.takeDamage(2);
    Zeke.beRepaired(1);
    Zeke.takeDamage(9);
    Zeke.attack("Ennemy");
    return 0;
}