#include <exception>
#include <iostream>

#include "Bureaucrat.h"

int main() {
  try {
    Bureaucrat one;
    Bureaucrat two = one;
    Bureaucrat three;
    three = one;
    std::cout << one << '\n';
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Bureaucrat high1("high1", 0);
    std::cout << high1 << '\n';
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Bureaucrat low1("low1", 151);
    std::cout << low1 << '\n';
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Bureaucrat high2("high2", 1);
    std::cout << high2 << '\n';

    high2.incrementGrade();
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Bureaucrat low2("low2", 150);
    std::cout << low2 << '\n';

    low2.decrementGrade();
  } catch (const std::exception& e ) {
    std::cout << "Exception: " << e.what() << '\n';
  }

  std::cout << std::endl;

  try {
    Bureaucrat common("common", 23);

    common.incrementGrade();
    common.incrementGrade();
    std::cout << common;
    common.decrementGrade();
    std::cout << common;

    throw 42;
  } catch (int n) {
    std::cout << n << '\n';
  }

  return 0;
}
