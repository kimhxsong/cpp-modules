#include <string>
#include <new>
#include <iostream>

#include "Zombie.hpp"

int main(void) {
  Zombie *zombies = zombieHorde(42, "cadet");
  for (int i = 0; i < 42; ++i) {
    std::cout << '[' << i << ']';
    zombies[i].announce();
  }
  delete[] zombies;
  return 0;
}
