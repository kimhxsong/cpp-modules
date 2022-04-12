#include "WrongCat.h"

#include <iostream>
#include <string>
#include <new>

#include "Brain.h"
#include "WrongAnimal.h"

WrongCat::WrongCat()
  : WrongAnimal("WrongCat") {
  std::cout << "WrongCat Default Constructor Called\n";
  brain_ = new Brain;
}

WrongCat::WrongCat(const WrongCat& other) {
  std::cout << "WrongCat Copy Constructor Called\n";
  brain_ = new Brain;
  *this = other;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor Called\n";
  delete brain_;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  type_ = other.getType();
  *brain_ = other.getBrain();
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "Meow Meow.. >.<\n";
}

Brain& WrongCat::getBrain() const {
  return *brain_;
}
