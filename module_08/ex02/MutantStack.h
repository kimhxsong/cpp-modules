#ifndef MUTANTSTACK_H_
#define MUTANTSTACK_H_

#include <list>
#include <stack>
#include <deque>

template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
 public:
  typedef typename std::stack<T, C>::container_type::iterator
                   iterator;
  typedef typename std::stack<T, C>::container_type::const_iterator
                   const_iterator;
  typedef typename std::stack<T, C>::container_type::reverse_iterator
                   reverse_iterator;
  typedef typename std::stack<T, C>::container_type::const_reverse_iterator
                   const_reverse_iterator;

  MutantStack()
    : std::stack<T, C>() {}

  MutantStack(const MutantStack& other) {
    if (this != &other) this->c = other.c;
  }

  ~MutantStack() {}

  MutantStack& operator=(const MutantStack& other) {
    if (this != &other) this->c = other.c;
    return *this;
  }

  iterator begin() { return this->c.begin(); }
  const_iterator begin() const { return this->c.begin(); }

  iterator end() { return this->c.end(); }
  const_iterator end() const { return this->c.end(); }

  reverse_iterator rbegin() { return this->c.rbegin(); }
  const_reverse_iterator rbegin() const { return this->c.rbegin(); }; 

  reverse_iterator rend() { return this->c.rend(); }
  const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif  // MUTANTSTACK_H_
