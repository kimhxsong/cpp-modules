#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include <string>

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  explicit ScavTrap(const std::string& name);

  virtual ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& other);

  void attack(const std::string& target);
  void guardGate();
};

#endif  // SCAVTRAP_H_
