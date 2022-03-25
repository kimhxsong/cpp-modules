#ifndef PHONECONTACT_HPP
#define PHONECONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

using std::string;

class PhoneContact {
 public:
  PhoneContact();
  ~PhoneContact();

  string getFirstName();
  string getNickname();
  string getLastName();
  string getPhoneNumber();
  string getDarkestSecret();

  void setFirstName();
  void setLastName();
  void setNickname();
  void setPhoneNumber();
  void setDarkestSecret();

 private:
  string first_name_;
  string last_name_;
  string nickname_;
  string phone_number_;
  string darkest_secret_;
};

#endif  // PHONECONTACT_HPP
