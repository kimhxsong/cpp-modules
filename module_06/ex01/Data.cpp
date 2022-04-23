#include "Data.h"

#include <cstdint>

uintptr_t serializie(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
  return reinterpret_cast<Data*>(raw);
}
