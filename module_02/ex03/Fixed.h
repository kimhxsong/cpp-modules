#ifndef FIXED_H_
#define FIXED_H_

#include <ostream>

class Fixed {
 public:
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);

  Fixed();
  Fixed(const Fixed& other);

  explicit Fixed(const int i);
  explicit Fixed(const float f);

  ~Fixed();

  Fixed& operator=(const Fixed& other);

  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  bool operator<(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator>(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;

  const Fixed operator+(const Fixed& other) const;
  const Fixed operator-(const Fixed& other) const;

  const Fixed operator*(const Fixed& other) const;
  const Fixed operator/(const Fixed& other) const;

  Fixed operator++(int);
  Fixed operator--(int);

  Fixed& operator++();
  Fixed& operator--();

  int getRawBits() const;

  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

 private:
  static const int kFractional_ = 8;
  int raw_;
};

std::ostream& operator<<(std::ostream &output, const Fixed &rhs);

#endif  // FIXED_H_
