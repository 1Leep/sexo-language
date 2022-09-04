#pragma once
#include "../include/ast.hpp"
#include <exception>
#include <sstream>

void ass_error_fn_call(const Token &arg, const AstNode &fn_node);
void ass_error_var_statement(const AstNode &node); 
void cum_error_is_missing(const std::string &content, const std::string &target, std::size_t line);
void cum_error_unexpected(const std::string &content, const std::string &target, std::size_t line);
