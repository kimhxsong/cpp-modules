#ifndef BRAIN_H_
#define BRAIN_H_

#include <string>

class Brain {
 public:
  Brain();
  Brain(const Brain& other);

  ~Brain();

  Brain& operator=(const Brain& other);

  const std::string& getIdea(const size_t index) const;
  
 private:
  std::string ideas_[100];
};

#endif  // BRAIN_H_
