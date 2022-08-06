#include "../include/token.hpp"

Token::Token(enum TokenType p_type, std::string p_literal)
    : type(p_type), literal(p_literal) {}
