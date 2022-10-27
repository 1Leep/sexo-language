#pragma once
#include "./visitor.hpp"

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &statements, const AstNode &fn_node);
void built_in_read_file(const AstNode &node, const std::vector<AstNode> &statements, std::size_t args_count);
