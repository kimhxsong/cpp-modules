#include "Span.h"

#include <algorithm>
#include <set>
#include <stdexcept>

Span::Span()
  : size_(0),
    data_() {}

Span::Span(const Span& other)
  : size_(other.size_),
    data_(other.data_) {}

Span::Span(unsigned int N)
  : size_(N) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    data_ = other.data_;
    size_ = other.size_;
  }
  return *this;
}

void Span::resize(unsigned int N) {
  if (data_.size() >= N) { 
    throw std::logic_error("smaller than the size of the currently stored data.");
  }
  size_ = N;
}

void Span::addNumber(int elem) {
  if (size_ == data_.size()) {
    throw std::logic_error("has no space");
  }
  data_.insert(elem);
}

const std::multiset<int>& Span::data() const { return data_; }

unsigned int Span::shortestSpan() {
  if (data_.size() < 2) {
    throw std::logic_error("span no found");
  }

  std::multiset<int> diff_data;
  for(std::multiset<int>::iterator it = data_.begin();
      std::distance(it, data_.end()) > 1;) {
    std::multiset<int>::iterator prev_it = it;
    diff_data.insert(*(++it) - *prev_it);
  }
  return *(diff_data.begin());
}

unsigned int Span::longestSpan() {
  if (data_.size() < 2) { throw std::logic_error("span no found"); }
  return (*(data_.rbegin()) - *(data_.begin()));
}
