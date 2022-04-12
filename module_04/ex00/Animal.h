#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
 public:
  Animal();
  Animal(const Animal& other);

  virtual ~Animal();
  
  Animal& operator=(const Animal& other);

  const std::string& getType() const;

  virtual void makeSound() const;

 protected:
  Animal(const std::string& type);

  std::string type_;
};

#endif  // ANIMAL_H_
