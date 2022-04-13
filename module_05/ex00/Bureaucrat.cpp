#include "Bureaucrat.h"

#include <iostream>
#include <ostream>
#include <string>

Bureaucrat::Bureaucrat()
  : grade_(150) {
  std::cout << "Bureaucrat Default Constructor Called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
  std::cout << "Bureaucrat Copy Constructor Called\n";
  *this = other;
}
Bureaucrat::Bureaucrat(const std::string& name, const unsigned int grade)
  : name_(name),
    grade_(grade) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  }
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat Destructor Called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << "Bureaucrat Copy Operator Called\n";
  *const_cast<std::string*>(&name_) = other.getName();
  grade_ = other.getGrade();
  return *this;
}

const std::string& Bureaucrat::getName() const {
  return name_;
}

unsigned char Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::setGrade(const unsigned int grade) {
  if (grade > 150) {
    throw GradeTooLowException();
  } else if (grade < 1) {
    throw GradeTooHighException();
  }
  grade_ = grade;
}

void Bureaucrat::incrementGrade() {
  const unsigned int grade = getGrade();
  setGrade(grade - 1);
}

void Bureaucrat::decrementGrade() {
  const unsigned int grade = getGrade();
  setGrade(grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs) {
  os << rhs.getName() << ", bureaucrat grade " <<
        static_cast<int>(rhs.getGrade()) << '\n';
  return os;
}
