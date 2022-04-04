#ifndef FRAGTRAP_H_
#define FRAGTRAP_H_

#include <string>

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
 public:
  FragTrap();
  explicit FragTrap(const std::string& name);
  ~FragTrap();

  FragTrap& operator=(const FragTrap& other);

  virtual const std::string& get_name();
  virtual unsigned int get_energy_point();
  virtual unsigned int get_attack_damage();
  virtual unsigned int get_hit_point();

  virtual void set_energy_point(unsigned int energy_point);
  virtual void set_attack_damage(unsigned int attack_damage);
  virtual void set_hit_point(unsigned int hit_point);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void highFiveGuys(void);

 private:
  std::string name_;
};

#endif  // FRAGTRAP_H_
