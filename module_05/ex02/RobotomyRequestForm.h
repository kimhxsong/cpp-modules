#ifndef ROBOTOMYREQUESTFORM_H_
#define ROBOTOMYREQUESTFORM_H_

#include <string>

#include "Bureaucrat.h"
#include "Form.h"

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm(const std::string& target);

  virtual ~RobotomyRequestForm();

  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  // override
  void execute(const Bureaucrat& executor) const;
};

#endif  // ROBOTOMYREQUESTFORM_H_
