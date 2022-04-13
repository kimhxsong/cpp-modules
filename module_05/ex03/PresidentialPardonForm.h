#ifndef PRESIDENTIALPARDONFORM_H_
#define PRESIDENTIALPARDONFORM_H_

#include <string>

#include "Bureaucrat.h"
#include "Form.h"

class PresidentialPardonForm : virtual public Form {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm(const std::string& target);

  virtual ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  // override
  void execute(const Bureaucrat& executor) const;
};

#endif  // PRESIDENTIALPARDONFORM_H_
