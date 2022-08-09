#include "../include/visitor.hpp"

void visitor_visit(const std::vector<AstNode> &nodes) {
  for (auto node : nodes) {
    if (node.fn_call.exists)
      visitor_fn_call(node);
  }
}

void visitor_fn_call(const AstNode &node) {
  if (node.fn_call.name == "cumshot") {
    built_in_print(node.fn_call.args);
  }
}

void built_in_print(const std::vector<Token> &args) {
  std::cout << "\x1b[1;32mNYAH ~\x1b[0m ";
  for (auto arg : args) {
    std::cout << arg.literal << " ";
  }
  std::cout << '\n';
}
