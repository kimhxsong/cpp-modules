#include "WrongCat.h"

#include <iostream>
#include <string>

#include "WrongAnimal.h"

WrongCat::WrongCat()
  : WrongAnimal("WrongCat") {
  std::cout << "WrongCat Default Constructor Called\n";
}

WrongCat::WrongCat(const WrongCat& other) {
  std::cout << "WrongCat Copy Constructor Called\n";
  *this = other;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor Called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  type_ = other.getType();
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "Meow Meow.. >.<\n";
}
