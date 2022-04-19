#ifndef SHRUBBERYCREATIONFORM_H_
#define SHRUBBERYCREATIONFORM_H_

#include <string>

#include "Bureaucrat.h"
#include "Form.h"

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm(const std::string& target);

  virtual ~ShrubberyCreationForm();

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  // override
  void execute(const Bureaucrat& executor) const;
};

#endif  // SHRUBBERYCREATIONFORM_H_
