#include "Dog.h"

#include <iostream>
#include <string>

Dog::Dog() {
  type = "Dog";
  std::cout << "Dog Constructor Called\n";
}

Dog::~Dog() {
  std::cout << "Dog Destructor Called\n";
}

Dog& Dog::operator=(const Dog& other) {
  type = other.type;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Bark Barkkk! ^&^\n";
}
