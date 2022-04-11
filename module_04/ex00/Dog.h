#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);

  virtual ~Dog();

  Dog& operator=(const Dog& other);
  // override
  void makeSound() const;
};

#endif  // DOG_H_
