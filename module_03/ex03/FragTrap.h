#ifndef FRAGTRAP_H_
#define FRAGTRAP_H_

#include <string>

#include "ClapTrap.h"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  explicit FragTrap(const std::string& name);
  ~FragTrap();

  FragTrap& operator=(const FragTrap& other);

  const std::string& get_name() const;

  void highFiveGuys(void);

 private:
  std::string name_;
};

#endif  // FRAGTRAP_H_
