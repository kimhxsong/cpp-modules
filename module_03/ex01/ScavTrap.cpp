#include "ScavTrap.h"

#include <iostream>
#include <string>

ScavTrap::ScavTrap()
  : name_("default") {
  std::cout << "ScavTrap Default Constructor Called\n";
}

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap(name + "_clap_name"),
    name_(name) {
  std::cout << "ScavTrap Parameterized Constructor Called\n";
  set_hit_point(100);
  set_energy_point(50);
  set_attack_damage(20);
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap Destructor Called: " << name_ << '\n';
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
  name_ = other.name_;
  hit_point_ = other.hit_point_;
  energy_point_ = other.energy_point_;
  attack_damage_ = other.attack_damage_;
  return *this;
}

const std::string& ScavTrap::get_name() const {
  return name_;
}

void ScavTrap::attack(const std::string& target) {
  if (isTrapBroken() == true) {
    std::cout << "ScavTrap " << get_name() <<
                 " is already completely broken, can't do anything\n";
    return;
  }

  if (hasNoEnergy() == true) {
    std::cout << "ScavTrap " << get_name() <<
                 " has not enough energy to attack\n";
    return;
  }

  set_energy_point(get_energy_point() - 1);
  std::cout << "ScavTrap " << get_name() <<
               " attacks " << target <<
               ", causing " << get_attack_damage() <<
               " points of damage!\n";
}

void ScavTrap::guardGate() {
  if (isTrapBroken() == true) {
    std::cout << "ScavTrap " << get_name() <<
                 " is already completely broken\n";
    return;
  }

  std::cout << "ScavTrap is now in Gate keeper mode.\n";
}
