#ifndef MATH_OPERATORS_HPP
#define MATH_OPERATORS_HPP

#include "base_expr.hpp"
#include <exception>

class ast_math_operators : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;
    virtual void prettyprint(std::ostream &stream) const = 0;

    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;
    virtual void allocate_memory(int& allocated_mem) const = 0;

    virtual int constant_fold() const = 0;

	virtual ~ast_math_operators()
	;

    const ast_base_expression* get_left() const ;
    const ast_base_expression* get_right() const ;
private:
    const ast_base_expression *left;
    const ast_base_expression *right;

protected:
    ast_math_operators(const ast_base_expression *_left, const ast_base_expression *_right);
};


class ast_add_operator : public ast_math_operators{
public:
	ast_add_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;

};


class ast_subtract_operator : public ast_math_operators{
public:
	ast_subtract_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;

};


class ast_multiply_operator : public ast_math_operators{
public:
	ast_multiply_operator(const ast_base_expression *_left, const ast_base_expression *_right);
	//~ast_if_else_statement() ;

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;
};


class ast_divide_operator : public ast_math_operators{
public:
	ast_divide_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;

};


class ast_bitwise_and_operator : public ast_math_operators{
public:
    ast_bitwise_and_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;

};

class ast_bitwise_or_operator : public ast_math_operators{
public:
    ast_bitwise_or_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;

};

class ast_bitwise_xor_operator : public ast_math_operators{
public:
    ast_bitwise_xor_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;
};

class ast_bitwise_modulo_operator : public ast_math_operators{
public:
    ast_bitwise_modulo_operator(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;


    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;
};


class ast_left_shift_bit : public ast_math_operators{
public:
    ast_left_shift_bit(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;
};


class ast_right_shift_bit : public ast_math_operators{
public:
    ast_right_shift_bit(const ast_base_expression *_left, const ast_base_expression *_right);

    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const ;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const;

    void allocate_memory(int& allocated_mem) const ;
};

#endif 


