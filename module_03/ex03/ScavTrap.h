#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include <string>

#include "ClapTrap.h"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  explicit ScavTrap(const std::string& name);

  virtual ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& other);

  const std::string& get_name() const;

  void attack(const std::string& target);
  void guardGate();

 private:
  std::string name_;
};

#endif  // SCAVTRAP_H_
