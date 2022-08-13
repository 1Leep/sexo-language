#pragma once
#include "./lexer.hpp"
#include <any>

struct VarStatement {
  std::string name;
  std::any value;
  bool exists = false;
  bool is_value_var = false;
  std::size_t line = 0;
};

struct FunctionCall {
  std::string name;
  std::vector<Token> args;
  bool exists = false;
};

struct AstNode {
  VarStatement var;
  FunctionCall fn_call;
};
