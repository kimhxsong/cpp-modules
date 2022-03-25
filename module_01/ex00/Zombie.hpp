#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  explicit Zombie(std::string name);
  ~Zombie();

  void announce(void);

 private:
  std::string name_;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif  // ZOMBIE_HPP_
