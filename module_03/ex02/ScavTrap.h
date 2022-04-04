#ifndef SCAVTRAP_H_
#define SCAVTRAP_H_

#include <string>

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
 public:
  ScavTrap();
  explicit ScavTrap(const std::string& name);
  ~ScavTrap();

  ScavTrap& operator=(const ScavTrap& other);

  virtual unsigned int get_energy_point();
  virtual unsigned int get_attack_damage();
  virtual unsigned int get_hit_point();

  virtual void set_energy_point(unsigned int energy_point);
  virtual void set_attack_damage(unsigned int attack_damage);
  virtual void set_hit_point(unsigned int hit_point);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void guardGate();

 private:
  std::string name_;
};

#endif  // SCAVTRAP_H_
