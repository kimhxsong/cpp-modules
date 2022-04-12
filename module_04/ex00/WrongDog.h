#ifndef WRONGDOG_H_
#define WRONGDOG_H_

#include "WrongAnimal.h"

class WrongDog : public WrongAnimal {
 public:
  WrongDog();
  WrongDog(const WrongDog& other);

  ~WrongDog();

  WrongDog& operator=(const WrongDog& other);

  void makeSound() const;
};

#endif  // WRONGDOG_H_
