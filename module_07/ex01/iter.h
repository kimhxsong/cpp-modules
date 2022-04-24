#ifndef ITER_H_
#define ITER_H_

#include <cstddef>

template<typename T>
void iter(const T* array, std::size_t len, void (*fn)(const T&)) {
  for (std::size_t i = 0; i < len; ++i) { 
    fn(array[i]);
  }
}

#endif  // ITER_H_
