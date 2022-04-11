#ifndef WRONGDOG_H_
#define WRONGDOG_H_

#include "Brain.h"
#include "WrongAnimal.h"

class WrongDog : public WrongAnimal {
 public:
  WrongDog();
  WrongDog(const WrongDog& other);

  ~WrongDog();

  WrongDog& operator=(const WrongDog& other);

  void makeSound() const;
  Brain& getBrain() const;

 private:
  Brain *brain_;
};

#endif  // WRONGDOG_H_
