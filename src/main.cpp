#include "../include/lexer.hpp"
#include "../include/parser.hpp"
#include "../include/visitor.hpp"
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

  std::vector<AstNode> ast_nodes = parser->parse();

  // PRINTING DEBUG INFO:
 /* for (auto node : ast_nodes) {

    if (node.var.exists) {
      auto value = node.var.value;

      if (strcmp(value.type().name(), "f") == 0) {
        std::cout << "variable " << node.var.name << " receives the value: "
                  << std::any_cast<float>(node.var.value) << '\n';

      } else {
        std::cout << "variable " << node.var.name << " receives the value: "
                  << std::any_cast<std::string>(node.var.value) << '\n';
      }

    } else if (node.fn_call.exists) {
      std::cout << "function " << node.fn_call.name << " receives the args: ( ";
      for (auto token : node.fn_call.args) {
        std::cout << token.literal << " ";
      }
      std::cout << ")\n" << node.fn_call.args.size() << " arguments" << '\n';
    }
  }
*/
  //-------------------------

  visitor_visit(ast_nodes);

  file.close();
  delete lexer;
  delete parser;
  return 0;
}
