#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include <string>

#include "Weapon.hpp"

class HumanA {
 public:
  HumanA(const std::string &name, Weapon &weapon);
  ~HumanA();

  void setWeapon(Weapon &weapon);
  void attack();

 private:
  const std::string& name_;
  Weapon &weapon_;
};

#endif  // HUMANA_HPP_
