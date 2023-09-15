#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap();
	FragTrap(const std::string &n);
	~FragTrap();

    FragTrap(const FragTrap &obj);
    FragTrap &operator=(const FragTrap &obj);

    void highFivesGuys(void);
};

#endif