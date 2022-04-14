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

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Error: It takes only one argument.\n";
    return 1;
  }
  int fnum;
  std::stringstream sstrm(argv[1]);
  sstrm >> fnum;
  std::cout << "failbit" << sstrm.fail() << " eofbit " << sstrm.eof();
  std::cout << " " << std::fixed << fnum << '\n';
  sstrm >> fnum;
  std::cout << "failbit" << sstrm.fail() << " eofbit " << sstrm.eof();
  std::cout << " " << fnum << '\n';
}
