#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include <string>

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  explicit ScavTrap(const std::string& name);
  ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& other);

  // virtual void attack(const std::string& target);
  // virtual void takeDamage(unsigned int amount);
  // virtual void beRepaired(unsigned int amount);

  void guardGate();

 private:
  std::string name_;
};

#endif  // SCAVTRAP_H_
