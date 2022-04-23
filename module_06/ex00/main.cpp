#include <cctype>

#include <exception>
#include <iostream>

#include "Convert.h"

static void toLowerString(std::string& input) {
  size_t len = input.length();
  for (size_t i = 0; i < len; ++i) {
      input[i] = std::tolower(input[i]);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: It takes only one argument\n";
    return 1;
  }

  if (std::strlen(argv[1]) == 0) {
    std::cout << "Error: The argument is empty\n";
    return 1;
  }

  std::string input(argv[1]);
  toLowerString(input);

  try {
    Convert convert(input);
    convert.print();
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
