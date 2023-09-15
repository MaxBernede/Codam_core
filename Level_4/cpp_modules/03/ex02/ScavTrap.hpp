#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string);
	~ScavTrap();

    //Copy constructor
	ScavTrap(const ScavTrap &obj);

	//Operator overload
	ScavTrap &operator=(const ScavTrap &obj);

    void guardGate(void);
    void attack(const std::string& target);
private:
    bool guard_mode;
};

#endif