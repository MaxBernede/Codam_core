#include "DiamondTrap.hpp"

//ressources : https://www.scaler.com/topics/cpp/multiple-inheritance-in-cpp/

int main( void ) {

    DiamondTrap Diam("Diams");
    std::cout << std::endl;

    Diam.attack("Kole");
    std::cout << std::endl;

    Diam.whoAmI();
    std::cout << std::endl;

    return 0;
}