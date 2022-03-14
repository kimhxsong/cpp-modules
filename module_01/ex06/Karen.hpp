#ifndef KAREN_HPP
# define KAREN_HPP

# include <string>

class Karen
{
public:
	enum eLevel {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	typedef struct Karen_s {
		std::string	level;
		void		(Karen::*fn)(void);
	}	Karen_t;

	int		_findLogLevel(std::string &level);
	void	complain(std::string level);
	void	filter(std::string level);

	Karen(void);
	~Karen(void);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	Karen_t	mTable[4];
};

#endif