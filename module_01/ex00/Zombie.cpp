#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	mName = name;
	std::cout << name << "좀비 생성!\n";
}

Zombie::~Zombie(void)
{
	std::cout << mName << " 좀비 소멸!\n";
}

void	Zombie::announce(void)
{
	std::cout << mName << " BraiiiiiiinnnzzzZ...\n";
}