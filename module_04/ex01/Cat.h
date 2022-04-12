#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"

#include "Brain.h"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& other);

  virtual ~Cat();

  Cat& operator=(const Cat& other);
  // override
  void makeSound() const;

  Brain& getBrain() const;

 private:
  Brain *brain_;
};

#endif  // CAT_H_
