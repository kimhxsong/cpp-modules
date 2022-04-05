#include <iostream>

#include "ClapTrap.h"
#include "ScavTrap.h"

int main(void) {
  std::cout << "\n== TEST ==\n\n";
  {
    std::cout << "STATEMENT ScavTrap scav(\"SCAV\");\n";
    ScavTrap scav("SCAV");
    scav.set_energy_point(1);
    scav.displayInfo();

    std::cout << "STATEMENT scav.attack(\"target_1\");\n";
    scav.attack("target_1");
    scav.displayInfo();

    std::cout << "STATEMENT scav.beRepaired(3);\n";
    scav.beRepaired(3);
    scav.displayInfo();

    std::cout << "STATEMENT scav.attack(\"target_1\");\n";
    scav.attack("target_1");
    scav.displayInfo();

    std::cout << "STATEMENT scav.takeDamage(10);\n";
    scav.takeDamage(10);
    scav.displayInfo();

    std::cout << "STATEMENT scav.beRepaired(3);\n"; 
    scav.beRepaired(3);
    scav.displayInfo();

    std::cout << "STATEMENT scav.attack(\"target_1\");\n";
    scav.attack("target_1");
    scav.displayInfo();

    std::cout << "STATEMENT scav.guardGate();\n";
    scav.guardGate();
    scav.displayInfo();
  }

  return 0;
}
