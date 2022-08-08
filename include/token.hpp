#pragma once
#include <string>

enum TokenType { 
    Variable,
    Identifier, 
    Assign, 
    String, 
    Number,
    Operator
};

class Token {
public:
  enum TokenType type;
  std::string literal;
  Token(enum TokenType p_type, std::string p_literal);
};
