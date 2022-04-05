#include <iostream>

#include "ClapTrap.h"
#include "FragTrap.h"
#include "FragTrap.h"

int main(void) {
  std::cout << "\n== TEST ==\n\n";
  {
    std::cout << "STATEMENT FragTrap frag(\"FRAG\");\n";
    FragTrap frag("FRAG");
    frag.set_energy_point(1);
    frag.displayInfo();

    std::cout << "STATEMENT frag.attack(\"target_1\");\n";
    frag.attack("target_1");
    frag.displayInfo();

    std::cout << "STATEMENT frag.beRepaired(3);\n";
    frag.beRepaired(3);
    frag.displayInfo();

    std::cout << "STATEMENT frag.attack(\"target_1\");\n";
    frag.attack("target_1");
    frag.displayInfo();

    std::cout << "STATEMENT frag.takeDamage(10);\n";
    frag.takeDamage(10);
    frag.displayInfo();

    std::cout << "STATEMENT frag.beRepaired(3);\n"; 
    frag.beRepaired(3);
    frag.displayInfo();

    std::cout << "STATEMENT frag.attack(\"target_1\");\n";
    frag.attack("target_1");
    frag.displayInfo();

    std::cout << "STATEMENT frag.highFiveGuys();\n";
    frag.highFiveGuys();
    frag.displayInfo();
  }
  return 0;
}
