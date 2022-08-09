#include "./ast.hpp"

void visitor_visit(const std::vector<AstNode> &nodes);
void visitor_fn_call(const AstNode &node);
void built_in_print(const std::vector<Token>& args);
