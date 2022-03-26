#include "Harl.hpp"

#include <iostream>
#include <string>

Harl::Harl() {
  fn_table_[LEVEL_DEBUG].level = "DEBUG";
  fn_table_[LEVEL_DEBUG].fn = &Harl::debug;
  fn_table_[LEVEL_INFO].level = "INFO";
  fn_table_[LEVEL_INFO].fn = &Harl::info;
  fn_table_[LEVEL_WARNING].level = "WARNING";
  fn_table_[LEVEL_WARNING].fn = &Harl::warning;
  fn_table_[LEVEL_ERROR].level = "ERROR";
  fn_table_[LEVEL_ERROR].fn = &Harl::error;
}

Harl::~Harl() {}

int Harl::findLogLevel(const std::string &level) {
  for (int i = 0; i < 4; ++i) {
    if (level == fn_table_[i].level) { return (i); }
  }
  return (-1);
}

void Harl::filter(const std::string& level) {
  const int log_level = findLogLevel(level);
  switch (log_level) {
  case LEVEL_DEBUG:
    debug();
  case LEVEL_INFO:
    info();
  case LEVEL_WARNING:
    warning();
  case LEVEL_ERROR:
    error();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]\n\n";
    break;
  }
}

void Harl::debug() {
  std::cout <<
    "[ DEBUG ]\n" <<
    "I love to get extra bacon for my 7XL-double-cheese" <<
    "-triple-pickle-special-ketchup burger. I just love it!\n";
}

void Harl::info() {
  std::cout <<
    "[ INFO ]\n" <<
    "I cannot believe adding extra bacon cost more money." <<
    "You don’t put enough! If you did I would not have to ask for it!\n";
}

void Harl::warning() {
  std::cout <<
    "[ WARNING ]\n" <<
    "I think I deserve to have some extra bacon for free." <<
    "I’ve been coming here for years and you just started working here" <<
    "last month.\n";
}

void Harl::error() {
  std::cout <<
    "[ ERROR ]\n" <<
    "This is unacceptable, I want to speak to the manager now.\n";
}
