#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include "../include/visitor.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

int main(int argc, const char *argv[]) {

  Lexer *lexer = nullptr;
  Parser *parser = nullptr;

  if (argc > 1) {
    std::ifstream file;
    std::stringstream source;

    file.open(argv[1]);
    if (!file.is_open()) {
      std::cout << "An error occurred!" << '\n';
      return 1;
    }

    source << file.rdbuf();
    lexer = new Lexer(source.str());
    parser = new Parser(lexer);

    std::vector<AstNode> ast_nodes = parser->parse();
    visitor_visit(ast_nodes);

    file.close();

  } else {
    std::string source;
    std::cout << "WelCum to interactive 'Sex Mode' [version 1.0.0]\n"
              << "Type '\x1b[1;35mblowjob()\x1b[0m' to quit\n"
              << '\n';

    while (source != "blowjob()") {
      std::cout << "\x1b[1;35mAWWN ~ \x1b[0m";
      std::getline(std::cin, source);

      lexer = new Lexer(source);
      parser = new Parser(lexer);

      std::vector<AstNode> ast_nodes = parser->parse();
      visitor_visit(ast_nodes);
    }
  }

  delete lexer;
  delete parser;
  return 0;
}
