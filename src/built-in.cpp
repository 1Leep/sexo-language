#include "../include/built-in.hpp"
#include "../include/error.hpp"

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &statements, const AstNode& fn_node) {

  if (args.size() < 1) {
      ass_error_arg_required(fn_node, 1);
  }

  for (auto arg : args) {
    if (arg.type == TokenType::Identifier) {

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
