#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

#include "Brain.h"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& other);

  virtual ~Dog();

  Dog& operator=(const Dog& other);
  // override
  void makeSound() const;

  Brain& getBrain() const;

 private:
  Brain *brain_;
};

#endif  // DOG_H_
