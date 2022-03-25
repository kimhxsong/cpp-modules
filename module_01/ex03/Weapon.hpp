#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include <string>

class Weapon {
 public:
  explicit Weapon(std::string type);
  ~Weapon();

  const std::string& getType();
  void setType(std::string type);

 private:
  std::string type_;
};

#endif  // WEAPON_HPP_
