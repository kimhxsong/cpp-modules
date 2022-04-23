#include <exception>
#include <iostream>
#include <string>

#include "Base.h"

void do_something() {
  Base* test = generate();
  Base empty;

  identify(test);
  identify(*test);

  try {
    identify(NULL);
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  try {
    identify(empty);
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << '\n';
  }

  delete test;
}

int main() {
  do_something();
  // system("leaks test");
  return 0;
}
