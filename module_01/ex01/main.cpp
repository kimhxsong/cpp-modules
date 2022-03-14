#include <string>
#include <new>
#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies = zombieHorde(42, "cadet");
	for (int i = 0; i < 42; ++i) {
		zombies[i].announce();
	}
	delete [] zombies;
}