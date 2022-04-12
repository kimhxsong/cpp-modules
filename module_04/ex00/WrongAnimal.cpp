#include "WrongAnimal.h"

#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal Default Constructor Called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  std::cout << "WrongAnimal Copy Constructor Called\n";
  *this = other;
}

WrongAnimal::WrongAnimal(const std::string& type)
  : type_(type) {
  std::cout << "WrongAnimal Parameterized Constructor Called\n";
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructor Called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  type_ = other.getType();
  return *this;
}

const std::string& WrongAnimal::getType() const {
  return type_;
}

void WrongAnimal::makeSound() const {
  std::cout << "Can't make sound\n";
}
