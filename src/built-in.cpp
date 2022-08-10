#include "../include/built-in.hpp"
#include "../include/error.hpp"

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &nodes, const AstNode& fn_node) {

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
            ass_error_fn_call(arg, fn_node);
        }
        
    } else {
        std::cout << arg.literal << ' ';
    }
  }

  std::cout << '\n';
}
