#include "Cat.h"

#include <iostream>
#include <string>

#include "Animal.h"

Cat::Cat()
  : Animal("Cat") {
  std::cout << "Cat Default Constructor Called\n";
}

Cat::Cat(const Cat& other) {
  std::cout << "Cat Copy Constructor Called\n";
  *this = other;
}

Cat::~Cat() {
  std::cout << "Cat Destructor Called\n";
}

Cat& Cat::operator=(const Cat& other) {
  type_ = other.getType();
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow Meow.. >.<\n";
}
