#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
public:
  Fixed();
  Fixed(Fixed const & src);
  ~Fixed();

  int     getRawBits() const;
  int     getRawBits(Fixed const & rhs) const;
  void    setRawBits(int const raw); 
  Fixed&  operator=(Fixed const & rhs);

  static int const _kFractional;

private:
  int               _raw;
};

#endif