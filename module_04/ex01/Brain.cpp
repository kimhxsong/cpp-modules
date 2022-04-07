#include "Brain.h"

#include <iostream>

Brain::Brain() {
  std::cout << "Brain Default Constructor Called\n";
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain Copy Constructor Called\n";
  for (size_t i = 0; i < 100; ++i) {
    ideas[i] = other.ideas[i];
  }
}

Brain::~Brain() {
  std::cout << "Brain Destructor Called\n";
}

Brain& Brain::operator=(const Brain& other) {
  for (size_t i = 0; i < 100; ++i) {
    ideas[i] = other.ideas[i];
  }
  return *this;
}
