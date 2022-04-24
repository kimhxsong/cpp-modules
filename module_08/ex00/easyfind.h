#ifndef EASYFIND_H_
#define EASYFIND_H_

#include <algorithm>

template<typename T>
typename std::iterator_traits<typename T::iterator>::difference_type
easyfind(T cont, int n) {
  typename T::iterator found = std::find(cont.begin(), cont.end(), n);
  if (found == cont.end()) {
    throw std::runtime_error("element not found");
  }
  return std::distance(cont.begin(), found);
}

#endif  // EASYFIND_H_
