#ifndef CLAPTRAP_H_
#define CLAPTRAP_H_

#include <string>

class ClapTrap {
 public:
  ClapTrap();
  explicit ClapTrap(const std::string& name);

  virtual ~ClapTrap();

  ClapTrap& operator=(const ClapTrap& other);

  virtual const std::string& get_name() const ;
  unsigned int get_energy_point() const ;
  unsigned int get_attack_damage() const ;
  unsigned int get_hit_point() const ;

  void set_energy_point(unsigned int energy_point);
  void set_attack_damage(unsigned int attack_damage);
  void set_hit_point(unsigned int hit_point);

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  bool isTrapBroken();
  bool hasNoEnergy();
  void displayInfo();

 protected:
  unsigned int energy_point_;
  unsigned int attack_damage_;
  unsigned int hit_point_;

 private:
  std::string name_;
};

#endif  // CLAPTRAP_H_
