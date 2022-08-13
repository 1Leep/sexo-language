#include "../include/error.hpp"

void ass_error_fn_call(const Token &arg, const AstNode &fn_node) {
  std::string spaces(fn_node.fn_call.name.size(), ' ');

  std::cout << "\n\x1b[1;31m[ASS_ERROR]: \x1b[0m"
            << "oh yeah daddy, that shit is not defined" << '\n';

  std::cout << "\n¦\n¦" << arg.line << " ->\t" << fn_node.fn_call.name
            << "(..., \x1b[1;32m" << arg.literal << "\x1b[0m)"
            << "\n¦    \t" << spaces << "      ^\n\n"
            << "variable '" << arg.literal << "' at the line " << arg.line
            << '\n';

  exit(EXIT_FAILURE);
}


void ass_error_var_statement(const AstNode &node) {  
  std::string keyword = "dick ";
  std::string spaces(node.var.name.size() + keyword.size(), ' ');

  std::cout << "\n\x1b[1;31m[ASS_ERROR]: \x1b[0m"
            << "oh yeah daddy, that shit is not defined" << '\n';

  std::cout << "\n¦\n¦" << node.var.line << " ->\t" << keyword << node.var.name
            << " = \x1b[1;32m" << std::any_cast<std::string>(node.var.value) << "\x1b[0m"
            << "\n¦    \t" << spaces << "   ^\n\n"
            << "variable '" << std::any_cast<std::string>(node.var.value) << "' at the line " << node.var.line 
            << '\n';

  exit(EXIT_FAILURE);
}


void cum_error_is_missing(const std::string &content, const std::string &target, std::size_t line) {
  std::string spaces(content.size(), ' ');

  std::cout << "\n\x1b[1;31m[CUM_ERROR]: \x1b[0m"
            << "oh fuck! you're so stupid step-brother" << '\n';

  std::cout << "\n¦\n¦" << line << " -> \t" << content << "\x1b[1;31m" << target << "\x1b[0m"
            << "\n¦     \t" << spaces << "^\n\n"
            << "is missing the token '" << target << "' at the line " << line
            << '\n';

  exit(EXIT_FAILURE);
}


void cum_error_unexpected(const std::string &content, const std::string &target, std::size_t line) {
  std::string spaces(content.size(), ' ');

  std::cout << "\n\x1b[1;31m[CUM_ERROR]: \x1b[0m"
            << "I didn't expect that, I'm gonna cum..." << '\n';

  std::cout << "\n¦\n¦" << line << " -> \t" << content << "\x1b[1;31m" << target << "\x1b[0m"
            << "\n¦     \t" << spaces << "^\n\n"
            << "unexpected token '" << target << "' at the line " << line
            << '\n';

  exit(EXIT_FAILURE);
}
