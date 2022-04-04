#include "FragTrap.h"

#include <iostream>
#include <string>

FragTrap::FragTrap() {
  std::cout << "FragTrap Default Constructor Called\n";
}

FragTrap::FragTrap(const std::string& name)
  : name_(name) {
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


void FragTrap::attack(const std::string& target) {
  if (isTrapBroken() == true) {
    std::cout << "FragTrap " << get_name() <<
                 " is already completely broken, can't do anything\n";
    return;
  }

  if (get_energy_point() == 0) {
    std::cout << "FragTrap " << get_name() <<
                 " has not enough energy to attack\n";
    return;
  }

  set_energy_point(get_energy_point() - 1);
  std::cout << "FragTrap " << get_name() <<
               " attacks " << target <<
               ", causing " << get_attack_damage() <<
               " points of damage!\n";
}

void FragTrap::takeDamage(unsigned int amount) {
  if (isTrapBroken() == true) {
    std::cout << "FragTrap " << get_name() <<
                 " is already completely broken\n";
    return;
  }

  if (get_hit_point() < amount) {
    set_hit_point(0);
  } else {
    set_hit_point(get_hit_point() - amount);
  }

  std::cout << "FragTrap " << get_name() <<
               " takes Damages " << amount <<
               " and has " << get_hit_point() <<
               " hit points.\n";
}

void FragTrap::beRepaired(unsigned int amount) {
  if (isTrapBroken() == true) {
    std::cout << "FragTrap " << get_name() <<
                 " is already completely broken. it can't be fixed\n";
    return;
  }

  if (get_energy_point() == 0) {
    std::cout << "FragTrap " << get_name() <<
                 " has not enough energy to be repaired\n";
    return;
  }

  set_energy_point(get_energy_point() - 1);
  set_hit_point(get_hit_point() + amount);
  std::cout << "FragTrap " << get_name() <<
               " is repaired " << amount <<
               " and has " << get_hit_point() <<
               " hit points.\n";
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
