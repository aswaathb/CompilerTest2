#ifndef FORWHILE_STATEMENT_HPP
#define FORWHILE_STATEMENT_HPP

#include "base_expr.hpp"
#include "base_statement.hpp"
#include "binary_operators.hpp"
#include "declaration.hpp"
#include "logical_expr.hpp"

//Not an optimising compiler, uses nop's everytime a delay slot is encountered.

class ast_loops : public ast_base_statement {
public:
    virtual ~ast_loops() ;
    virtual void xmlprint() const = 0;
    virtual void allocate_memory(int& allocated_mem) const = 0;
};

class ast_for_statement : public ast_loops {
public:
    ast_for_statement(ast_base_expression* in_condition, ast_base_expression* in_bin_op, ast_base_statement* stat) ;

    ast_for_statement(ast_base_expression* in_condition, ast_base_expression* in_bin_op, ast_base_expression* in_base_expr, ast_base_statement* stat) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const ;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

private:
    ast_base_expression* bin_op;
    ast_base_expression* base_expr;
    ast_base_statement* statement;
    ast_base_expression* first_condition;
};



class ast_while_statement : public ast_loops {
public:

    ast_while_statement(ast_base_expression* in_comparison, ast_base_statement* in_stat, bool in_do_while) ;

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;


private:
    ast_base_expression* comparison;
    ast_base_statement* statement;
    bool do_while;
};


#endif