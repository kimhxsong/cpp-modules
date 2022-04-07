#ifndef CAT_H_
#define CAT_H_

#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
 public:
  Cat();

  virtual ~Cat();

  Cat& operator=(const Cat& other);

  void makeSound() const;

 private:
  Brain* brain;
};

#endif  // CAT_H_