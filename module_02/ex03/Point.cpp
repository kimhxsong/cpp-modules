#include "Point.h"

#include "Fixed.h"

Point::Point()
  : x(),
    y() {}

Point::Point(const Point& other)
  : x(other.x),
    y(other.y) {}

Point::Point(const float fx, const float fy)
  : x(fx),
    y(fy) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
  *const_cast<Fixed *>(&x) = other.x;
  *const_cast<Fixed *>(&y) = other.y;
  return *this;
}
