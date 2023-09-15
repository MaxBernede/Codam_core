#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const std::string &);
	~ScavTrap();

	ScavTrap(const ScavTrap &obj);
	ScavTrap &operator=(const ScavTrap &obj);

    void guardGate(void);
    void attack(const std::string& target);
private:
    bool guard_mode;
};

#endif