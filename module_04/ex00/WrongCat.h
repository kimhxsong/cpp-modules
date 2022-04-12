#ifndef WRONGCAT_H_
#define WRONGCAT_H_

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& other);

  ~WrongCat();

  WrongCat& operator=(const WrongCat& other);

  void makeSound() const;
};

#endif  // WRONGCAT_H_
