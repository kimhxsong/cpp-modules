#include "Convert.h"

#include <cstdint>

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>


bool bDotFound = false;
bool bFFound = false;

bool Convert::isSign(char ch) {
  return (ch == '+' || ch == '-');
}

int Convert::detectType(const std::string& str) {
  size_t idx = 0;
  size_t found_dot;
  size_t found_f;

  idx += (str.length() != 1) && isSign(str[i]);

  // if (str.find("nan", idx) != std::
  if ((found_dot = str.find('.', idx)) != bDotFound) {
    bDotFound = true;
  }
  found_f = str.find('f', found_dot);
  if (bDotFound == true && found_f != std::string::npos) {
    if (found_f != (str.length() - 1)) {
      return -1; // wrong format
    }
    bFFound = true;
  }

  if (bDotFound == true) {
    for (size_t start = idx; i < found_dot; ++start) {
      if (std::isdigit(str[start]) == false) {
        return -1; // wrong format
      }
    }
  }

  if (bFFound == true) {
    for (size_t start = found_dot + 1; start < found_f; ++start) {
      if (std::isdigit(str[start]) == false) {
        return -1;
      }
    }
    str.erase(found_f, 1);
  }
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