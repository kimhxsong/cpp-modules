#include "ClapTrap.h"

#include <iostream>
#include <string>

ClapTrap::ClapTrap()
  : name_("Default"),
    energy_point_(0),
    attack_damage_(0),
    hit_point_(0) {
  std::cout << "ClapTrap Default Constructor Called: " << name_ << '\n';
}

ClapTrap::ClapTrap(const std::string& name)
  : name_(name),
    energy_point_(10),
    attack_damage_(0),
    hit_point_(10) {
  std::cout << "ClapTrap Parameterized Constructor Called: " << name_ << '\n';
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap Destructor Called: " << name_ << '\n';
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  name_ = other.name_;
  energy_point_ = other.energy_point_;
  attack_damage_ = other.attack_damage_;
  hit_point_ = other.hit_point_;
  return *this;
}

const std::string& ClapTrap::get_name() const {
  return name_;
}

unsigned int ClapTrap::get_energy_point() const {
  return energy_point_;
}

unsigned int ClapTrap::get_attack_damage() const {
  return attack_damage_;
}

unsigned int ClapTrap::get_hit_point() const {
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
  if (isTrapBroken() == true) {
    std::cout << "ClapTrap " << get_name() <<
                 " is already completely broken, can't do anything\n";
    return;
  }

  if (hasNoEnergy() == true) {
   std::cout << "ClapTrap " << get_name() <<
                 " has not enough energy to attack\n";
    return;
  }

  set_energy_point(get_energy_point() - 1);
  std::cout << "ClapTrap " << get_name() <<
               " attacks " << target <<
               ", causing " << get_attack_damage() <<
               " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (isTrapBroken() == true) {
    std::cout << "ClapTrap " << get_name() <<
                 " is already completely broken\n";
    return;
  }

  if (get_hit_point() < amount) {
    set_hit_point(0);
  } else {
    set_hit_point(get_hit_point() - amount);
  }

  std::cout << "ClapTrap " << get_name() <<
               " takes Damages " << amount <<
               " and has " << get_hit_point() <<
               " hit points.\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (isTrapBroken() == true) {
    std::cout << "ClapTrap " << get_name() <<
                 " is already completely broken. it can't be fixed\n";
    return;
  }

  if (hasNoEnergy() == true) {
    std::cout << "ClapTrap " << get_name() <<
                 " has not enough energy to be repaired\n";
    return;
  }

  set_energy_point(get_energy_point() - 1);
  set_hit_point(get_hit_point() + amount);
  std::cout << "ClapTrap " << get_name() <<
               " is repaired " << amount <<
               " and has " << get_hit_point() <<
               " hit points.\n";
}

void ClapTrap::displayInfo() {
  std::cout << "Name: " << get_name() << '\n' <<
               "Energy Point: " << get_energy_point() << '\n' <<
               "Attack Damage: " << get_attack_damage() << '\n' <<
               "Hit Point: " << get_hit_point() << "\n\n";
}

bool ClapTrap::isTrapBroken() {
  return (get_hit_point() == 0);
}

bool ClapTrap::hasNoEnergy() {
  return (get_energy_point() == 0);
}
