#pragma once
#include "./visitor.hpp"

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &statements, const AstNode &fn_node);
