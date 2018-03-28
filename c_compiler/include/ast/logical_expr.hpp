
#ifndef LOGICAL_EXPR_HPP
#define LOGICAL_EXPR_HPP

#include "base_expr.hpp"


class ast_logical_expressions : public ast_base_expression{
public:
	virtual void xmlprint() const = 0;
	virtual void prettyprint(std::ostream &stream) const =0;
    virtual void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const = 0;
    virtual void allocate_memory(int& allocated_mem) const = 0;


	virtual ~ast_logical_expressions();


	protected:
	    const ast_base_expression *left;
	    const ast_base_expression *right;

};


class ast_or_comp : public ast_logical_expressions{
public:
	ast_or_comp(const ast_base_expression *_left, const ast_base_expression *_right);
	
    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;
};



class ast_and_comp : public ast_logical_expressions{
public:
	ast_and_comp(const ast_base_expression *_left, const ast_base_expression *_right);
	
    void xmlprint() const ;

    void prettyprint(std::ostream &stream) const;

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    int constant_fold() const ;

    void allocate_memory(int& allocated_mem) const ;
};


#endif 