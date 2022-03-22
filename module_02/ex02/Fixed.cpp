#include "Fixed.h"

#include <cmath>
#include <ostream>

Fixed&  Fixed::max(Fixed& a, Fixed& b) {
  return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  return (a > b) ? a : b;
}

Fixed&  Fixed::min(Fixed& a, Fixed& b) {
  return (a < b) ? a : b;
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b) {
  return (a < b) ? a : b;
}

Fixed::Fixed()
  : raw_(0) {}

Fixed::Fixed(const Fixed& other) {
  raw_ = other.raw_;
}

Fixed::Fixed(const int i) {
  raw_ = (i << kFractional_);
}

Fixed::Fixed(const float f) {
  raw_ = static_cast<int>(roundf(f * (0b1 << kFractional_)));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
  raw_ = other.raw_;
  return *this;
}

bool Fixed::operator==(const Fixed& other) const {
  return raw_ == other.raw_;
}

bool Fixed::operator!=(const Fixed& other) const {
  return raw_ != other.raw_;
}

bool Fixed::operator<(const Fixed& other) const {
  return raw_ < other.raw_;
}

bool Fixed::operator<=(const Fixed& other) const {
  return raw_ <= other.raw_;
}

bool Fixed::operator>(const Fixed& other) const {
  return raw_ > other.raw_;
}

bool Fixed::operator>=(const Fixed& other) const {
  return raw_ >= other.raw_;
}

Fixed Fixed::operator+(const Fixed& other) {
  Fixed result(*this);
  result.raw_ += other.raw_;
  return result;
}

Fixed Fixed::operator-(const Fixed& other) {
  Fixed result(*this);
  result.raw_ -= other.raw_;
  return result;
}

Fixed Fixed::operator*(const Fixed& other) {
  Fixed result(*this);
  result.raw_ = (raw_ * other.raw_) >> kFractional_;
  return result;
}

Fixed Fixed::operator/(const Fixed& other) {
  Fixed result(*this);
  result.raw_ = (raw_ * (0b1 << kFractional_)) / other.raw_;
  return result;
}

Fixed Fixed::operator++(int) {
  Fixed result(*this);
  raw_ += 1;
  return result;
}

Fixed Fixed::operator--(int) {
  Fixed result(*this);
  raw_ -= 1;
  return result;
}

Fixed& Fixed::operator++() {
  raw_ += 1;
  return *this;
}

Fixed& Fixed::operator--() {
  raw_ -= 1;
  return *this;
}

int Fixed::getRawBits() const {
  return raw_;
}

void Fixed::setRawBits(const int raw) {
  raw_ = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(getRawBits()) / (0b1 << kFractional_);
}

int Fixed::toInt(void) const {
  return (getRawBits() + (0b1 << (kFractional_ - 1))) >> kFractional_;
}

std::ostream& operator<<(std::ostream &output, const Fixed& rhs) {
  return output << rhs.toFloat();
}
