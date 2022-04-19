#ifndef FORM_H_
#define FORM_H_

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class Form {
 public:
   class AlreadySignedException : public std::exception {
   public:
    // override
    const char *what() const throw();
  };

  class GradeTooHighException : public std::exception {
   public:
    // override
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    // override
    const char *what() const throw();
  };

  Form();
  Form(const Form& other);
  Form(const std::string& name, const unsigned int signable_grade,
                                const unsigned int executable_grade);

  virtual ~Form();

  Form& operator=(const Form& other);

  const std::string& getName() const;
  unsigned int getSignableGrade() const;
  unsigned int getExecutableGrade() const;
  const std::string& getTarget() const;
  
  bool isSigned() const;
  void beSigned(const Bureaucrat& signer) const;
  virtual void execute(Bureaucrat const & executor) const = 0;

 protected:
  std::string target_;

 private:
  const std::string name_;
  const unsigned int kSignableGrade_;
  const unsigned int kExecutableGrade_;
  const bool sign_;
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif  // FORM_H_
