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

  virtual ~DiamondTrap();

  DiamondTrap& operator=(const DiamondTrap& other);

  const std::string& get_name() const;
  void attack(const std::string& target);

  void whoAmI();

 private:
  std::string name_;
};

#endif  // DIAMONDTRAP_H_
