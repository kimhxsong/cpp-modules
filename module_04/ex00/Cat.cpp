#include "Cat.h"

#include <iostream>
#include <string>

Cat::Cat() {
  type = "Cat";
  std::cout << "Cat Constructor Called\n";
}

Cat::~Cat() {
  std::cout << "Cat Destructor Called\n";
}

Cat& Cat::operator=(const Cat& other) {
  type = other.type;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow.. Meowwwooo >.<\n";
}
