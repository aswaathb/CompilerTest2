#ifndef ASSIGNMENT_EXPR_HPP
#define ASSIGNMENT_EXPR_HPP

#include "base_expr.hpp"

class ast_assignment_expression : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;

    virtual void prettyprint(std::ostream &stream) const =0;

    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;

    virtual void allocate_memory(int& allocated_mem) const = 0;

    virtual int constant_fold() const = 0;

    virtual std::string get_id() const = 0;

	virtual ~ast_assignment_expression();

protected:
    ast_base_expression *left;
    ast_base_expression *right;

};


class ast_assign_equal : public ast_assignment_expression{
public:
	ast_assign_equal(ast_base_expression *_left, ast_base_expression *_right);

    void xmlprint() const;

    std::string get_id() const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void prettyprint(std::ostream &stream) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;
};





class ast_array_initialiser : public ast_base_expression{
public:
    ast_array_initialiser(std::vector<ast_base_expression*> in_init);

    ast_array_initialiser(ast_base_expression* in_list);

    void xmlprint() const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    std::string get_id() const;

    void prettyprint(std::ostream &stream) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
    std::vector<ast_base_expression*> init_list;
};


class ast_size_of_expr : public ast_base_expression {
public:
    ast_size_of_expr(ast_base_expression* in_expr);

    ast_size_of_expr(ast_type* in_type);

    void xmlprint() const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void prettyprint(std::ostream &stream) const;

    void allocate_memory(int& allocated_mem) const;

    int constant_fold() const;

private:
    ast_base_expression* expr;
    ast_type* type;
};

#endif