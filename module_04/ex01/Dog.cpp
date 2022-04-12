#include "Dog.h"

#include <iostream>
#include <string>
#include <new>

#include "Animal.h"
#include "Brain.h"

Dog::Dog()
  : Animal("Dog") {
  std::cout << "Dog Default Constructor Called\n";
  brain_ = new Brain;
}

Dog::Dog(const Dog& other) {
  std::cout << "Dog Copy Constructor Called\n";
  brain_ = new Brain;
  *this = other;
}

Dog::~Dog() {
  std::cout << "Dog Destructor Called\n";
  delete brain_;
}

Dog& Dog::operator=(const Dog& other) {
  type_ = other.getType();
  *brain_ = other.getBrain();
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Bowwow Bowwow! =*=\n";
}

Brain& Dog::getBrain() const {
  return *brain_;
}
