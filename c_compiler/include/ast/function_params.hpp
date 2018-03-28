
#ifndef FUNCTION_PARAMS_HPP
#define FUNCTION_PARAMS_HPP

#include "declaration.hpp"

class ast_function_parameters : public ast_base {
public:
    ast_function_parameters(ast_type* in_type, ast_declarator* in_ID) ;

    //~ast_function_parameters() ;

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const ;

    std::string get_id() ;

    void allocate_memory(int& allocated_mem) const ;

private:
	ast_type* Type;
    ast_declarator* ID;
};



class ast_function_declarator: public ast_declarator {
public:
    ast_function_declarator(ast_identifier* in_ID, std::vector<ast_function_parameters*> in_parameters) ;

    ast_function_declarator(ast_identifier* in_ID) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string get_id() const ;

    void allocate_memory(int& allocated_mem) const;

private:
    std::vector<ast_function_parameters*> all_parameters;
};

#endif 