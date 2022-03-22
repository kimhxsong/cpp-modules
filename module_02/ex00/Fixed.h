#ifndef FIXED_H_
#define FIXED_H_

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed& other);

  ~Fixed();

  Fixed& operator=(const Fixed& other);

  int getRawBits() const;
  void setRawBits(int const raw);

 private:
  static const int kFractional_;
  int raw_;
};

#endif  // FIXED_H_
