#include "WrongDog.h"

#include <iostream>
#include <string>

#include "WrongAnimal.h"

WrongDog::WrongDog()
  : WrongAnimal("WrongDog") {
  std::cout << "WrongDog Default Constructor Called\n";
}

WrongDog::WrongDog(const WrongDog& other) {
  std::cout << "WrongDog Copy Constructor Called\n";
  *this = other;
}

WrongDog::~WrongDog() {
  std::cout << "WrongDog Destructor Called\n";
}

WrongDog& WrongDog::operator=(const WrongDog& other) {
  type_ = other.getType();
  return *this;
}

void WrongDog::makeSound() const {
  std::cout << "Bowwow Bowwow! =*=\n";
}
