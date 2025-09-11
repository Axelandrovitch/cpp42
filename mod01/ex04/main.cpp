#include <iostream>
#include <fstream>
#include <cstring>

int ftSed(char **argv) {

  std::ifstream infile(argv[1]);

  if (!infile) {
    std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return errno;
  }

  std::string outFileName = std::string(argv[1]) + ".replace";
  std::ofstream outfile(outFileName.c_str());

  if (!outfile) {
    std::cerr << "Error: " << std::strerror(errno) << std::endl;
    return errno;
  }
  outfile << "Hello World!\nFrom outfile.txt\n";
  
  return 0;
}

int main(int argc, char **argv) {

  if (argc != 4){
    std::cout << "Usage:" << argv[0] << " <filename>" << " <string to replace>" << " <string to replace with>\n";
    return 0;
  }

  return ftSed(argv);
}
