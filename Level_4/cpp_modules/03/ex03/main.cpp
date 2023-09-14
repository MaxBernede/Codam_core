#include "DiamondTrap.hpp"

//ressources : https://www.scaler.com/topics/cpp/multiple-inheritance-in-cpp/

int main( void ) {
    // ClapTrap Zeke("Zeke");
    // ScavTrap Scav("Robot");
    // FragTrap Frag("Frank");
    DiamondTrap Diam("Diams");
    std::cout << std::endl;
    Diam.whoAmI();
    std::cout << std::endl;
    Diam.attack("Kole");
    std::cout << std::endl;
    return 0;
}