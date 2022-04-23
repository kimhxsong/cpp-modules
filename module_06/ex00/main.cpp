#include <exception>
#include <iostream>

#include "Convert.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: It takes only one argument\n";
    return 1;
  }

  if (std::strlen(argv[1]) == 0) {
    std::cout << "Error: The argument is empty\n";
    return 1;
  }

  try {
    Convert convert(argv[1]);
    convert.print();
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
