#pragma once
#include "./ast.hpp"

void visitor_visit(const std::vector<AstNode> &nodes);
void visitor_fn_call(const AstNode &node);
void visitor_var_statement(const AstNode &node);
