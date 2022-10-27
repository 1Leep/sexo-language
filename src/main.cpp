#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include "../include/visitor.hpp"
#include <sstream>

int main(int argc, const char *argv[]) {
  try {
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
      std::cout << "WelCum to interactive 'Sex Mode'\n"
                << "Type '\x1b[1;35mblowjob()\x1b[0m' to quit\n"
                << '\n';

      while (source != "blowjob()") {
        std::cout << "\x1b[1;35mAWWN ~ \x1b[0m";
        
        if (!std::getline(std::cin, source)) {
          std::cout << '\n';
          break;
        }
        
        lexer = std::make_shared<Lexer>(source);
        parser = std::make_shared<Parser>(lexer);

        std::vector<AstNode> ast_nodes = parser->parse();
        visitor_visit(ast_nodes);
      }
    }
  }
  catch (std::exception &err) {
    if (strcmp(err.what(), "std::bad_alloc") == 0) {
      return 1;
    }
    std::cout << err.what() << '\n';
  }

  return 0;
}
