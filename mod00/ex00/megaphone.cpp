#include <iostream>

void megaphone(char *argv[]) {
  while (*argv) {
    std::string s = *argv;
    for (unsigned int i = 0; i < s.length(); ++i) {
      s[i] = std::toupper(static_cast<unsigned char>(s[i]));
    }
    std::cout << s << " ";
    argv++;
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  if(argc == 1) {
    return 0;
  }
  megaphone(++argv); 
  return 0;
}
