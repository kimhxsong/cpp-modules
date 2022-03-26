#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  explicit Zombie(const std::string& name);
  ~Zombie();

  void announce(void);

 private:
  const std::string& name_;
};

Zombie* newZombie(const std::string& name);
void randomChump(const std::string& name);

#endif  // ZOMBIE_HPP_
