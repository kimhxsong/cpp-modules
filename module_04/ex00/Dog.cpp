#include "Dog.h"

#include <iostream>
#include <string>

#include "Animal.h"

Dog::Dog()
  : Animal("Dog") {
  std::cout << "Dog Default Constructor Called\n";
}

Dog::Dog(const Dog& other) {
  std::cout << "Dog Copy Constructor Called\n";
  *this = other;
}

Dog::~Dog() {
  std::cout << "Dog Destructor Called\n";
}

Dog& Dog::operator=(const Dog& other) {
  type_ = other.getType();
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Bowwow Bowwow! =*=\n";
}
