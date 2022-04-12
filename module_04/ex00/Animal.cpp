#include "Animal.h"

#include <string>
#include <iostream>

Animal::Animal() {
  std::cout << "Animal Default Constructor Called\n";
}

Animal::Animal(const Animal& other) {
  std::cout << "Animal Copy Constructor Called\n";
  *this = other;
}

Animal::Animal(const std::string& type)
  : type_(type) {
  std::cout << "Animal Parameterized Constructor Called\n";
}

Animal::~Animal() {
  std::cout << "Animal Destructor Called\n";
}

Animal& Animal::operator=(const Animal& other) {
  type_ = other.getType();
  return *this;
}

const std::string& Animal::getType() const {
  return type_;
}

void Animal::makeSound() const {
  std::cout << "Can't make sound\n";
}
