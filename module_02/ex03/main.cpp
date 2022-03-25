#include <iostream>

#include "Fixed.h"
#include "Point.h"

int main() {
  const int x_min = 0;
  const int y_min = 0;
  const int x_max = 25;
  const int y_max = 25;

  Point a((Fixed(x_min)), Fixed(y_min));
  Point b((Fixed(x_max / 2)), Fixed(y_max));
  Point c((Fixed(x_max)), Fixed(y_min));

  Point point1(Fixed(5), Fixed(-1));
  Point point2(Fixed(5), Fixed(0));
  Point point3(Fixed(5), Fixed(0.1f));
  Point point4(Fixed(5), Fixed(2.5f));
  Point point5(Fixed(5), Fixed(5));
  Point point6(Fixed(5), Fixed(5.1f));

  std::cout << bsp(a, b, c, point1) << std::endl;
  std::cout << bsp(a, b, c, point2) << std::endl;
  std::cout << bsp(a, b, c, point3) << std::endl;
  std::cout << bsp(a, b, c, point4) << std::endl;
  std::cout << bsp(a, b, c, point5) << std::endl;
  std::cout << bsp(a, b, c, point6) << std::endl;

  for (int y = y_max; y > y_min; y--) {
    for (int x = x_min; x < x_max; x++) {
      Point point((Fixed(x)), (Fixed(y)));
      if (bsp(a, b, c, point)) {
        std::cout << "@@";
      } else {
        std::cout << "^^";
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
