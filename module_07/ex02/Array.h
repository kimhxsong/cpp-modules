#ifndef ARRAY_H_
#define ARRAY_H_

template<typename T>
class Array {
 public:
  Array();
  Array(const Array& other);
  Array(unsigned int size);
  ~Array();

  Array& operator=(const Array& other);
  T& operator[](long index) const;

  unsigned int size() const;

 private:
  T*  data_;
  unsigned int size_;
};

template<typename T>
Array<T>::Array()
  : data_(new T[0]),
    size_(0) {
# ifdef DEBUG
  std::cout << "(void*)data: " << data_ << std::endl;
# endif
}

template<typename T>
Array<T>::Array(const Array& other)
  : data_(NULL) {
  *this = other;
}

template<typename T>
Array<T>::Array(unsigned int size) {
  data_ = new T[size];
  size_ = size;
# ifdef DEBUG
  std::cout << "(void*)data: " << data_ << std::endl;
# endif
}
template<typename T>
Array<T>::~Array() { delete[] data_; }

template<typename T>
Array<T> &Array<T>::operator=(const Array& other) {
  if (data_) delete data_;
  size_ = other.size();
  data_ = new T[size_];
  for (unsigned int i = 0; i < size_; ++i) {
    data_[i] = const_cast<T&>(other[i]);
  }
# ifdef DEBUG
  std::cout << "(void*)data: " << data_ << std::endl;
# endif
  return *this;
}

template<typename T>
T& Array<T>::operator[](long index) const {
  if (index < 0 || index >= size_) {
    throw std::runtime_error("Array Index Out of Bounds");
  }
  return data_[index];
}

template<typename T>
unsigned int Array<T>::size() const {
  return size_;
}

#endif  // ARRAY_H_
