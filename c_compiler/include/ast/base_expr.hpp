#ifndef BASE_EXPR_HPP
#define BASE_EXPR_HPP

#include "baseNode.hpp"

class ast_base_expression : public ast_base{
public:
    virtual void xmlprint() const =0;
    
    virtual void prettyprint(std::ostream &stream) const =0;

    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;
    
    virtual std::string get_id() const;

    virtual void allocate_memory(int& allocated_mem) const = 0;

    virtual int constant_fold() const = 0;

};

class ast_expression : public ast_base_expression {
public:
	ast_expression();

	void add_new(ast_base_expression* in_expr);

	void xmlprint() const;

	void prettyprint(std::ostream &stream) const;

	void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
	std::vector<ast_base_expression*> all_expr;
};


//HACK
class ast_expression_number : public ast_base_expression {
public:
	ast_expression_number(ast_number* in_num);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string get_id() const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
	ast_number* num;
};



//HACK
class ast_expression_char : public ast_base_expression {
public:
    ast_expression_char(ast_char* in_num);
    
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string get_id() const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
    ast_char* num;
};




class ast_expression_identifier  : public ast_base_expression {
public:
	ast_expression_identifier(ast_identifier* in_ID);
	
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string get_id() const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
	ast_identifier* ID;
};


class ast_expression_string  : public ast_base_expression {
public:
	ast_expression_string(ast_string* in_str);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
	ast_string* my_str;
};


//HACK --> Arrays can only take integers
class ast_expression_array  : public ast_base_expression {
public:
    ast_expression_array(ast_base_expression* in_id, ast_base_expression* in_expr);

    void xmlprint() const;

    std::string get_id() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
    ast_base_expression* id;
    ast_base_expression* expr;
};


class ast_constant_expression : public ast_base_expression {
public:
	ast_constant_expression(ast_base_expression* in_binary_comparison, ast_base_expression* in_expr_1, ast_base_expression* in_expr_2);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
	ast_base_expression* if_expressions;
	ast_base_expression* else_expressions;

	ast_base_expression* binary_comparison;	
};

#endif 
