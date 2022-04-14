#ifndef INTERN_H_
#define INTERN_H_

#include <string>

#include "Form.h"

class Intern {
 public:
  enum eFormType {
    FORM_TYPE_PP,
    FORM_TYPE_RR,
    FORM_TYPE_SC,
    FORM_TYPE_INVALID
  };

  static const int kNumberOfForm = 3;
  static int findFormType(const std::string& name);

  Intern();
  Intern(const Intern& other);

  ~Intern();

  Intern& operator=(const Intern& other);

  Form* makeForm(const std::string& name, const std::string& target);

 private:
  static std::string form_name_table_[3];
};

#endif  // INTERN_H_
