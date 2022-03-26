#include "Point.h"
#include "Fixed.h"

#include <cmath>
#include <iostream>

namespace {

Fixed calculateArea(Point const a, Point const b, Point const c) {
  Fixed area = (a.getX() * (b.getY() - c.getY()) + b.getX() *
               (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
  return (area < Fixed(0)) ? area * Fixed(-1) : area;
}

}

// BSP stands for "Binary space partioning"
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  const Fixed area_abc = calculateArea(a, b, c);
  const Fixed area_pbc = calculateArea(point, b, c);
  const Fixed area_apc = calculateArea(a, point, c);
  const Fixed area_abp = calculateArea(a, b, point);

  if (area_pbc.getRawBits() == 0 || area_apc.getRawBits() == 0 ||
      area_abp.getRawBits() == 0) {
    return false;
  }
  return area_abc == (area_pbc + area_apc + area_abp);
}
