#ifndef HUMANA_HPP
#define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &w);
	~HumanA(void);
    void    attack(void);
private:
	std::string name;
    Weapon *weapon;
};

#endif