#include "HumanB.hpp"

#include <iostream>
#include <string>

#include "Weapon.hpp"

HumanB::HumanB(std::string name)
  : name_(name) {
    weapon_ = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
  weapon_ = &weapon;
}

void HumanB::attack() {
  std::cout << name_ << "attacks with his" << weapon_->getType() << '\n';
}
