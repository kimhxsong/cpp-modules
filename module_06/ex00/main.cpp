#include <iostream>
#include <limits.h>

#include "Converter.h"


  try {
    validateArg(argc, argv);
  } catch (const std::string &s) {
    std::cout << "Error: " << s << '\n';
  }

  try {
    if (istr.length() == 1) {
      if (std::isprint(istr[i]) == true) {
        return TYPE_CH;
      }
      throw "invalid char literal";
    }
  } catch {
    std::cout 
  }
    // throw exception()
  std::cout << type << '\n';
  
  // replaceDigitWithSpace
  size_t  found;
  if ((found = istr.find("nan", 0)) != std::string::npos) {
    for (size_t i = found; i < found + 3; ++i) {
      istr[i] = ' ';
    }
    istr[found] = '.';
  }

  if ((found = istr.find("inf", 0)) != std::string::npos) {
    for (size_t i = found; i < found + 3; ++i) {
      istr[i] = ' ';
    }
    istr[found] = '.';
  }

  for (size_t i = istr.length(); i-- > 0;) {
    if (std::isdigit(istr[i]) || !std::isprint(istr[i])) {
      istr[i] = ' ';
    }
  }
  sizeof(int);

  std::cout << "istr: " << istr << '\n';
  std::istringstream iss(istr);
  char ch;

  // detectLiteralType()


  // if (iss.eof()) {
  //   return TYPE_INT;
  // }

  // if (ch == '.') {
  //   iss >> std::skipws >> ch;
  //   if (iss.eof()) {
  //     return TYPE_DOUBLE;
  // }
  // }

  // if (ch == 'f') {
  //   iss >> std::skipws >> ch;
  //   if (iss.eof()) {
  //     return TYPE_FLOAT;
  //   }
  } 

  char ch;
  bool bDotFound = false;
  
  type = TYPE_INT;
  iss >> std::skipws >> ch;

  if (ch == '+' || ch == '-') {
      iss >> std::skipws >> ch;
  }

  while (true) {
    iss >> std::skipws >> ch;
    if (iss.eof()) break;

    switch (ch) {
      case '.':
        bDotFound = true;
        type = TYPE_DOUBLE;
        break;
      case 'f':
        if (bDotFound == true) {
          type = TYPE_FLOAT;
          break;
        }
        // Intentional fall-through
      default:
        // throw() exception;
        break;
    }
  }
  SC_OPEN_MAX_
  return TYPE;

int main(int argc, char *argv[]) {
  if (isValidArgument(argc, argv) == false) {
      std::cout << "print"
  }


  return 0;
}
