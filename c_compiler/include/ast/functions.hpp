#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "baseNode.hpp"
#include "compound_statement.hpp"
#include "function_params.hpp"

#include <cmath>

class ast_function : public ast_base
{
private:
    std::vector<ast_function_parameters*> ast_parameters;
    ast_compound_statement* statements;
    ast_type* return_type;
    ast_identifier* ID;

public:
    ast_function(ast_type* in_return_type, ast_identifier* in_id, std::vector<ast_function_parameters*> in_params, ast_compound_statement* in_stat) ;

    ast_function(ast_type* in_return_type, ast_identifier* in_id, ast_compound_statement* in_stat) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void allocate_memory(int& allocated_mem) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

};


//Store memory location before moving from $8 to $2
struct recursion_template
{
    int mem;
    int reg;
};

static std::vector<recursion_template> func_call_store;


class ast_function_call : public ast_base_expression
{
private:
    std::vector<ast_base_expression*> args_list;
    ast_identifier* ID;

public:
    ast_function_call(ast_identifier* in_ID, std::vector<ast_base_expression*> in_args_list) ;

    ast_function_call(ast_identifier* in_ID) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const;

};

#endif