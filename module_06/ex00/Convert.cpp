#include "Convert.h"

#include <cstdint>

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>

int Convert::detectType(const char* str) {
  int type;
  if (std::strlen(str) == 1) {
    if (std::isprint(*str) == true) {
      return TYPE_CHAR;
    } else {
      std::cout << "Error: Non displayable character shouldn't be used as inputs\n";
      return -1;
    }
  }
  bool bDotFound = false;

  std::stringstream sstrm(str);
  std::string trimmed_str;

  sstrm >> trimmed_str;
  char ch;
  sstrm >> ch;
  if (sstrm.eof() == false) {
    std::cout << "Error: Invalid Argument\n";
    return -1; 
  }

  if (trimmed_str.find('.', 0) != std::string::npos) {
    bDotFound = true;
  }

  bool bSuffixFound;
  if (trimmed_str[trimmed_str.length() - 1] == 'f') {
    if (bDotFound == false) {
      return -1;
    }
    trimmed_str.erase(trimmed_str.length() - 1, 1);
    bSuffixFound = true;
  }

  sstrm.clear();
  sstrm.str(trimmed_str);
  double dnum;
  sstrm >> dnum;
  if (!sstrm || sstrm.eof() == false) {
    sstrm >> ch;
    return -1;
  }

  if (bSuffixFound == true) {
    return TYPE_FLOAT;
  }

  if (bDotFound == true) {
    return TYPE_DOUBLE;
  }

  return TYPE_INT;
}

void executeFromChar(char ch) {
  int i = static_cast<char>(i);
  double d = static_cast<double>(i);
  float f = static_cast<float>(i);
  std::cout << "char: '" << ch << "'\n";
  std::cout << "int: " << i << '\n';
  std::cout << "float: " << f << "f\n";
  std::cout << "double: " << d << '\n';
}

void executeFromInt(int i) {
  double d;
  float f;
  char c;

  c = static_cast<char>(i);
  d = static_cast<double>(i);
  f = static_cast<float>(i);
  std::cout.flags(std::ios_base::showpoint | std::ios_base::fixed);
  {
    if (std::isprint(c)) {
      std::cout << "char: " << c << '\n';
    } else {
      std::cout << "char: " << "Non displayable\n";
    }
  }
  std::cout << "int: " << i << '\n';
  std::cout << std::setprecision(1) << "float: " << f << "f\n";
  std::cout << std::setprecision(1) << "double: " << d << '\n';
}

void executeFromFloat(float f) {

}

void executeFromDouble(double d) {

}

void Convert::execute(int type, const std::string& str) {
  double d;
  float f;
  int i;
  char c;

  std::istringstream iss(str);
  switch (type) {
    case TYPE_CHAR:
      iss >> c;
      executeFromChar(c);
      break;
    case TYPE_INT:
      iss >> i;
      if (iss.fail() == true && (i == std::numeric_limits<int>::min() ||
                                 i == std::numeric_limits<int>::max())) {
        std::cout << "Error: Overflow\n";
        return;
      }
      executeFromInt(i);
      break;
    case TYPE_FLOAT:
      iss >> f;
      executeFromFloat(f);
      break;
    case TYPE_DOUBLE:
      iss >> d;
      executeFromDouble(d);
      break;
    default:
      break;
  }
}