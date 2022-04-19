#include "PresidentialPardonForm.h"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
  : Form("PresidentialPardonForm", 25, 5),
    target_("RandomTarget") {
  std::cout << "PresidentialPardonForm Default Constructor Called\n";
  
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
  : Form("PresidentialPardonForm", 25, 5),
    target_("RandomTarget") {
  std::cout << "PresidentialPardonForm Copy Constructor Called\n";
  *this = other;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : Form("PresidentialPardonForm", 25, 5) {
  std::cout << "PresidentialPardonForm Parameterized Constructor Called\n";
  target_ = target; 
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm Destructor Called\n";
}

PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
  std::cout << "PresidentialPardonForm Copy Operator Called\n";
  target_ = other.getTarget();
  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
  if (getExecutableGrade() < executor.getGrade()) {
    throw GradeTooLowException();
  }
  std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
