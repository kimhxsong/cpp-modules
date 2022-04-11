#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

class Animal {
 public:
  virtual ~Animal();

  Animal& operator=(const Animal& other);

  const std::string& getType() const;

  virtual void makeSound() const = 0;

 protected:
  Animal();
  Animal(const Animal& other);
  Animal(const std::string& type);

  std::string type_;
};

#endif  // ANIMAL_H_
