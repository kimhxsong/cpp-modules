#include <iostream>

#include "Fixed.h"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << b.toInt() << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << (Fixed(0.5f) / Fixed(0.1f)) << std::endl;

  return 0;
}
