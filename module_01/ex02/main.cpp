#include <new>
#include <string>
#include <iostream>

int main() {
  std::string str("HI THIS IS BRAIN");
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout <<
    "\n===The Address in momory of the string====\n" <<
    "stringORG: " << &str << '\n' <<
    "stringPTR: " << stringPTR << '\n' <<
    "stringREF: " << &stringREF << '\n';

  std::cout <<
    "\n===Display the string=====================\n" <<
    "stringORG: " << str << '\n' <<
    "stringPTR: " << *stringPTR << '\n' <<
    "stringREF: " << stringREF << '\n';

  std::cout << '\n';
  return 0;
}
