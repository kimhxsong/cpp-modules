#include "Fixed.h"

#include <iostream>

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  std::cout << std::endl;

  Fixed g;
  Fixed const e(-10);
  Fixed const f(-42.42f);
  g = Fixed(-1234.4321f);

  std::cout << "e is " << e << std::endl;
  std::cout << "f is " << f << std::endl;
  std::cout << "g is " << g << std::endl;

  std::cout << "e is " << e.toInt() << " as integer" << std::endl;
  std::cout << "f is " << f.toInt() << " as integer" << std::endl;
  std::cout << "g is " << g.toInt() << " as integer" << std::endl;

  return 0;
}
