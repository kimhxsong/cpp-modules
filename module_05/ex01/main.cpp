#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"

int main() {
  try {
    Bureaucrat one;
    Bureaucrat two = one;
    Bureaucrat three;
    three = one;

    // Bureaucrat high1("high1", 0);
    // std::cout << high1 << '\n';

    // Bureaucrat low1("low1", 151);
    // std::cout << low1 << '\n';

    // Bureaucrat high2("high2", 1);
    // std::cout << high2 << '\n';

    // high2.incrementGrade();

    // Bureaucrat low2("low2", 150);
    // std::cout << high2 << '\n';

    // low2.decrementGrade();

    Bureaucrat common("common", 23);

    common.incrementGrade();
    common.incrementGrade();
    std::cout << common;
    common.decrementGrade();
    std::cout << common;

    throw 42;

  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  } catch (int n) {
    std::cout << n << '\n';
  }

  Bureaucrat someone("someone", 25);
  Form formA("formA", 50, 20);
  std::cout << formA << '\n';
  Form formB("formB", 24, 10);
  std::cout << formB << '\n';
  someone.signForm(formA);
  Form formC(formA);
  std::cout << formC << '\n';
  someone.signForm(formB);

  return 0;
}
