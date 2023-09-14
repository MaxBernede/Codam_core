#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
    FragTrap Frag("Frank");

    std::cout << std::endl;
    Frag.highFivesGuys();
    std::cout << std::endl;

    return 0;
}