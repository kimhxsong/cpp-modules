#ifndef HUMANB_HPP_
# define HUMANB_HPP_

#include <string>

#include "Weapon.hpp"

class HumanB {
 public:
  explicit HumanB(const std::string& name);
  ~HumanB();

  void setWeapon(Weapon &weapon);
  void attack();

 private:
  const std::string& name_;
  Weapon* weapon_;
};

#endif  // HUMANB_HPP_
