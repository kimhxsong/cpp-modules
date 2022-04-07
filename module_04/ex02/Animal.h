#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
 public:
  Animal();
  Animal(const Animal& other);
  virtual ~Animal();
  
  Animal& operator=(const Animal& other);

  const std::string& getType() const;

  // pure virtual method
  virtual void makeSound() const = 0;

 protected:
  std::string type;
};

#endif
