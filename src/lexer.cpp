#include "../include/lexer.hpp"

Lexer::Lexer(const std::string &p_source) {
  this->source = std::vector<char>(p_source.begin(), p_source.end());
  this->counter = 0;
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

      while (this->current_char() != c) {
        if (this->current_char() == '\\') {
          this->counter += 1;
        }
        s.push_back(this->current_char());
        this->counter += 1;
      }

      tokens.push_back(Token(TokenType::String, s));
      this->counter += 1;

    } else if (isalnum(c)) {
      std::string s;
      s.push_back(this->current_char());
      this->counter += 1;

      while (this->current_char() != ' ' && this->current_char() != '\n') {
        s.push_back(this->current_char());
        this->counter += 1;
      }

      if (s == "cum") {
        tokens.push_back(Token(TokenType::Variable, s));
      } else if (is_numeric(s)) {
        tokens.push_back(Token(TokenType::Number, s));
      } else {
        tokens.push_back(Token(TokenType::Identifier, s));
      }
      this->counter += 1;

    } else if (c == '#') {
      while (this->current_char() != '\n' && this->current_char() != '\0') {
        this->counter += 1;
      }

    } else {
      this->counter += 1;
    }
  }

  this->tokens = tokens;
}

bool is_numeric(const std::string &s) {
  std::regex r(R"(^^\s*[-+]?((\d+(\.\d+)?)|(\d+\.)|(\.\d+))(e[-+]?\d+)?\s*$)");
  return std::regex_match(s, r);
}
