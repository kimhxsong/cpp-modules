#include "WrongDog.h"

#include <iostream>
#include <string>
#include <new>

#include "Brain.h"
#include "WrongAnimal.h"

WrongDog::WrongDog()
  : WrongAnimal("WrongDog") {
  std::cout << "WrongDog Default Constructor Called\n";
  brain_ = new Brain;
}

WrongDog::WrongDog(const WrongDog& other) {
  std::cout << "WrongDog Copy Constructor Called\n";
  brain_ = new Brain;
  *this = other;
}

WrongDog::~WrongDog() {
  std::cout << "WrongDog Destructor Called\n";
  delete brain_;
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
  type_ = other.getType();
  *brain_ = other.getBrain();
  return *this;
}

void WrongDog::makeSound() const {
  std::cout << "Bowwow Bowwow! =*=\n";
}

Brain& WrongDog::getBrain() const {
  return *brain_;
}
