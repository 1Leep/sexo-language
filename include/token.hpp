#pragma once
#include <string>

enum TokenType { 
    Invalid,
    Variable,
    Identifier, 
    Assign, 
    String, 
    Number,
    Operator,
    LeftParen,
    RightParen
};

class Token {
public:
  enum TokenType type;
  std::string literal;
  Token(enum TokenType p_type, std::string p_literal);
};
