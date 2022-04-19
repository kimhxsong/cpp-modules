#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
    // override
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    // override
    const char* what() const throw();
  };

  Bureaucrat();
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat(const std::string& name, const unsigned int grade);

  ~Bureaucrat();

  Bureaucrat& operator=(const Bureaucrat& other);

  const std::string& getName() const;
  unsigned char getGrade() const;

  void  setName(const std::string& name);

  void incrementGrade();
  void decrementGrade();

 private:
  void setGrade(const unsigned int grade);

  const std::string name_;
  const unsigned int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif  // BUREAUCRAT_H_
