#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include "Converter.h"

enum eType {
  TYPE_CHAR,
  TYPE_INT,
  TYPE_FLOAT,
  TYPE_DOUBLE,
  TYPE_INVALID
};

int detectType(const std::string& str) {
  std::istringstream iss(str);
  int type;
  bool bDotFound = false;
  char ch;

  while (true) {
    iss >> std::skipws >> ch;
    if (ch == '+' || ch == '-') {
      iss >> ch;
    }
    std::cout << iss.str() << '\n';
    if (iss.str() == "nan" || iss.str() == "nanf") {
      std::cout << "nan\n";
      return 0;
    }

    if (iss.str() == "inf" || iss.str() == "inff") {
      std::cout << "inf\n";
      return 0;
    }
    break;
  }
  return 0;
}

// int detectType(const std::string& str) {
//   std::istringstream iss(str);
//   int type;
//   bool bDotFound = false;
//   char ch;

//   type = TYPE_INT;
//   while (true) {
//     iss >> std::skipws >> ch;
//     if (iss.eof()) break;

//     switch (ch) {
//       case '.':
//         bDotFound = true;
//         type = TYPE_DOUBLE;
//         break;
//       case 'f':
//         if (bDotFound == true) {
//           type = TYPE_FLOAT;
//           break;
//         }
//         // Intentional fall-through
//       default:
//         type = TYPE_INVALID;
//         break;
//       }
//   }
//   return type;
// }

int main(int argc, char *argv[]) {
  // if (isValidArgument(argc, argv) == false) {
  //     std::cout << ""
  // }

  // std::cout << <<'\n';
  double d;
  std::istringstream iss2(argv[1]);

  iss2 >> d;
  std::cout << "d: " << d <<  '\n';
  std::cout << iss2.good() << iss2.eof() << iss2.fail() << iss2.bad() << '\n';


  if (argc != 2) {
    std::cout << "Error: It takes only one argument\n";
    return 1;
  }

  std::string istr(argv[1]);
  if (istr.length() == 0) {
    std::cout << "Error: The argument is empty\n";
  }

  if (istr.length() == 1) {
    if (std::isprint(istr[0]) == true) {
      std::cout << "char\n";
      return 0;
    } else {
      std::cout << "Error: Non displayable characters shouldn’t be used as inputs\n";
      return 1;
    }
  }
  std::cout << "'" << istr << "'" << '\n';

  int type = detectType(istr);
  std::cout << "type: " << type << '\n';

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
  std::cout << "'" << istr << "'" << '\n';



  std::istringstream iss(istr);
  char ch;


  iss >> ch;

  if (ch == '+' || ch == '-') {
      iss >> std::skipws >> ch;
  }

  if (iss.eof()) {
    std::cout << "int\n";
    return 0;
  }

  if (ch == '.') {
    iss >> std::skipws >> ch;
    if (iss.eof()) {
      std::cout << "double\n";
      return 0;
    }
  } else {
    std::cout << "Error: Invalid Literal\n";
    return 1;
  }

  if (ch == 'f') {
    iss >> std::skipws >> ch;
  }

  if (iss.eof()) {
    std::cout << "float\n";
    return 0;
  } else {
    std::cout << "Error: Invalid Literal\n";
    return 1;
  }


  return 0;
}
