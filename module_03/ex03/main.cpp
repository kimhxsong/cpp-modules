#include <iostream>

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"
#include "DiamondTrap.h"

int main(void) {
  {
    ClapTrap clap("Base");

    clap.attack("target_0");
    clap.takeDamage(3);
    clap.beRepaired(3);
  }

  std::cout << std::endl;

  {
    ScavTrap scav("Derived1");

    scav.attack("target_1");
    scav.takeDamage(5);
    scav.beRepaired(5);
    scav.guardGate();
  }

  std::cout << std::endl;

  {
    FragTrap frag("Derived2");

    frag.attack("target_2");
    frag.takeDamage(5);
    frag.beRepaired(5);
    frag.highFiveGuys();
  }

  std::cout << std::endl;

  {
    DiamondTrap diamond("Diamond");
    diamond.takeDamage(5);
    diamond.beRepaired(5);
    diamond.whoAmI();
  }

  return 0;
}
