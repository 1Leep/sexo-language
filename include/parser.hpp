#pragma once
#include "./ast.hpp"
#include "./lexer.hpp"
#include <memory>
 
class Parser {
public:
  std::shared_ptr<Lexer> lexer;

  Parser(std::shared_ptr<Lexer> lexer);
  virtual ~Parser() {};

  std::vector<AstNode> parse();
  AstNode parse_value(const Token &identifier, const Token &value, int index);
  const Token get_token(int position = 0, int advance = 0) const;
  const Token get_previous_token(int position) const;
};
