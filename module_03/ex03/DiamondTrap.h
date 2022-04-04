#ifndef DIAMONDTRAP_H_
#define DIAMONDTRAP_H_

#include <string>

#include "ClapTrap.h"
#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap
  : public ScavTrap,
    public FragTrap {
 public:
  DiamondTrap();
  explicit DiamondTrap(const std::string& name);
  ~DiamondTrap();

  // void attack(const std::string& target);
  // void takeDamage(unsigned int amount);
  // void beRepaired(unsigned int amount);

  void whoAmI();

 private:
  std::string name_;
};

#endif  // DIAMONDTRAP_H_
