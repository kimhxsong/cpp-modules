#ifndef POINT_H_
#define POINT_H_

#include "Fixed.h"

class Point {
 public:
  Point();
  Point(const Point& other);
  Point(const float fx, const float fy);

  ~Point();

  Point& operator=(const Point& other);

 private:
  const Fixed x;
  const Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // POINT_H_
