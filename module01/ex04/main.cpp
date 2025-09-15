#include <iostream>
#include <fstream>
#include <cstring>
#include <string>



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
  
  std::string oldStr = argv[2];
  std::string newStr = argv[3];
  std::string currentLine;

  while(std::getline(infile, currentLine)) {
    size_t pos = 0;
    while((pos = currentLine.find(oldStr, pos)) != std::string::npos) {
      currentLine.erase(pos, oldStr.length());
      currentLine.insert(pos, newStr);
      pos += newStr.length();
    }
    outfile << currentLine << std::endl;
  }

  infile.close();
  outfile.close();
  return 0;
}

int main(int argc, char **argv) {

  if (argc != 4){
    std::cout << "Usage:" << argv[0] << " <filename>" << " <string to replace>" << " <string to replace with>\n";
    return 0;
  }
  if (argv[2][0] == '\0') {
    std::cerr << "Error: s1 cannot be an empty string." << std::endl;
    return 1;
  }
  return ftSed(argv);
}
