#pragma once
#include "./lexer.hpp"
#include <any>

struct VarStatement {
  std::string name;
  std::any value;
  bool exists;
};

struct Statement {
  VarStatement var;
};
