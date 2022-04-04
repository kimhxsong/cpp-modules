#include "DiamondTrap.h"

#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
  : ClapTrap() {}

DiamondTrap::DiamondTrap(const std::string& name)
  : ClapTrap(name + "_clap_name"),
    name_(name) {
  std::cout << "DiamondTrap Default Constructor Called\n";
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor Called: " << name_ << '\n';
}

// void DiamondTrap::takeDamage(unsigned int amount) {
//   if (isTrapBroken() == true) {
//     std::cout << "DiamondTrap " << get_name() <<
//                  " is already completely broken\n";
//     return;
//   }

//   if (get_hit_point() < amount) {
//     set_hit_point(0);
//   } else {
//     set_hit_point(get_hit_point() - amount);
//   }

//   std::cout << "DiamondTrap " << get_name() <<
//                " takes Damages " << amount <<
//                " and has " << get_hit_point() <<
//                " hit points.\n";
// }

// void DiamondTrap::beRepaired(unsigned int amount) {
//   if (isTrapBroken() == true) {
//     std::cout << "DiamondTrap " << get_name() <<
//                  " is already completely broken. it can't be fixed\n";
//     return;
//   }

//   if (get_energy_point() == 0) {
//     std::cout << "DiamondTrap " << get_name() <<
//                  " has not enough energy to be repaired\n";
//     return;
//   }

//   set_energy_point(get_energy_point() - 1);
//   set_hit_point(get_hit_point() + amount);
//   std::cout << "DiamondTrap " << get_name() <<
//                " is repaired " << amount <<
//                " and has " << get_hit_point() <<
//                " hit points.\n";
// }

void DiamondTrap::whoAmI() {
  std::cout << "My name is " << get_name() << '\n';
}
