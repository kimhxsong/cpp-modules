#ifndef EASYFIND_H_
#define EASYFIND_H_

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T cont, int n) {
  typename T::iterator found = std::find(cont.begin(), cont.end(), n);
  if (found == cont.end()) {
    throw std::runtime_error("element not found");
  }
  return found;
}

#endif  // EASYFIND_H_
