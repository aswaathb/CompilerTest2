#ifndef COMPOUND_STATEMENT_HPP
#define COMPOUND_STATEMENT_HPP

#include "base_statement.hpp"

class ast_statement_list : public ast_base_statement{
public:
    ast_statement_list();

    void add_new(ast_base_statement* in_stat) ;

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;


    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const ;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ; 

private:
    std::vector<ast_base_statement*> all_statements;

};

class ast_compound_statement : public ast_base_statement{
public:
    ast_compound_statement(ast_statement_list* in_stat);

    ast_compound_statement();

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const ;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

private:
    ast_statement_list* all_statements;

    bool empty_function;
};



#endif 
