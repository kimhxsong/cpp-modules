#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  Zombie();
  explicit Zombie(std::string name);
  ~Zombie();

  std::string getName();
  void setName(std::string name);

  void announce();

 private:
  std::string name_;
};

Zombie* zombieHorde(int N, std::string name);

#endif  // ZOMBIE_HPP_
