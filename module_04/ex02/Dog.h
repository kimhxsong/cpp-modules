#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
 public:
  Dog();

  virtual ~Dog();

  Dog& operator=(const Dog& other);

  void makeSound() const;

 private:
  Brain* brain;
};

#endif  // DOG_H_