#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "좀비 할당!\n";
};

Zombie::Zombie(std::string name)
{
	mName = name;
	std::cout << name << "좀비 생성!\n";
}

Zombie::~Zombie(void)
{
	std::cout << mName << " 좀비 소멸!\n";
}

void	Zombie::setName(std::string name)
{
	mName = name;
}

std::string	Zombie::getName(void)
{
	return (mName);
}

void	Zombie::announce(void)
{
	std::cout << getName() << " 으갸갸...갸갸각!\n";
}