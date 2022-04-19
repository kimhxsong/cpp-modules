#ifndef CONVERTER_H_
#define CONVERTER_H_

class Converter {
 public:
  Converter();
  Converter(const Converter& other);
  ~Converter();

  Converter& operator=(const Converter& other);

 private:
  void *detected_type_ref_;
  double dnum;
  float fnum;
  int inum;
  int expected_type_;
  int type_;
  char ch;
}

#endif  // CONVERTER_H_