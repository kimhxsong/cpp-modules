#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

int main() {
  Bureaucrat someone("someone", 25);

  try {
    Form formA("formA", 50, 20);
    std::cout << formA << '\n';
    someone.signForm(formA);
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Form formB("formB", 24, 10);
    std::cout << formB << '\n';
    someone.signForm(formB);
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Form formA("formA", 50, 20);
    Form formC;
    std::cout << formC << '\n';
    formC = formA;
    std::cout << formC << '\n';
    someone.signForm(formC);
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  return 0;
}
