#include "Zombie.hpp"

#include <string>
#include <new>

Zombie* newZombie(const std::string& name) {
  Zombie *zombie = new Zombie(name);
  return zombie;
}
