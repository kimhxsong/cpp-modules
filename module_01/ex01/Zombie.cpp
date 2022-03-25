#include "Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie() {
  std::cout << "Defalut Constructor Called!\n";
}

Zombie::Zombie(std::string name)
  : name_(name) {
  std::cout << name << ": Contructor Called!\n";
}

Zombie::~Zombie() {
  std::cout << name_ << ": Destructor Called!\n";
}

void Zombie::setName(std::string name) {
  name_ = name;
}

std::string Zombie::getName() {
  return name_;
}

void Zombie::announce() {
  std::cout << getName() << ":  BraiiiiiiinnnzzzZ...\n";
}
