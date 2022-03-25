#include "HumanA.hpp"

#include <iostream>
#include <string>

#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
  : name_(name),
    weapon_(weapon) {}

HumanA::~HumanA() {}

void HumanA::setWeapon(Weapon &weapon) {
  weapon_ = weapon;
}

void HumanA::attack() {
  std::cout << name_ << " attacks with his " << weapon_.getType() << '\n';
}
