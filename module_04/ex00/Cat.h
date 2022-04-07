#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"

class Cat : public Animal {
 public:
  Cat();
  virtual ~Cat();

  Cat& operator=(const Cat& other);

  void makeSound() const;
};

#endif  // CAT_H_