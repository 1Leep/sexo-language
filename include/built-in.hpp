#pragma once
#include "./visitor.hpp"

void built_in_print(const std::vector<Token> &args, const std::vector<AstNode> &nodes, const AstNode &fn_node);
