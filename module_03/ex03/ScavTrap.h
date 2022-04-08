#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include <string>

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
 public:
  explicit ScavTrap(const std::string& name);

  virtual ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& other);

  void attack(const std::string& target);
  void guardGate();

 protected:
  ScavTrap();
};

#endif  // SCAVTRAP_H_
