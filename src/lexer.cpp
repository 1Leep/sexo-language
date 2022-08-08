#include "../include/lexer.hpp"

Lexer::Lexer(const std::string &p_source) {
  this->source = std::vector<char>(p_source.begin(), p_source.end());
  this->counter = 0;
  this->lex();
}

bool is_numeric(const std::string &s) {
  std::regex r(R"(-?[0-9]+([\.][0-9]+)?)");
  return std::regex_match(s, r);
}

const char Lexer::current_char() const { return this->source[this->counter]; }

void Lexer::lex() {
  std::vector<Token> tokens;

  while (this->source.size() > this->counter) {
    char c = this->current_char();

    if (c == '=') {
      tokens.push_back(Token(TokenType::Assign, "="));
      this->counter += 1;

    } else if (c == '\'' || c == '"') {
      std::string s;
      this->counter += 1;

      while (this->current_char() != c && this->current_char() != '\n' &&
             this->current_char() != '\0') {
        if (this->current_char() == '\\') {
          this->counter += 1;
        }
        s.push_back(this->current_char());
        this->counter += 1;
      }

      if (this->current_char() == c) {
        tokens.push_back(Token(TokenType::String, s));
      } else {
        tokens.push_back(Token(TokenType::Invalid, s));
      }
      this->counter += 1;

    } else if (c == '(') {
      tokens.push_back(Token(TokenType::LeftParen, "("));
      this->counter += 1;

    } else if (c == ')') {
      tokens.push_back(Token(TokenType::RightParen, ")"));
      this->counter += 1;

    } else if (c == ',') {
      tokens.push_back(Token(TokenType::Comma, ","));
      this->counter += 1;

    } else if (isalnum(c)) {
      std::string s;
      s.push_back(this->current_char());
      this->counter += 1;

      while ((this->current_char() != ' ' && this->current_char() != '\n' &&
              isalnum(this->current_char())) ||
             (this->current_char() == '.' || this->current_char() == '_')) {

        s.push_back(this->current_char());
        this->counter += 1;
      }

      if (s == "dick") {
        tokens.push_back(Token(TokenType::Variable, s));
      } else if (is_numeric(s)) {
        tokens.push_back(Token(TokenType::Number, s));
      } else {
        tokens.push_back(Token(TokenType::Identifier, s));
      }

    } else if (c == '#') {
      while (this->current_char() != '\n' && this->current_char() != '\0') {
        this->counter += 1;
      }

    } else if (c == '+' || c == '-' || c == '/' || c == '*') {
      std::string str(1, c);
      tokens.push_back(Token(TokenType::Operator, str));
      this->counter += 1;

    } else if (c == ' ' || c == '\n') {
      this->counter += 1;

    } else {
      std::string str(1, c);
      tokens.push_back(Token(TokenType::Invalid, str));
      this->counter += 1;
    }
  }

  // PRINT FOR DEBUGGING
  /*
    const char* token_types_list[10] = {
      "(INVALID)", "(VARIABLE)", "(IDENTIFIER)",
      "(ASSIGN)", "(STRING)", "(NUMBER)",
      "(OPERATOR)", "(L_PAREN)", "(R_PAREN)",
      "(COMMA)"
    };

    for (auto t : tokens) {
      std::cout << "LITERAL: " << t.literal
                << "\t\t¦ TYPE: " << token_types_list[t.type] << '\n';
    }
  */

  //-----------------
  this->tokens = tokens;
}
