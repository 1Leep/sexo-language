#include "../include/visitor.hpp"

void visitor_visit(const std::vector<AstNode> &nodes) {
  for (auto node : nodes) {
    if (node.fn_call.exists) visitor_fn_call(node, nodes);
  }
}

void visitor_fn_call(const AstNode &node, const std::vector<AstNode> &nodes) {
  if (node.fn_call.name == "cumshot") {
    built_in_print(node.fn_call.args, nodes);
  }
}

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &nodes) {
  std::cout << "\x1b[1;32mNYAH ~\x1b[0m ";

  for (auto arg : args) {
    if (arg.type == TokenType::Identifier) {
        std::vector<AstNode> statements;
    
        for (auto node : nodes) {
            if (node.var.exists) statements.push_back(node);
        }
    
        auto it_found = std::find_if(statements.begin(), statements.end(), [&](const AstNode &p_statement) -> bool {
            return p_statement.var.name == arg.literal;
        });
        
        if (it_found != statements.end()) {
            (strcmp(it_found->var.value.type().name(), "f") == 0) 
                ? std::cout << std::any_cast<float>(it_found->var.value) << ' '
                : std::cout << std::any_cast<std::string>(it_found->var.value) << ' ';
        } else {
            std::cout << arg.literal << " is not defined" << '\n';
            exit(EXIT_FAILURE);
        }
        
    } else {
        std::cout << arg.literal << ' ';
    }
  }

  std::cout << '\n';
}
