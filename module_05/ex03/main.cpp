#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"
#include "Intern.h"

int main() {
  Intern someRandomIntern;
  Form* rrf;
  Form* ppf;
  Form* scf;

  rrf = someRandomIntern.makeForm("robotomy request", "TARGET[1]");
  ppf = someRandomIntern.makeForm("presidential pardon", "TARGET[2]");
  scf = someRandomIntern.makeForm("shrubbery creation", "TARGET[3]");

  Bureaucrat person("EXCUTOR", 1);
  person.executeForm(*rrf);
  person.executeForm(*ppf);
  person.executeForm(*scf);

  return 0;
}
