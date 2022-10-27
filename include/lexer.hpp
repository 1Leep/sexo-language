#pragma once

#include "./token.hpp"
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>

bool is_numeric(const std::string &s);

class Lexer {
public:
  std::vector<char> source;
  std::size_t counter;
  std::size_t line;
  std::vector<Token> tokens;

  Lexer(const std::string &p_source);
  virtual ~Lexer() {}

  void lex();
  const char current_char() const;
  void advance();
};
