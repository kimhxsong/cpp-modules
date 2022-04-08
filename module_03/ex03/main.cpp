#include <iostream>

#include "ClapTrap.h"
#include "FragTrap.h"
#include "ScavTrap.h"
#include "DiamondTrap.h"

/*
  ClapTrap
  - Hit point (10)
  - Energy points (10)
  - Attack damage (0)

  ScavTrap
  - Hit point (100)
  - Energy points (50)
  - Attack damage (20)

  FragTrap
  - Hit point (100)
  - Energy points (100)
  - Attack damage (30)

  DiamondTrap
  - Hit point (100) // FragTrap
  - Energy points (50) // ScavTrap
  - Attack damage (30) // FragTrap
*/

int main(void) {
  std::cout << "\n== TEST1 ==\n\n";
  {
    DiamondTrap diamond("diamond");
    diamond.displayInfo();

    diamond.attack("target");
    diamond.highFiveGuys();
    diamond.guardGate();
    diamond.whoAmI();
    std::cout << std::endl;
  }

  std::cout << "\n== TEST2 ==\n\n";
  {
    DiamondTrap diamond = DiamondTrap("diamond2");
    diamond.displayInfo();

    diamond.attack("target");
    diamond.highFiveGuys();
    diamond.guardGate();
    diamond.whoAmI();
  }

  std::cout << "\n== TEST3 ==\n\n";
  {
    DiamondTrap diamond3;
  }
  
  std::cout << "\n== TEST4 ==\n\n";
  {
    ClapTrap *test_clap = new DiamondTrap("dia");
    test_clap->attack("target");
    delete test_clap;
  }
  system("leaks DiamondTrap");
  return 0;
}
