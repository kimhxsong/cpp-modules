#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {
  Bureaucrat someone("Marvin", 1);

  // PresidentialPardonForm ppf("target1");
  // std::cout << ppf << '\n';
  // RobotomyRequestForm rrf("target2");
  // std::cout << rrf << '\n';
  ShrubberyCreationForm scf("target3");
  // std::cout << scf << '\n';

  // someone.executeForm(ppf);
  // someone.executeForm(rrf);
  someone.executeForm(scf);

  return 0;
}
