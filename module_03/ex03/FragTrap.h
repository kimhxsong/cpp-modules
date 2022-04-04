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

  virtual void attack(const std::string& target);
  virtual void takeDamage(unsigned int amount);
  virtual void beRepaired(unsigned int amount);

  void highFiveGuys(void);

 private:
  std::string name_;
};

#endif  // FRAGTRAP_H_
