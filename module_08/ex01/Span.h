
#include <set>

class Span {
 public:
  Span();
  Span(const Span& other);
  Span(unsigned int N);
  ~Span();

  Span& operator=(const Span& other);
  void addNumber(int i);

  const std::multiset<int>& data() const;
  void resize(unsigned int N);

  template<typename Iter>
  void addNumbers(Iter first, Iter last) {
    while (first != last) {
      addNumber(*first++);
    }
  }
  unsigned int shortestSpan();
  unsigned int longestSpan();

 private:
  unsigned int size_;
  std::multiset<int> data_;
};
