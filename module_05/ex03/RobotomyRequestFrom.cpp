#include "RobotomyRequestForm.h"

#include <cstdlib>
#include <iostream>
#include <random>

RobotomyRequestForm::RobotomyRequestForm()
  : Form("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm Default Constructor Called\n";
  
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : Form("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm Copy Constructor Called\n";
  *this = other;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : Form("RobotomyRequestForm", 72, 45) {
  std::cout << "RobotomyRequestForm Parameterized Constructor Called\n";
  target_ = target;
  
}
RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << "RobotomyRequestForm Destructor Called\n";
}

RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
  std::cout << "RobotomyRequestForm Copy Operator Called\n";
  target_ = other.getTarget();

  return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
  if (getExecutableGrade() < executor.getGrade()) {
    throw GradeTooLowException();
  }

  std::cout << "%*&#^&$* #&* ~!#@$# )#&$*\n";
  // NULL(until c++11), nullptr(since c++11)
  std::srand(std::time(NULL));
  const bool isRobotomized = std::rand() % 2;

  if (isRobotomized == true) {
    std::cout << getTarget() << " has been robotomized\n";
    return;
  }

  std::cout << "The robotomy failed\n";
}


