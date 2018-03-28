#ifndef IFELSE_STATEMENT_HPP
#define IFELSE_STATEMENT_HPP

#include "base_statement.hpp"
#include "binary_operators.hpp"
#include "compound_statement.hpp"
#include "logical_expr.hpp"



class ast_if_else_statement : public ast_base_statement{
public:
    ast_if_else_statement(ast_base_expression* in_binary_comparison);

    void push_back_if(ast_base_statement* in_expr) ;

    void push_back_else(ast_base_statement* in_expr) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const;

private:
    ast_base_statement* if_expressions;
    ast_base_statement* else_expressions;

    ast_base_expression* binary_comparison; 
};


#endif 

