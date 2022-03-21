#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	setWeapon(Weapon &weapon);
	void	attack(void);

private:
	std::string	mName;
	Weapon		&mWeapon;
};

#endif