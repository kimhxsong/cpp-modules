#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  enum eLevel {
    LEVEL_DEBUG,
    LEVEL_INFO,
    LEVEL_WARNING,
    LEVEL_ERROR
  };

  typedef struct Harl_s {
    std::string level;
    void (Harl::*fn)();
  } Harl_t;

  Harl();
  ~Harl();

  void complain(std::string level);

 private:
  void debug();
  void info();
  void warning();
  void error();

  Harl_t fn_table_[4];
};

#endif  // HARL_HPP_
