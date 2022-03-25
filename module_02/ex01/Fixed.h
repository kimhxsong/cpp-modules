#ifndef FIXED_H_
#define FIXED_H_

#include <ostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);
  explicit Fixed(const int i);
  explicit Fixed(const float f);

  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits() const;

  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  static const int  kFractional_;
  int  raw_;
};

std::ostream& operator<<(std::ostream &output, const Fixed &src);

#endif  // FIXED_H_
