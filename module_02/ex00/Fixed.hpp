//
// Copyright 2022 Hyeonsong Kim
//
#ifndef MODULE_02_EX00_FIXED_HPP_
#define MODULE_02_EX00_FIXED_HPP_

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  ~Fixed();

  Fixed&  operator=(const Fixed& other);

  int     getRawBits() const;
  void    setRawBits(int const raw);

 private:
  static const int  fractional_;
  int               raw_;
};

#endif  // MODULE_02_EX00_FIXED_HPP_
