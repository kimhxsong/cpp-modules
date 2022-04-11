#include "Cat.h"

#include <iostream>
#include <string>
#include <new>

#include "Animal.h"
#include "Brain.h"

Cat::Cat()
  : Animal("Cat") {
  std::cout << "Cat Default Constructor Called\n";
  brain_ = new Brain;
}

Cat::Cat(const Cat& other) {
  std::cout << "Cat Copy Constructor Called\n";
  brain_ = new Brain;
  *this = other;
}

Cat::~Cat() {
  std::cout << "Cat Destructor Called\n";
  delete brain_;
}

Cat& Cat::operator=(const Cat& other) {
  type_ = other.getType();
  *brain_ = other.getBrain();
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow Meow.. >.<\n";
}

Brain& Cat::getBrain() const {
  return *brain_;
}
