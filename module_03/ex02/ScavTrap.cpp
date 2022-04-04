#include "ScavTrap.h"

#include <iostream>
#include <string>

ScavTrap::ScavTrap() {
  std::cout << "ScavTrap Default Constructor Called\n";
}

ScavTrap::ScavTrap(const std::string& name)
  : name_(name) {
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


void ScavTrap::attack(const std::string& target) {
  if (get_hit_point() == 0) {
    std::cout << "ScavTrap " << get_name() <<
                 " is already completely broken, can't do anything\n";
    return;
  }

  if (get_energy_point() == 0) {
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

void ScavTrap::takeDamage(unsigned int amount) {
  if (get_hit_point() == 0) {
    std::cout << "ScavTrap " << get_name() <<
                 " is already completely broken\n";
    return;
  }

  if (get_hit_point() < amount) {
    set_hit_point(0);
  } else {
    set_hit_point(get_hit_point() - amount);
  }

  std::cout << "ScavTrap " << get_name() <<
               " takes Damages " << amount <<
               " and has " << get_hit_point() <<
               " hit points.\n";
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (get_hit_point() == 0) {
    std::cout << "ScavTrap " << get_name() <<
                 " is already completely broken. it can't be fixed\n";
    return;
  }

  if (get_energy_point() == 0) {
    std::cout << "ScavTrap " << get_name() <<
                 " has not enough energy to be repaired\n";
    return;
  }

  set_energy_point(get_energy_point() - 1);
  set_hit_point(get_hit_point() + amount);
  std::cout << "ScavTrap " << get_name() <<
               " is repaired " << amount <<
               " and has " << get_hit_point() <<
               " hit points.\n";
}

void ScavTrap::guardGate() {
  if (get_hit_point() == 0) {
    std::cout << "ScavTrap " << get_name() <<
                 " is already completely broken\n";
    return;
  }

  std::cout << "ScavTrap is now in Gate keeper mode.\n";
}
