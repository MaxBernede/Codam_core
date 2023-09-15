#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string n);
	~ClapTrap();

	//Copy constructor
	ClapTrap(const ClapTrap &obj);

	//Operator overload
	ClapTrap &operator=(const ClapTrap &obj);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void	print_life();
	std::string name;

protected:
	virtual std::ostream &me();

private:
	int health;
	int energy;
	int attack_dmg;
};

#endif