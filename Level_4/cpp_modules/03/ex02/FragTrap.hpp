#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
	FragTrap(std::string n);
	~FragTrap();
    void highFivesGuys(void);
};

#endif