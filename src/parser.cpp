#include "../include/parser.hpp"
#include "../include/error.hpp"

Parser::Parser(std::shared_ptr<Lexer> p_lexer) : lexer(p_lexer) {}

const Token Parser::get_token(int position, int advance) const {
  return this->lexer->tokens[position + advance];
}

const Token Parser::get_previous_token(int position) const {
    if (position - 1 > 0) {
      return this->lexer->tokens[position - 1];
    } else {
      return this->lexer->tokens[position];
    }
}

std::vector<AstNode> Parser::parse() {
  std::vector<AstNode> nodes;

  for (auto i = 0; i != this->lexer->tokens.size(); ++i) {
    Token current = this->get_token(i);
    
    if (current.type == TokenType::Invalid) {
      cum_error_unexpected(std::string(1, ' '), current.literal, current.line); 

    } else if (current.type == TokenType::Variable) {
      Token identifier = this->get_token(i, 1);
      Token assign     = this->get_token(i, 2);
      Token value      = this->get_token(i, 3);

      if (identifier.type != TokenType::Identifier) {
        cum_error_is_missing(current.literal + " ", std::string("name"), current.line);
      }

      if (assign.type != TokenType::Assign) {
        std::string content = current.literal + " " + identifier.literal + " "; 
        cum_error_is_missing(content, std::string("="), current.line);
      }

      if (value.type != TokenType::Number
              && value.type != TokenType::String
              && value.type != TokenType::Identifier
              && value.type != TokenType::Boobslean) {
        std::string content = current.literal + " " + identifier.literal + " " + assign.literal + " ";
        cum_error_unexpected(content, value.literal, current.line);
      }

      AstNode node = this->parse_value(identifier, value, i + 3);
      nodes.push_back(node);

    } else if (current.type == TokenType::Identifier) {
        Token next_token         = this->get_token(i, 1);
        Token previous_token     = this->get_previous_token(i);
        std::size_t tokens_size  = this->lexer->tokens.size();

        if (next_token.type == TokenType::LeftParen) {
            std::size_t count =  2;
            bool is_over      = false;
            std::vector<Token> args; 

            while(i + count < tokens_size && !is_over) {
                Token tk = this->get_token(i + count);
                switch(tk.type) {
                    case TokenType::Variable:
                    case TokenType::Assign:
                    case TokenType::LeftParen:
                    case TokenType::Invalid:
                        cum_error_unexpected(current.literal + "(..., ", tk.literal, current.line);
                    break;
                    case TokenType::Comma:
                        is_over = false;
                    break;
                    case TokenType::RightParen:
                        is_over = true;
                    break;
                 
                    default:
                        args.push_back(tk);
                }
                ++count;
            }
            
            if (!is_over) {
                std::string content = current.literal + "(...";
                cum_error_is_missing(content, std::string(")"), current.line);
            }

            AstNode node;
            node.fn_call = { current.literal, args, true, current.line };
            nodes.push_back(node);
        } 

    }
  }

  return nodes;
}

AstNode Parser::parse_value(const Token &identifier, const Token &value, int index) {
  AstNode node;

  if (value.type == TokenType::Number) {
    Token op = this->get_token(index, 1);

    if (op.type == TokenType::Operator) {
        float result;
        Token right_hand = this->get_token(index, 2);

        if (right_hand.type != TokenType::Number) {
            std::string content = "dick " + identifier.literal
                         + " = " + value.literal + " " + op.literal + " "; 
            cum_error_unexpected(content, right_hand.literal, value.line);
        } 
        
        if (op.literal == "+") result = std::stof(value.literal) + std::stof(right_hand.literal);
        else if (op.literal == "-") result = std::stof(value.literal) - std::stof(right_hand.literal);
        else if (op.literal == "/") result = std::stof(value.literal) / std::stof(right_hand.literal);
        else if (op.literal == "*") result = std::stof(value.literal) * std::stof(right_hand.literal);
        
        node.var = { identifier.literal, result, true };
    } else {
        node.var = { identifier.literal, std::stof(value.literal), true };
    }

  } else if (value.type == TokenType::String || value.type == TokenType::Boobslean) {
      node.var = { identifier.literal, value.literal, true };

  } else if (value.type == TokenType::Identifier) {
    node.var = { identifier.literal, value.literal, true, true, identifier.line };

  } else { 
    std::string content = "dick " + identifier.literal + " = ";
    cum_error_unexpected(content, value.literal, value.line);
  }

  return node;
}


