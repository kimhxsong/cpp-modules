#include <iostream>

#include "ClapTrap.h"

int main(void) {
  std::cout << "== TEST1 ==\n\n";
  // HP CASE
  {
    std::cout << "STATEMENT ClapTrap clap(\"Base\");" << '\n';
    ClapTrap clap("Base");
    clap.displayInfo();

    std::cout << "STATEMENT clap.attack(\"target_1\");" << '\n';
    clap.attack("target_1");
    clap.displayInfo();

    std::cout << "STATEMENT clap.takeDamage(3);" << '\n';
    clap.takeDamage(3);
    clap.displayInfo();

    std::cout << "STATEMENT clap.beRepaired(3);" << '\n';
    clap.beRepaired(3);
    clap.displayInfo();

    std::cout << "STATEMENT clap.takeDamage(10);" << '\n';
    clap.takeDamage(10);
    clap.displayInfo();

    std::cout << "STATEMENT clap.takeDamage(1);" << '\n';
    clap.takeDamage(1);
    clap.displayInfo();

    std::cout << "STATEMENT clap.beRepaired(10);" << '\n';
    clap.beRepaired(10);
    clap.displayInfo();

    std::cout << "STATEMENT clap.attack(\"target_2\");" << '\n';
    clap.attack("target_2");
    clap.displayInfo();
  }

  std::cout << "\n== TEST2 ==\n\n";
  // EP CASE
  {
    std::cout << "STATEMENT ClapTrap clap(\"Base\");" << '\n';
    ClapTrap clap("Base");
    clap.set_energy_point(0);
    clap.displayInfo();

    std::cout << "STATEMENT clap.beRepaired(3);" << '\n'; 
    clap.beRepaired(3);
    clap.displayInfo();

    std::cout << "STATEMENT clap.attack(\"target_1\");" << '\n';
    clap.attack("target_1");
    clap.displayInfo();

    std::cout << "STATEMENT clap.takeDamage(10);" << '\n';
    clap.takeDamage(10);
    clap.displayInfo();

    std::cout << "STATEMENT clap.beRepaired(3);" << '\n'; 
    clap.beRepaired(3);
    clap.displayInfo();

    std::cout << "STATEMENT clap.attack(\"target_1\");" << '\n';
    clap.attack("target_1");
    clap.displayInfo();
  }

  return 0;
}
