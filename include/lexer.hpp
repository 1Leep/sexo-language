#pragma once

#include "./token.hpp"
#include <ctype.h>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

class Lexer {
public:
  std::vector<char> source;
  std::size_t counter;

  Lexer(const std::string &p_source);
  void lex();
  const char current_char() const;
};

bool is_numeric(const std::string &s);
