#include "../include/parser.hpp"

Parser::Parser(Lexer *p_lexer) : lexer(p_lexer) {}
Parser::~Parser() { delete this->lexer; }

Statement Parser::parse_expression(const Token &identifier,
                                   const Token &expression) {
  Statement st;
  if (expression.type == TokenType::Number) {
    st.var = {identifier.literal, std::stof(expression.literal), true};
  } else {
    st.var = {identifier.literal, expression.literal.c_str(), true};
  }

  return st;
}

std::vector<Statement> Parser::parse() {
  std::vector<Statement> statements;

  for (auto i = 0; i != this->lexer->tokens.size(); ++i) {
    Token current = this->lexer->tokens[i];
    auto next = [&](int count = 1) -> Token {
      return this->lexer->tokens[i + count];
    };

    switch (current.type) {
    case TokenType::Variable: {

      Token identifier = next();

      if (identifier.type != TokenType::Identifier) {
        std::cout << "[Syntax Error] Expected an Identifier" << '\n';
        exit(EXIT_FAILURE);
      }

      if (next(2).type != TokenType::Assign) {
        std::cout << "[Syntax Error] Expected an '=' assign symbol" << '\n';
        exit(EXIT_FAILURE);
      }

      Statement st = this->parse_expression(identifier, next(3));
      statements.push_back(st);

      break;
    }
    }
  }

  return statements;
}
