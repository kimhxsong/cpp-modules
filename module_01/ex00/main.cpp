#include <string>
#include <new>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombieOnStack("Stack");
	Zombie	*zombieOnHeap = newZombie("Heap");

	zombieOnStack.announce();
	zombieOnHeap->announce();
	randomChump("Block");
	delete zombieOnHeap;
}