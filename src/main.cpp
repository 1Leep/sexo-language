#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include <fstream>
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
  Parser *parser = new Parser(lexer);

  std::vector<Statement> ast_nodes = parser->parse();

  for (auto statement : ast_nodes) {

    if (statement.var.exists) {
      auto value = statement.var.value;

      if (strcmp(value.type().name(), "f") == 0) {
        std::cout << "variable " << statement.var.name
                  << " receives the value: "
                  << std::any_cast<float>(statement.var.value) << '\n';

      } else {
        std::cout << "variable " << statement.var.name
                  << " receives the value: "
                  << std::any_cast<std::string>(statement.var.value) << '\n';
      }
    }
  }

  file.close();
  delete lexer;
  delete parser;
  return 0;
}
