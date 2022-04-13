#include "ShrubberyCreationForm.h"

#include <ctime>
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
  : Form("ShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm Default Constructor Called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
  : Form("ShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm Copy Constructor Called\n";
  *this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : Form("ShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm Parameterized Constructor Called\n";
  target_ = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm Destructor Called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
  std::cout << "ShrubberyCreationForm Copy Operator Called\n";
  target_ = other.getTarget();
  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
  if (getExecutableGrade() < executor.getGrade()) {
    throw GradeTooLowException();
  }

  const std::string filename = getTarget() + "_shrubbery";
  {

    std::ifstream istrm(".shrubbery");
    std::ofstream ostrm(filename, std::ios::out);
    ostrm << istrm.rdbuf() << '\n';
    std::time_t rawtime = std::time(NULL);
    ostrm << "Created by " << executor.getName() << " " << ctime(&rawtime);
  }
}
