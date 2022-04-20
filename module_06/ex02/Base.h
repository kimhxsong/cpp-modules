#ifndef BASE_H_
#define BASE_H_

class Base {
 public:
  virtual ~Base();
};

Base* generate();
void identify(Base* p);
void identify(Base& p);


#endif  //BASE_H_
