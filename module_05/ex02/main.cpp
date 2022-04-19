#include <exception>
#include <iostream>

#include "Bureaucrat.h"
#include "Form.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main() {
  Bureaucrat someone("Marvin", 1);
  Bureaucrat anonymous;

  {
    PresidentialPardonForm ppf("target1");
    std::cout << ppf << '\n';
    try {
      ppf.beSigned(anonymous);
    } catch (const std::exception& e) {
      std::cout << "Exception: " << e.what() << '\n';
    }
    someone.executeForm(ppf);
  }

  std::cout << std::endl;

  {
    RobotomyRequestForm rrf("target2");
    std::cout << rrf << '\n';
    someone.executeForm(rrf);
  }

  std::cout << std::endl;

  {
    ShrubberyCreationForm scf("target3");
    std::cout << scf << '\n';
    someone.executeForm(scf);
  }

  return 0;
}
