#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: mName(name)
	, mWeapon(weapon) {}

HumanA::~HumanA(void) {}


void	HumanA::setWeapon(Weapon &weapon)
{
	mWeapon = weapon;
}

void	HumanA::attack(void)
{
	std::cout
		<< mName << "attacks with his"
		<< mWeapon.getType() << std::endl;
}
