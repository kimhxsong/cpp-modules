//
// Created by Hyeonsong Kim on 3/9/22.
//

#ifndef PHONECONTACT_HPP
#define PHONECONTACT_HPP

#include <string>

using std::string;

class PhoneContact {
public:
    PhoneContact(void);
    ~PhoneContact(void);

private:
    string  mFirstName;
    string  mLastName;
    string  mNickname;
    string  mPhoneNumber;
    string  mDarkestSecret;
};

#endif //PHONECONTACT_HPP
