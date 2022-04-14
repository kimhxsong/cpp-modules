#include "Intern.h"

#include <iostream>

#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

// static
std::string Intern::form_name_table_[3] = {
  "presidential pardon", 
  "robotomy request", 
  "shrubbery creation"
};

// static
int Intern::findFormType(const std::string& name) {
  int type_index = 0;
  while (type_index < kNumberOfForm) {
    if (form_name_table_[type_index] == name) {
      break ;
    }
    ++type_index;
  }
  return type_index;
}

Intern::Intern() {
  std::cout << "Intern Default Constructor Called\n";
}

Intern::Intern(const Intern& other) {
  (void)other;
  std::cout << "Intern Copy Constructor Called\n";
}

Intern::~Intern() {
  std::cout << "Intern Destructor Called\n";
}

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  std::cout << "Intern Copy Operator Called\n";
  return *this;
}

Form* Intern::makeForm(const std::string& name,
                       const std::string& target) {
  Form *form;
  try {
    switch (findFormType(name)) {
     case FORM_TYPE_PP:
      form = new PresidentialPardonForm(target);
      break;
     case FORM_TYPE_RR:
      form = new RobotomyRequestForm(target);
      break;
     case FORM_TYPE_SC:
      form = new ShrubberyCreationForm(target);
      break;
     default:
      throw 42;
    }
  } catch (int e) {
    std::cout << "Intern can't create '" << name <<
                 " Because A form with that name does not exist\n";
  }
  return form;
}
