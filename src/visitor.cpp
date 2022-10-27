#include "../include/visitor.hpp"
#include "../include/built-in.hpp"
#include "../include/error.hpp"

std::vector<AstNode> vars;

void visitor_visit(const std::vector<AstNode> &nodes) {
  for (auto &node : nodes) {
    if (node.fn_call.exists) visitor_fn_call(node);
    if (node.var.exists) {
      vars.push_back(node);
      visitor_var_statement(node);
    }
  }
}

void visitor_fn_call(const AstNode &node) {
  if (node.fn_call.name == "cumshot") {
    built_in_print(node.fn_call.args, vars, node);
  }

  if (node.fn_call.name == "handjob") {
    built_in_read_file(node, vars, 1);
  }
}

void visitor_var_statement(const AstNode &node) {
  if (node.var.is_value_var) {
    auto it_found_value = std::find_if(
        vars.begin(), vars.end(), [&](const AstNode &target) -> bool {
          return target.var.name == std::any_cast<std::string>(node.var.value);
        });

    if (it_found_value != vars.end()) {
      auto it_found_main = std::find_if(
          vars.begin(), vars.end(), [&](const AstNode &target) -> bool {
            return target.var.name == node.var.name;
          });

      it_found_main->var.value = it_found_value->var.value;
    } else {
        ass_error_var_statement(node);
    }
  }
}
