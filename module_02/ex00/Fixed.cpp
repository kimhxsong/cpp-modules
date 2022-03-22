//
// Copyright 2022 Hyeonsong Kim
//
#include "Fixed.hpp"

#include <iostream>

const int Fixed::_kFractional = 8;

Fixed::Fixed()
    : raw_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::~Fixed() {
  std::cout << "Desctructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed& other) {
  std::cout << "Assignation operator called" << std::endl;
  raw_ = other.raw_;
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return raw_;
}

void  Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called" << std::endl;
  raw_ = raw;
}
