#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: mType(type)
{};

Weapon::~Weapon() {};

const std::string&	Weapon::getType(void)
{
	return (mType);
}

void	Weapon::setType(std::string type)
{
	mType = type;
}