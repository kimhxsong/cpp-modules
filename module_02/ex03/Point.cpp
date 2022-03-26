#include "Point.h"

#include "Fixed.h"

Point::Point()
  : x(),
    y() {}

Point::Point(const Point& other)
  : x(other.x),
    y(other.y) {}

Point::Point(const Fixed& other_x, const Fixed& other_y)
  : x(other_x),
    y(other_y) {}

Point::Point(const float fx, const float fy)
  : x(fx),
    y(fy) {}

Point::~Point() {}

Point& Point::operator=(const Point& other) {
  *const_cast<Fixed *>(&x) = other.x;
  *const_cast<Fixed *>(&y) = other.y;
  return *this;
}

const Point Point::operator+(const Point &other) const {
  return Point(x + other.x, y + other.y);
}

const Point Point::operator-(const Point& other) const {
  return Point(x - other.x, y - other.y);
}

const Fixed& Point::getX() const {
  return x;
}

const Fixed& Point::getY() const {
  return y;
}
