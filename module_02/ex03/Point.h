#ifndef POINT_H_
#define POINT_H_

#include "Fixed.h"

class Point {
 public:
  Point();
  Point(const Point& other);
  Point(const Fixed& other_x, const Fixed& other_y);
  Point(const float fx, const float fy);

  ~Point();

  Point& operator=(const Point& other);

  const Point operator+(const Point& other) const;
  const Point operator-(const Point& other) const;

  const Fixed& getX() const;
  const Fixed& getY() const;

 private:
  const Fixed x;
  const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // POINT_H_
