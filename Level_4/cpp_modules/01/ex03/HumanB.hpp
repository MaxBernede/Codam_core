#ifndef HUMANB_HPP
#define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
    ~HumanB();
    void    attack(void);
    void    setWeapon(Weapon &w);
private:
	std::string name;
    Weapon *weapon;
};

#endif