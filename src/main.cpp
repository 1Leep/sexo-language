#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include "../include/visitor.hpp"
#include <fstream>
#include <sstream>

int main(int argc, const char *argv[]) {

  std::shared_ptr<Parser> parser;
  std::shared_ptr<Lexer> lexer;

  if (argc > 1) {
    std::ifstream file;
    std::stringstream source;

    file.open(argv[1]);
    if (!file.is_open()) {
      std::cout << "An error occurred!" << '\n';
      return 1;
    }

    source << file.rdbuf();
    lexer = std::make_shared<Lexer>(source.str());
    parser = std::make_shared<Parser>(lexer);

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

      lexer = std::make_shared<Lexer>(source);
      parser = std::make_shared<Parser>(lexer);

      std::vector<AstNode> ast_nodes = parser->parse();
      visitor_visit(ast_nodes);
    }
  }

  return 0;
}
