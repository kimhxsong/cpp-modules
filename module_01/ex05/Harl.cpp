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

void Harl::complain(std::string level) {
  for (size_t index = 0; index < 4; ++index) {
    if (level == fn_table_[index].level) {
      (this->*fn_table_[index].fn)();
      return;
    }
  }
  std::cout << "[ Probably complaining about insignificant problems ]\n";
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
