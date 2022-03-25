#include "Weapon.hpp"

#include <string>

Weapon::Weapon(std::string type)
  : type_(type) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType() {
  return (type_);
}

void Weapon::setType(std::string type) {
  type_ = type;
}
