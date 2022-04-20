#ifndef DATA_H_
#define DATA_H_

#include <cstdint>

struct Data {
  double dval;
  float fval;
  int ival;
  char ch;
};

uintptr_t serializie(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif  //DATA_H_
