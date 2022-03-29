#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

#include <string>

class ClapTrap {
 public:
  ClapTrap(const std::string& name);
  ~ClapTrap();

  unsigned int get_energy_point();
  unsigned int get_attack_damage();
  unsigned int get_hit_point();

  void set_energy_point(unsigned int energy_point);
  void set_attack_damage(unsigned int attack_damage);
  void set_hit_point(unsigned int hit_point);

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
 
 private:
  std::string name_;
  unsigned int energy_point_;
  unsigned int attack_damage_;
  unsigned int hit_point_;
};

#endif  // CLAPTRAP_H_
