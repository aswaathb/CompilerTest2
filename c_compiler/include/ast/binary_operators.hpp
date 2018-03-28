#ifndef BINARY_OPERATORS_HPP
#define BINARY_OPERATORS_HPP

#include "base_expr.hpp"

class ast_binary_operators : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;
    virtual void prettyprint(std::ostream &stream) const =0;
    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;
    virtual void allocate_memory(int& allocated_mem) const = 0;
    virtual int constant_fold() const = 0;

	virtual ~ast_binary_operators();

	const ast_base_expression* get_left() const;

	const ast_base_expression* get_right() const;

private:
    const ast_base_expression *left;
    const ast_base_expression *right;

protected:
    ast_binary_operators(const ast_base_expression *_left, const ast_base_expression *_right);
};

class ast_less_comp : public ast_binary_operators{
public:
	ast_less_comp(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;


    int constant_fold() const;


    void allocate_memory(int& allocated_mem) const;

};


class ast_less_equal_comp : public ast_binary_operators{
public:
	ast_less_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right);
	
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const;

    void allocate_memory(int& allocated_mem) const;
};


class ast_greater_comp : public ast_binary_operators{
public:
	ast_greater_comp(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const;

    void allocate_memory(int& allocated_mem) const;
};


class ast_greater_equal_comp : public ast_binary_operators{
public:
	ast_greater_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right);
	
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const;

    void allocate_memory(int& allocated_mem) const;
};


class ast_equal_comp : public ast_binary_operators{
public:
	ast_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right);
	
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const;

    void allocate_memory(int& allocated_mem) const;
};


class ast_not_equal_comp : public ast_binary_operators{
public:
	ast_not_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right);
	
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const;

    void allocate_memory(int& allocated_mem) const;
};

#endif 