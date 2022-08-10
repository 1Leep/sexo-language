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
  RightParen,
  Comma
};

class Token {
public:
  enum TokenType type;
  std::string literal;
  std::size_t line;

  Token(enum TokenType p_type, std::string p_literal, std::size_t p_line);
};
