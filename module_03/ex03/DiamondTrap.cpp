#include "DiamondTrap.h"

#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
  : ClapTrap("default_clap_name"),
    name_("default") {
  std::cout << "DiamondTrap Default Constructor Called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name"),
    name_(name) {
  set_hit_point(FragTrap::get_hit_point());
  set_energy_point(ScavTrap::get_energy_point());
  set_attack_damage(FragTrap::get_attack_damage());
  std::cout << "DiamondTrap Parameterized Constructor Called\n";
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor Called: " << get_name() << '\n';
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  name_ = other.name_;
  hit_point_ = other.hit_point_;
  energy_point_ = other.energy_point_;
  attack_damage_ = other.attack_damage_;
  return *this;
}

const std::string& DiamondTrap::get_name() const {
  return name_;
}

void DiamondTrap::whoAmI() {
  std::cout << "DiamondTrap My name is " << get_name() << '\n';
 std::cout << "ClapTrap My name is " << ClapTrap::get_name() << '\n';
}
