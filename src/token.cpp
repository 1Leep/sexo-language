#include "../include/token.hpp"

Token::Token(enum TokenType p_type, std::string p_literal, std::size_t p_line)
    : type(p_type), literal(p_literal), line(p_line) {}
