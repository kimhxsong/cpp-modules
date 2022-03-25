#include "Zombie.hpp"

#include <string>
#include <new>

Zombie* newZombie(std::string name) {
  Zombie *zombie = new Zombie(name);
  return zombie;
}
