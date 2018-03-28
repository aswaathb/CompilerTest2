#ifndef TOKENS_HPP
#define TOKENS_HPP

#include <string>
#include "context.hpp"
#include "register_handler.hpp"

const int debug_mode = 0;
//HACK for function calls
extern bool save_math_op;


class ast_identifier{
public:
    ast_identifier(std::string in_ID);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    std::string get_id();

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

private:
	std::string ID;
};


class ast_number {
public:
    ast_number(int in_num);

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    std::string get_id();

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

private:
	int num;
};


class ast_char {
public:
    ast_char(char in_char);
  
    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    std::string get_id();

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

private:
  char my_char;
  int my_char_int;
};


class ast_type {
public:
	ast_type(std::string in_type);
	

    void xmlprint() const;

    void prettyprint(std::ostream &stream) const;

    std::string get_type();

    void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

    void allocate_memory(int& allocated_mem) const;

private:
	std::string Type;
};


class ast_string {
public:
	ast_string(std::string in_str);

	void xmlprint() const;

	void prettyprint(std::ostream &stream) const;

	void generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const;

  void allocate_memory(int& allocated_mem) const;

private:
	std::string Str;
};

#endif

