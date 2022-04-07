#include "Dog.h"

#include <iostream>
#include <string>

#include "Brain.h"

Dog::Dog() {
  type = "Dog";
  std::cout << "Dog Constructor Called\n";
  brain = new Brain();
}

Dog::~Dog() {
  delete brain;
  std::cout << "Dog Destructor Called\n";
}

Dog& Dog::operator=(const Dog& other) {
  type = other.type;
  brain = other.brain;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Bark Barkkk! ^&^\n";
}
