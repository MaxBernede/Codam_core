#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap Zeke("Zeke");

    // Zeke.attack("Ennemy");
    // Zeke.takeDamage(2);
    // Zeke.beRepaired(1);
    // Zeke.takeDamage(9);
    // Zeke.attack("Ennemy");

    ClapTrap Copied = Zeke;
    ClapTrap Copiod(Zeke);
    Zeke.name = "MALOUBAR";
    Zeke.takeDamage(1);
    Copied.takeDamage(2);
    Copiod.takeDamage(3);

    Copiod.name = "LOUSTIC";
    // Copied.print_life();
    // Zeke.print_life();
    return 0;
}