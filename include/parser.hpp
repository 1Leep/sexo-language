#pragma once
#include "./ast.hpp"
#include "./lexer.hpp"

class Parser {
public:
  Lexer *lexer;

  Parser(Lexer *p_lexer);
  ~Parser();

  std::vector<Statement> parse();
  Statement parse_value(const Token &identifier, const Token &value, int index);
  const Token get_token(int position = 0, int advance = 0) const;
};
