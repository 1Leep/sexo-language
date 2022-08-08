#include "../include/parser.hpp"

Parser::Parser(Lexer *p_lexer) : lexer(p_lexer) {}
Parser::~Parser() { delete this->lexer; }


Statement Parser::parse_value(const Token &identifier, const Token &value, int index) {
  Statement st;

  if (value.type == TokenType::Number) {
    Token op = this->get_token(index, 1);

    if (op.type == TokenType::Operator) {
        float result;
        Token right_hand = this->get_token(index, 2);

        if (right_hand.type != TokenType::Number) {
            std::cout << "Unexpected right-hand valid value" << '\n';
            exit(EXIT_FAILURE);
        } 
        
        if (op.literal == "+") result = std::stof(value.literal) + std::stof(right_hand.literal);

        st.var = { identifier.literal, result, true };
    } else {
        st.var = { identifier.literal, std::stof(value.literal), true };
    }

  } else {
      st.var = { identifier.literal, value.literal.c_str(), true };
  }

  return st;
}


const Token Parser::get_token(int position, int advance) const {
  return this->lexer->tokens[position + advance];
}


std::vector<Statement> Parser::parse() {
  std::vector<Statement> statements;

  for (auto i = 0; i != this->lexer->tokens.size(); ++i) {
    Token current = this->get_token(i);

    if (current.type == TokenType::Variable) {
      Token identifier = this->get_token(i, 1);
      Token assign     = this->get_token(i, 2);
      Token value      = this->get_token(i, 3);

      if (identifier.type != TokenType::Identifier) {
        std::cout << "Expected an Identifier" << '\n';
        exit(EXIT_FAILURE);
      }

      if (assign.type != TokenType::Assign) {
        std::cout << "Expected an '=' assign symbol" << '\n';
        exit(EXIT_FAILURE);
      }

      if (value.type != TokenType::Number && value.type != TokenType::String) {
        std::cout << "Expected a valid value type\ngot the type " << value.type
                  << '\n';
        exit(EXIT_FAILURE);
      }

      Statement st = this->parse_value(identifier, value, i + 3);
      statements.push_back(st);
    }
  }

  return statements;
}
