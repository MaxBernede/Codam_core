#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
    ScavTrap Robot("Robot");

    std::cout << std::endl;
    Robot.attack("Zeke");
    std::cout << std::endl;
    Robot.guardGate();
    std::cout << std::endl;
    return 0;
}