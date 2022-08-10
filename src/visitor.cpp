#include "../include/visitor.hpp"
#include "../include/built-in.hpp"

void visitor_visit(const std::vector<AstNode> &nodes) {
  for (auto node : nodes) {
    if (node.fn_call.exists) visitor_fn_call(node, nodes);
  }
}

void visitor_fn_call(const AstNode &node, const std::vector<AstNode> &nodes) {
  if (node.fn_call.name == "cumshot") {
    built_in_print(node.fn_call.args, nodes, node);
  }
}


