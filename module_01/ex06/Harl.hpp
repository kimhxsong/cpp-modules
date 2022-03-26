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

  void complain(const std::string& level);
  void filter(const std::string& level);

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  int findLogLevel(const std::string &level);

  Harl_t fn_table_[4];
};

#endif  // HARL_HPP_
