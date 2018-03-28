
#ifndef DECLARATION_HPP
#define DECLARATION_HPP


#include "base_expr.hpp"
#include "base_statement.hpp"


class ast_declarator : public ast_base_statement {
public:
    virtual ~ast_declarator();

    virtual std::string get_id() const = 0;

    virtual void xmlprint() const = 0;

    virtual void prettyprint(std::ostream &stream) const = 0;

    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const=  0;

    virtual void allocate_memory(int& allocated_mem) const = 0;

    std::string statement_type() const;
protected:
    ast_identifier* ID;
    std::vector<ast_identifier*> all_ids;

};

extern bool my_global_variable;

class ast_variable_declarator: public ast_declarator {
public:
    ast_variable_declarator(ast_identifier* in_ID);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const ;

    std::string get_id() const ;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

private:

};


class ast_array_declarator : public ast_declarator{
public:
    ast_array_declarator(ast_identifier* in_ID, ast_base_expression* in_expr);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const ;

    std::string get_id() const ;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

private:
    ast_base_expression* inside_expr;
    ast_identifier* ID;
};



class ast_initialisers_declarator : public ast_declarator {
public:
    ast_initialisers_declarator(ast_declarator* in_dec, ast_base_expression* in_equal_expr) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string get_id() const ;

    std::string statement_type() const ;

    void allocate_memory(int& allocated_mem) const ;

    int constant_fold() const ;

private:
    ast_declarator* declarator;
    ast_base_expression* equal_expression;
};



//UGLY HACK FOR GLOBAL VARIABLES!
struct declaration_template
{
    ast_initialisers_declarator* dec;
    int reg_num;
    std::string ID;
    int temp_mem;
};

static std::vector<declaration_template> load_dec;




class ast_declaration : public ast_base_statement {
public:

    ast_declaration(ast_type* in_Type) ;

    ast_declaration(ast_type* in_Type, std::vector<ast_initialisers_declarator*> in_dec) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string statement_type() const ;

    ast_type* return_type() ;

    void allocate_memory(int& allocated_mem) const;

    std::vector<ast_initialisers_declarator*>* return_dec_list();

private:
    ast_type* Type;
    std::vector<ast_initialisers_declarator*> dec_list;
};



class ast_global_declaration : public ast_base_statement {
public:

    ast_global_declaration(ast_declaration* in_decl) ;

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const ; 

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

    std::string statement_type() const ;

    int constant_fold(ast_initialisers_declarator* in_dec) const;

private:
    //Hack
    ast_declaration* decl;
    ast_type* Type;
    std::vector<ast_initialisers_declarator*>* dec_list;
};


#endif //AST_DECLARATION_HPP
