//
// Copyright 2022 Hyeonsong Kim
//
#include "Fixed.hpp"
#include <ostream>
#include <iostream>
#include <cmath>

const int Fixed::fractional_ = 8;

Fixed::Fixed()
    : raw_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::Fixed(const int i) {
  std::cout << "parameterized constructor called" << std::endl;
  raw_ = i << fractional_;
}

Fixed::Fixed(const float f) {
  std::cout << "parameterized constructor called" << std::endl;
  raw_ = roundf(f * (0b1 << fractional_));
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

float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (0b1 << fractional_);
}

int Fixed::toInt(void) const {
  return toFloat();
}

std::ostream& operator<<(std::ostream &output, const Fixed& src) {
  output << src.toFloat();
  return output;
}
