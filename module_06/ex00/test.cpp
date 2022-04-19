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
  try {
    if (converter::isValidArgument(argc, argv) == -1)
      throw();

    Converter converter(argv[1]);
    // converter.getExpectedType()
    converter.execute(); // 상태관리.
    {
      type = castFromType(type); //성공함. 예외 안던짐.
      void *detected_type = 

    caseFromType()
    {
      switch (type) {
        case 0:
          iss >> ch:
          detected_type = &ch;
        case 1: // overflow
          iss >> inum:
          if (!iss) {
            return;
          }
          detected_type = &inum;
        case 2: // inf, nan
          iss >> dnum:
          if (!iss) {
            return;
          }
          detected_type = &dnum;
        case 3: // inff, nan
          iss >> fnum:
          if (!iss) {
            return;
          }
          detected_type = &fnum;
        default:
          break;
      }
      if (!iss.eof()) {
        throw()
      }
      if (iss.fail()) {
        //maybe overflow
      }
      return TYPE;
    }
      // 인덱스. 함수 포인터 현재 인덱스 기억했다가 초기화하고 %루프로 돌면서 처리.
      if (type == NAN) {

      } else if (type == INF) {

      }

      // 개별적으로 사용할 일이 없고,, 구분지어야할 명령문이 그리 길거나 또 많지 않기 때문에 배열
      // 로 풀지 않음. 더 복잡하기도 하고.. 
      for (size_t count = 0; count < 4; ++count) {
        switch (type) {
          case 0:
            ch = *static_cast<char*>(detected_type);
          case 1:
            inum = *static_cast<int*>(detected_type);
          case 2:
            fnum = *static_cast<float*>(detected_type); // 아마 포인터 그대로 하면 안될 듯?
          case 3:
            dnum = *static_cast<double*>(detected_type); // ..
          default:
            // exception
            break;
        }
        type = (++type) % 4
      }
    // converter.display();
  } catch (...) {
    return -1;
  }
  converter.display();
  return 0;

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
  return TYPE;

  std::cout << type << '\n';
}
