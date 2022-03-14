#include <string>
#include <iostream>
#include <fstream>

using std::string;

void	ft_sed(string &filename, string &s1, string &s2)
{
	std::ifstream	ifs(filename);
	if (ifs.is_open() == false) {
		std::perror("ifstream");
		return ;
	}

	std::ofstream	ofs(filename + ".replace");
	if (ofs.is_open() == false) {
		std::perror("ofstream");
		ifs.close();
		return ;
	}

	if (s1 == s2) {
		while (1) {
			string	line;
			std::getline(ifs, line);
			ofs << line << std::endl;
			if (ifs.eof() == true) {
				ifs.close();
				ofs.close();
				break ;
			}
		}
		return ;
	}

	while (1) {
		string	replacedLine;
		size_t	pos = 0;
		string	line;
		std::getline(ifs, line);
		while (1) {
			size_t	foundIndex = line.find(s1, pos);
			if (foundIndex == string::npos) {
				replacedLine += line.substr(pos, line.length() - pos);
				break ;
			}
			while (pos < foundIndex) {
				replacedLine.push_back(line[pos]);
				++pos;
			}
			replacedLine += s2;
			pos += s1.length();
		}
		ofs << replacedLine;
		if (ifs.eof() == true) {
			break ;
		}
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
}

int	main(int argc, char *argv[])
{
	if (argc != 4) {
		if (argc < 4) {
			std::cout << "ft_sed: too few arguments\n";
		} else {
			std::cout << "ft_sed: too many arguments\n";
		}
		return (0);
	}

	string filename(argv[1]);
	string s1(argv[2]);
	string s2(argv[3]);

	ft_sed(filename, s1, s2);
}