#include "Animal.h"

#include <iostream>
#include <string>

Animal::Animal() {
  std::cout << "Animal Constructor Called\n";
}
Animal::Animal(const Animal& other) {
  type = other.type;
}

Animal::~Animal() {
  std::cout << "Animal Destructor Called\n";
}

Animal& Animal::operator=(const Animal& other) {
  type = other.type;
  return *this;
}

const std::string& Animal::getType() const{
  return type;
}

void Animal::makeSound() const {
  std::cout << "Unspecified Animal\n";
}
