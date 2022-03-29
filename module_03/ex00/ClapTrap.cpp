#include "ClapTrap.h"

#include <iostream>
#include <string>

ClapTrap::ClapTrap(const std::string& name)
  : name_(name),
    energy_point_(10),
    attack_damage_(0),
    hit_point_(10) {
  std::cout << "Constructor Called: " << name_ << '\n';
}

ClapTrap::~ClapTrap() {
  std::cout << "Destructor Called: " << name_ << '\n';
}

unsigned int ClapTrap::get_energy_point() {
  return energy_point_;
}

unsigned int ClapTrap::get_attack_damage() {
  return attack_damage_;
}

unsigned int ClapTrap::get_hit_point() {
  return hit_point_;
}

void ClapTrap::set_energy_point(unsigned int energy_point) {
  energy_point_ = energy_point;
}

void ClapTrap::set_attack_damage(unsigned int attack_damage) {
  attack_damage_ = attack_damage;
}

void ClapTrap::set_hit_point(unsigned int hit_point) {
  hit_point_ = hit_point;
}

void ClapTrap::attack(const std::string& target) {
  set_hit_point(get_hit_point() - 1);
  std::cout << "ClapTrap " << name_ <<
               " attacks " << target <<
               ", causing " << attack_damage_ <<
               " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  set_attack_damage(get_attack_damage() + amount);
  std::cout << "ClapTrap " << name_ <<
               " take Damages " << amount <<
               ", causing " << attack_damage_ <<
               " points of attack damages\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energy_point_ < 0) {
    std::cout << "Lack of energy points\n";
    return;
  }
  set_energy_point(get_energy_point() - amount);
  set_hit_point(get_hit_point() + amount);
  std::cout << "ClapTrap " << name_ <<
               " is repaired " << amount <<
               "hit points, so not energy points" << energy_point_ <<
               '\n';
}
