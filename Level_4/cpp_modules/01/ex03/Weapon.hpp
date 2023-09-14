#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Weapon
{
public:
	Weapon();
	Weapon(std::string str);
	~Weapon();
	const std::string &getType();
	void	setType(std::string str);
private:
	std::string type;
};

#endif