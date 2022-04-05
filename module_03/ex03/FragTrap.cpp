#include "FragTrap.h"

#include <iostream>
#include <string>

FragTrap::FragTrap()
  : name_("default") {
  std::cout << "FragTrap Default Constructor Called\n";
  set_hit_point(100);
  set_attack_damage(30);
}

FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name + "_clap_name"),
    name_(name) {
  std::cout << "FragTrap Parameterized Constructor Called\n";
  set_hit_point(100);
  set_energy_point(100);
  set_attack_damage(30);
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap Destructor Called: " << name_ << '\n';
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  name_ = other.name_;
  hit_point_ = other.hit_point_;
  energy_point_ = other.energy_point_;
  attack_damage_ = other.attack_damage_;
  return *this;
}

const std::string& FragTrap::get_name() const {
  return name_;
}

void FragTrap::highFiveGuys() {
  if (isTrapBroken() == true) {
    std::cout << "FragTrap " << get_name() <<
                 " is already completely broken\n";
    return;
  }

  std::cout << "FragTrap " << get_name() <<
               " Let's highfive guys!\n";
}
