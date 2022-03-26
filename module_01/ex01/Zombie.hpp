#ifndef ZOMBIE_HPP_
# define ZOMBIE_HPP_

#include <string>

class Zombie {
 public:
  Zombie();
  explicit Zombie(const std::string& name);
  ~Zombie();

  std::string getName();
  void setName(const std::string& name);

  void announce();

 private:
  const std::string& name_;
};

Zombie* zombieHorde(int N, const std::string& name);

#endif  // ZOMBIE_HPP_
