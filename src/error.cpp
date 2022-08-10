#include "../include/error.hpp"

void ass_error_fn_call(const Token &arg, const AstNode &fn_node) {
  std::string spaces(fn_node.fn_call.name.size(), ' ');

  std::cout << "\x1b[1;31m[ASS_ERROR]: \x1b[0m"
            << "oh yeah daddy, that shit is not defined" << '\n';

  std::cout << "\n¦\n¦" << arg.line << " ->\t" << fn_node.fn_call.name
            << "(..., \x1b[1;32m" << arg.literal << "\x1b[0m)"
            << "\n¦    \t" << spaces << "      ^\n\n"
            << "variable '" << arg.literal << "' at the line " << arg.line
            << '\n';

  exit(EXIT_FAILURE);
}
