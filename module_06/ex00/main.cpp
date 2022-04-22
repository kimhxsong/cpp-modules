#include <iostream>
#include <limits.h>
#include <sstream>
#include <string>
#include "Convert.h"


int main(int argc, char *argv[]) {
  Convert Convert;
  if (argc != 2) {
    std::cout << "Error: It takes only one argument\n";
    return 1;
  }

  if (std::strlen(argv[1]) == 0) {
    std::cout << "Error: The argument is empty\n";
    return 1;
  }

  std::string istr(argv[1]);
  int type = Convert.detectType(istr.c_str());
  if (type == -1) {
    std::cout << "Error\n";
  }
  Convert.execute(type, istr);
  return 0;
}
