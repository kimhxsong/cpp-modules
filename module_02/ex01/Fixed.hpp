//
// Copyright 2022 Hyeonsong Kim
//
#ifndef MODULE_02_EX01_FIXED_HPP_
#define MODULE_02_EX01_FIXED_HPP_

#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  explicit Fixed(const int i);
  explicit Fixed(const float f);
  ~Fixed();

  Fixed&  operator=(const Fixed& other);

  int     getRawBits() const;
  int     getRawBits(const Fixed& other) const;
  void    setRawBits(int const raw);

  float   toFloat(void) const;
  int     toInt(void) const;

 private:
  static const int  fractional_;
  int  raw_;
};

std::ostream& operator<<(std::ostream &output, const Fixed &src);

#endif  // MODULE_02_EX01_FIXED_HPP_
