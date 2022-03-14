#include <string>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie {
public:
	Zombie();
	Zombie(std::string name);
	~Zombie(void);

	void		setName(std::string name);
	std::string	getName(void);
	void		announce(void);

private:
	std::string	mName;
};

Zombie* zombieHorde(int N, std::string name);

#endif
