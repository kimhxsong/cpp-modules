#include "Cat.h"

#include <iostream>
#include <string>

#include "Brain.h"

Cat::Cat() {
  type = "Cat";
  std::cout << "Cat Default Constructor Called\n";
  brain = new Brain();
}

Cat::~Cat() {
  delete brain;
  std::cout << "Cat Destructor Called\n";
}

Cat& Cat::operator=(const Cat& other) {
  type = other.type;
  brain = other.brain;
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow.. Meowwwooo >.<\n";
}
