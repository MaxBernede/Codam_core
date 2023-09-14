#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string n);
	~DiamondTrap();
    void whoAmI();
    void attack(const std::string& target);
private:
	std::string name;
};

#endif