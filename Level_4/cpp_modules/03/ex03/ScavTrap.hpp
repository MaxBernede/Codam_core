#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string n);
	~ScavTrap();
    void guardGate(void);
    void attack(const std::string& target);
private:
    bool guard_mode;
};

#endif