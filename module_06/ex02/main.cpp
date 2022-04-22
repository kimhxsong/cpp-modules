#include <iostream>

#include "Base.h"

void do_something() {
  Base* test = generate();
  Base empty;

  identify(test);
  identify(*test);

  try {
    identify(NULL);
  } catch (const std::string& s) {
    std::cout << s;
  }

  try {
    identify(empty);
  } catch (const std::string& s) {
    std::cout << s;
  }

  delete test;
}

int main() {
  do_something();
  system("leaks test");
  return 0;
}
