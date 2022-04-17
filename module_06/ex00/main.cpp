#include <iostream>
#include <iomanip>
#include <sstream>

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

/*
char 문자열 길이 1
int  +-0숫자로만 이루어져있음
float +-0숫자.숫자f
double +-0숫자.숫자d
*/

// int detectType(const std::string& arg_str) {
// }

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Error: It takes only one argument.\n";
    return 1;
  }

  int type;
  std::string istr(argv[1]);

  if (istr.empty()) {
    // throw() exception;
    std::cout << "Error: The arument is empty\n";
    return -1;
  }

  if (istr.length() == 1) {
    type = TYPE_CH;
  } else {
    type = TYPE_INT;
  }
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
  iss >> std::skipws >> ch;
  std::cout << "ch: " << ch << '\n';
  type = TYPE_INT;
  while (true) {
    if (iss.eof()) break;

    switch (ch) {
      case '+':
      case '-':
        iss >> std::skipws >> ch;
        break;
      case '.':
        iss >> std::skipws >> ch;
        if (iss.eof()) {
          type = TYPE_DOUBLE;
          break;
        }
        if (ch == 'f') {
          iss >> std::skipws >> ch;
          if (iss.eof()) {
            type = TYPE_FLOAT;
            break;
          }
        }
        // fallthrough
      default:
        // throw()...
        type = -1;
        break;
    }
  }

  iss.close();
  std::cout << type << '\n';
}
