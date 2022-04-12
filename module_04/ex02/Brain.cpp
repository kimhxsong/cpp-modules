#include "Brain.h"

#include <iostream>

Brain::Brain()
  : ideas_() {
  std::cout << "Brain Default Constructor Called\n";
}

Brain::Brain(const Brain& other)
  : ideas_() {
  std::cout << "Brain Copy Constructor Called\n";
  *this = other;
}

Brain::~Brain() {
  std::cout << "Brain Destructor Called\n";
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "Brain Copy Operator Called\n";

  for (size_t index = 0; index < 100; ++index) {
    ideas_[index] = other.getIdea(index);
  }

  return *this;
}

const std::string& Brain::getIdea(const size_t index) const {
  return ideas_[index];
}

