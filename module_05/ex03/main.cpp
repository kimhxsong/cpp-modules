#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"
#include "Intern.h"

int main() {
  Intern someRandomIntern;
  Form* rrf;
  rrf = someRandomIntern.makeForm("robotomy request", "Bender");

  Bureaucrat person("A", 1);
  person.executeForm(*rrf);

  return 0;
}
