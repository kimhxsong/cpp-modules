#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(const std::string& name) {
  name_ = name;
  std::cout << name << ": Contructor calld\n";
}

Zombie::~Zombie() {
  std::cout << name_ << ": Destructor called\n";
}

void Zombie::announce(void) {
  std::cout << name_ << ": BraiiiiiiinnnzzzZ...\n";
}
