#include <iostream>

#include "ClapTrap.h"
#include "ScavTrap.h"

int main(void) {
  ClapTrap clap("Base");

  clap.attack("target_1");
  clap.takeDamage(3);
  clap.beRepaired(3);

  ScavTrap scav("Derived1");

  scav.attack("target_1");
  scav.takeDamage(5);
  scav.beRepaired(5);

  return 0;
}
