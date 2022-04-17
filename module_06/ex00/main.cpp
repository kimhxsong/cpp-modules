#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>

// -inff, +inff, -inf, +inf, nan(not a number)
// Non displayable, imposible 이런 문제들. 나는 적절한 유형인지만 평가하면됨.
/*
int impossible .
int 
*/
//   std::cout << std::setprecision(16); 기본 정밀도는 6
// class Convert {
//  public:
//   enum eTypeLiteral {
//     TYPE_LITERAL_CHAR,
//     TYPE_LITERAL_INT,
//     TYPE_LITERAL_FLOAT,
//     TYPE_LITERAL_DOUBLE
//   };

//   Converter();
//   Converter(const Converter& other);

//   ~Converter();

//   void detectType();
//   void execute()

//   operator=(const Converter& other);

//  private:
//   double dnum_;
//   float fnum_;
//   int inum_;
//   int type;
//   char  ch_;
// };

// int Converter::detectType(const std::string &input) {
//   if (input.size() <= 1) {
//     return TYPE_LITERAL_CHAR;
//   }

//   return 0;
// } // float는 끝까지 읽음.
// 
enum etype {
  TYPE_CH = 1,
  TYPE_INT = 2,
  TYPE_DOUBLE = 4,
  TYPE_FLOAT = 8,
  TYPE_INF,
  TYPE_NAN
};

void validateArg(int argc, char *argv[]) {
  if (argc == 2 || std::strlen(argv[1]) != 0) {
    return;
  }
  throw std::strerror(EINVAL);
}

int main(int argc, char* argv[]) {

  int type;
  std::string istr(argv[1]);

  try {
    validateArg(argc, argv);
  } catch (const std::string &s) {
    std::cout << "validateArg(): " << s << '\n';
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

  while (true)
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
  return TYPE;


  unsigned char marked = 00000;
  std::cout << "ch: " << ch << '\n';
  while (true) {
    if (ch == '.' || !(iss >> std::skipws >> ch) && iss.eof()) break;

    switch (ch) {
      case '+':
      case '-':
        if (marked & 01000) return (-1);
        marked |= 01000;
        break;
      case '.':
        break;
      default:
        // throw() exception;
        break;
    }
  }

  if (iss.eof()) {
    return type;
  }

  if (ch == 'f') {
    iss >> std::skipws >> ch;
    if (iss.eof()) {
      type = TYPE_FLOAT;

    } 
  }
  std::cout << type << '\n';
}
