#ifndef BRAIN_H_
#define BRAIN_H_

#include <string>

class Brain {
 public:
  Brain();
  Brain(const Brain& other);

  ~Brain();

  Brain& operator=(const Brain& other);

 private:
  std::string ideas[100];
};

#endif  // BRAIN_H_
