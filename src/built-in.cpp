#include "../include/built-in.hpp"
#include "../include/error.hpp"

const char* any_string_literal = "NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE";

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &statements, const AstNode& fn_node) {

  if (args.size() < 1) {
      ass_error_arg_required(fn_node, 1);
  }

  for (auto &arg : args) {
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


void built_in_read_file(const AstNode &node, const std::vector<AstNode> &statements, std::size_t args_count) {
    if (node.fn_call.args.size() != args_count) {
        std::cout << "this function receives only " << args_count << " arguments" << '\n';
        exit(EXIT_FAILURE);
    }

    std::string file_path;

    for (auto &arg : node.fn_call.args) {
        if (arg.type == TokenType::Identifier) {
            auto it_found = std::find_if(statements.begin(), statements.end(), [&](const AstNode &p_stament) -> bool {
                return p_stament.var.name == arg.literal;
            });

            if (it_found != statements.end()) {
              if (strcmp(it_found->var.value.type().name(), any_string_literal) == 0) {
                file_path = std::any_cast<std::string>(it_found->var.value);
              } else {
                 std::cout << "this argument must be a string" << '\n';
                 exit(EXIT_FAILURE);
              }
            } else {
                ass_error_fn_call(arg, node);
            }

        } else if (arg.type == TokenType::String) {
            file_path = arg.literal;
        } else {
            std::cout << "this argument must be a string" << '\n';
            exit(EXIT_FAILURE);
        }
    }

    std::ifstream file(file_path);
    
    if (!file.is_open()) {
        std::cout << "cannot find the file \"" << file_path << '\"' << '\n';
        exit(EXIT_FAILURE);
    }

    std::cout << file.rdbuf() << '\n';
    file.close();
}
