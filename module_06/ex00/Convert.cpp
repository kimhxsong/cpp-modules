#include "Convert.h"

#include <string>
#include <iostream>
#include <fstream>  // ifstream::failure
#include <sstream>  // istringstream
#include <limits>  // numeric_limits<...>

// static
bool Convert::isSign(char ch) {
  return (ch == '+' || ch == '-');
}

Convert::Convert()
  : bIsNan_(true) {}

Convert::~Convert() {}

Convert::Convert(const Convert& other) {
  *this = other;
}

Convert::Convert(const std::string& input)
  : input_(input),
    states_(),
    bIsNan_(false),
    bIsInf_(false) {
  if (detectType() == -1 ) { throw std::logic_error("invalid argument"); }
  execute();
}

Convert& Convert::operator=(const Convert& other) {
  input_ = other.input_;
  for (size_t i = 0; i < 4; ++i) {
    states_[i] = other.states_[i];
  }
  type_ = other.type_;
  d_ = other.d_;
  f_ = other.f_;
  i_ = other.i_;
  c_ = other.c_;
  bIsNan_ = other.bIsNan_;
  bIsInf_ = other.bIsInf_;
  return *this;
}

void Convert::executeFromNan() {
  if (bIsNan_ == true) {
    states_[0] = -1;  // impossible
    states_[1] = -1;  // impossible
    states_[2] = -1;  // nanf
    states_[3] = -1;  // nan
    return;
  }
}

void Convert::executeFromInf() {
  if (bIsInf_ == true) {
    states_[0] = -1;  // impossible
    states_[1] = -1;  // impossible
    states_[2] = 1;  // inff, -inff
    states_[3] = 1;  // inf, -inf
    return;
  }
}

void Convert::executeFromInt(std::istringstream& iss) {
  try {
    iss >> i_;
  } catch (std::ifstream::failure e) {
    if (i_ == std::numeric_limits<int>::max() ||
        i_ == std::numeric_limits<int>::min()) {
      throw std::overflow_error("integer overflow");
    }
    throw;
  }

  c_ = static_cast<char>(i_);
  f_ = static_cast<float>(i_);
  d_ = static_cast<double>(i_);

  if (i_ > std::numeric_limits<char>::max() ||
      i_ < std::numeric_limits<char>::min()) {
    states_[0] = -1;  // impossible
  } else if (!std::isprint(i_)) {
    states_[0] = 1;  // Non Displayable
  }

  if(!iss.eof()) throw std::runtime_error("unexpected");  // unexpected
}

void Convert::executeFromFloat(std::istringstream& iss) {
  try {
    iss >> f_;
  } catch (std::ifstream::failure e) {
    throw std::logic_error("invalid argument");
  }

  c_ = static_cast<char>(f_);
  i_ = static_cast<int>(f_);
  d_ = static_cast<double>(f_);

  if (f_ > std::numeric_limits<char>::max() ||
      f_ < std::numeric_limits<char>::min()) {
    states_[0] = -1;
  } else {
    states_[0] = std::isprint(f_) ? 0 : 1; // Non Displayable
  }

  if (f_ > std::numeric_limits<int>::max() ||
      f_ < std::numeric_limits<int>::min()) {
    states_[1] = -1; // impossible
  }

  if(!iss.eof()) throw std::runtime_error("unexpected");  // unexpected
}

void Convert::executeFromDouble(std::istringstream& iss) {
  try {
    iss >> d_;
  } catch (std::ifstream::failure e) {
    throw std::logic_error("invalid argument");
  }

  c_ = static_cast<char>(d_);
  i_ = static_cast<int>(d_);
  f_ = static_cast<float>(d_);

  if (d_ > std::numeric_limits<char>::max() ||
      d_ < std::numeric_limits<char>::min()) {
    states_[0] = -1;
  } else {
    states_[0] = std::isprint(i_) ? 0 : 1; // Non Displayable
  }

  if (d_ > std::numeric_limits<int>::max() ||
      d_ < std::numeric_limits<int>::min()) {
    states_[1] = -1;
  }

  if(!iss.eof()) throw std::runtime_error("unexpected");  // unexpected
}

void Convert::printDouble() {
  std::cout << "double: ";
  switch(states_[3]) {
    case 0:
      std::cout << std::fixed << std::setprecision(1) << d_;
      break;
    case 1: {
      char sign = (input_[0] == '-') ? '-' : '+';
      std::cout << sign << "inf";
      break;
    }
    default:
      std::cout << "nan";
  }
  std::cout << std::endl;
}

void Convert::printFloat() {
  std::cout << "float: ";
  switch(states_[2]) {
    case 0:
      std::cout << std::fixed << std::setprecision(1) << f_;
      break;
    case 1:
      char sign;
      sign = (input_[0] == '-') ? '-' : '+';
      std::cout << sign << "inf";
      break;
    default:
      std::cout << "nan";
      break;
  }
  std::cout << "f\n";
}

void Convert::printInt() {
  std::cout << "int: ";
  switch(states_[1]) {
    case 0:
      std::cout << i_;
      break;
    default:
      std::cout << "impossible";
  }
  std::cout << std::endl;
}

void Convert::printChar() {
  std::cout << "char: ";
  switch(states_[0]) {
    case 0:
      std::cout << '\'' << c_ << '\'';
      break;
    case 1:
      std::cout << "Non displayable";
      break;
    default:
      std::cout << "impossible";
  }
  std::cout << std::endl;
}

void Convert::print() {
  if (input_.empty() == true) throw std::logic_error("unintialized instance");

  printChar();
  printInt();
  printFloat();
  printDouble();
}

void Convert::execute() {
  if (input_.empty() == true) throw std::logic_error("unintialized instance");
  if (bIsInf_) { return executeFromInf(); }
  if (bIsNan_) { return executeFromNan(); };

  std::istringstream iss(input_);
  iss.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  switch(type_) {
    case TYPE_INT:
      executeFromInt(iss);
      break;
    case TYPE_FLOAT:
      executeFromFloat(iss);
      break;
    case TYPE_DOUBLE:
      executeFromDouble(iss);
      break;
    default:
    // Never Through
      break;
  }
}

int Convert::detectType() {
  size_t idx = 0;
  size_t found = 0;
  bool bDotFound = false;
  bool bFFound = false;

  idx += (input_.length() != 1) && isSign(input_[idx]);

  if ((found = input_.find("nan", 0)) != std::string::npos && found == 0) {
    bIsNan_ = true;
  } else if ((found = input_.find("inf", idx)) != std::string::npos) {
    bIsInf_ = true;
  }

  if (bIsNan_ == true || bIsInf_ == true) {
    input_.replace(found, 3, ".");
    if (input_[idx] != '.') { return -1; }
  }

  if ((found = input_.find('.', idx)) != std::string::npos) {
    for (size_t i = idx; i < found; ++i) {
      if (std::isdigit(input_[i]) == false) {
        return -1;  // invalid argument
      }
    }
    idx = found + 1;
    bDotFound = true;
  }

  if ((found = input_.find('f', found)) != std::string::npos) {
    if (((bDotFound == true) && (found != (input_.length() - 1))) ||
        bDotFound == false) {
      return -1;  // invalid argument
    }
    input_.erase(found, 1);
    bFFound = true;
  }

  for (size_t i = idx; input_[i] != '\0'; ++i) {
    if (std::isdigit(input_[i]) == false) {
      return -1;  // invalid argument
    }
  }

  if (bFFound == true) {
    type_ = TYPE_FLOAT;
  } else if (bDotFound == true) {
    type_ = TYPE_DOUBLE;
  } else {
    type_ = TYPE_INT;
  }

  return 0;
}
