#ifndef CONVERT_H_
#define CONVERT_H_

#include <string>

struct Convert {
  enum eType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
  };

  int detectType(const char* str);
  void execute(int type, const std::string& str);
};

#endif  // CONVERT_H_
