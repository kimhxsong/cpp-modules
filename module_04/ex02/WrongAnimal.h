#ifndef WRONGANIMAL_H_
#define WRONGANIMAL_H_

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& other);

  ~WrongAnimal();
  
  WrongAnimal& operator=(const WrongAnimal& other);

  const std::string& getType() const;

  void makeSound() const;

 protected:
  WrongAnimal(const std::string& type);

  std::string type_;
};

#endif  // WRONGANIMAL_H_
