#pragma once
#include "./lexer.hpp"
#include <any>

struct VarStatement {
  std::string name;
  std::any value;
  bool exists = false;
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
