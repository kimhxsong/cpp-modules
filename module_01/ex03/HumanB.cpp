#include <string>

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: mName(name)
{
	mWeapon = NULL;
}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon &weapon)
{
	mWeapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout
		<< mName << "attacks with his"
		<< mWeapon->getType() << std::endl;
}