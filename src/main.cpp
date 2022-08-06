#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, const char *argv[]) {

  std::ifstream file;
  std::stringstream source;

  if (argc < 2) {
    std::cout << "too few arguments!" << '\n';
    return 1;
  }

  file.open(argv[1]);
  if (!file.is_open()) {
    std::cout << "An error occurred!" << '\n';
    return 1;
  }

  source << file.rdbuf();

  Lexer *lexer = new Lexer(source.str());

  for (auto token : lexer->tokens) {
    std::cout << "LITERAL: " << token.literal << "\t\t| TYPE: " << token.type
              << '\n';
  }

  file.close();
  delete lexer;
  return 0;
}
