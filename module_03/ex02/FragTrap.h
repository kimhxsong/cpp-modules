#ifndef FRAGTRAP_H_
#define FRAGTRAP_H_

#include <string>

#include "ClapTrap.h"

class FragTrap : public ClapTrap {
 public:
  explicit FragTrap(const std::string& name);
  
  virtual ~FragTrap();

  FragTrap& operator=(const FragTrap& other);

  void highFiveGuys(void);

 protected:
  FragTrap();
};

#endif  // FRAGTRAP_H_
