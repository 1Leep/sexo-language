#pragma once
#include "./ast.hpp"
#include "./lexer.hpp"

class Parser {
public:
  Lexer *lexer;

  Parser(Lexer *p_lexer);
  ~Parser();

  std::vector<Statement> parse();
  Statement parse_expression(const Token &identifier, const Token &expression);
};
