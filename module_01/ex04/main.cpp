#include <fstream>
#include <iostream>
#include <string>

using std::string;

int ft_sed(string &filename, string &s1, string &s2) {
  // setIFS
  std::ifstream ifs(filename);
  if (ifs.is_open() == false) {
    std::cout << "Error\n";
    return 1;
  }

  // setOFS
  std::ofstream ofs(filename + ".replace");
  if (ofs.is_open() == false) {
    std::cout << "Error\n";
    ifs.close();
    return 1;
  }

  if (s1 == s2) {
  // createCopyNoReplaced
    while (1) {
      string line;
      std::getline(ifs, line);
      ofs << line << '\n';
      if (ifs.eof() == true) {
        break;
      }
    }
  } else {
  // createCopyReplaced
    while (1) {
      string replaced_line;
      string origin_line;
      std::getline(ifs, origin_line);
      size_t pos = 0;
      while (1) {
        size_t found_index = origin_line.find(s1, pos);
        if (found_index == string::npos) {
          replaced_line += origin_line.substr(pos, origin_line.length() - pos);
          break;
        }
        if (pos < found_index) {
          replaced_line += origin_line.substr(pos, found_index - pos);
          pos = found_index;
        }
        replaced_line += s2;
        pos += s1.length();
      }
      ofs << replaced_line << '\n';
      if (ifs.eof() == true) {
        break;
      }
    }
  }
  // ~Sed
  ifs.close();
  ofs.close();
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "Error\n" <<
      "usage: ./ft_sed \"filename\" \"string1\" \"string2\"\n";
    return 1;
  }
  string filename(argv[1]);
  string s1(argv[2]);
  string s2(argv[3]);
  int result = ft_sed(filename, s1, s2);
  return result;
}
