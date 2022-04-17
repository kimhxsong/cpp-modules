#ifndef BUREAUCRAT_H_
#define BUREAUCRAT_H_

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
    // override
    const char* what() const throw() { return "Exception: Grade Too High"; };
  };

  class GradeTooLowException : public std::exception {
   public:
    // override
    const char* what() const throw() { return "Exception: Grade Too Low"; };
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
  void signForm(Form& form);

 private:
  void setGrade(const unsigned int grade);

  const std::string name_;
  unsigned int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif  // BUREAUCRAT_H_
