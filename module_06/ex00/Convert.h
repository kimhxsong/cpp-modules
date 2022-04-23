#ifndef CONVERT_H_
#define CONVERT_H_

#include <sstream>
#include <string>

class Convert {
 public:
  static bool isSign(char ch);

  enum eType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
  };

  Convert();
  Convert(const Convert& other);
  Convert(const std::string& input);
  ~Convert();

  Convert& operator=(const Convert& other);


  void print();

 private:
  int detectType();

  void execute();
  void executeFromInf();
  void executeFromNan();
  void executeFromInt(std::istringstream& iss);
  void executeFromFloat(std::istringstream& iss);
  void executeFromDouble(std::istringstream& iss);

  void printChar();
  void printInt();
  void printFloat();
  void printDouble();

  std::string input_;
  int states_[4];
  int type_;

  double d_;
  float f_;
  int i_;
  char c_;

  bool bIsNan_;
  bool bIsInf_;
};

#endif  // CONVERT_H_
