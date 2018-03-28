
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <vector>
#include <iostream>
#include <cstdlib>

struct symbol_vector {
	std::string symbol_id;
	std::string symbol_type;
	int reg_num;
};

struct scope_symbol_table {
	std::string scope_ID; 	//The name of the parent function
	std::string scope_type; 		//The type of the scope: e.g. if, while, for
	std::vector<symbol_vector*> all_symbols;	//All symbols within the scope
};

class ast_context {
public:

	ast_context(std::ostream &in_stream);

	void enter_subroutine ();
	
	//Exiting the current subroutine
	void exit_subroutine ();

	//Inserting a symbol
	//Returns true if inserted, returns false if found before --> i.e. need to overwrite
	bool insert_symbols(std::string in_type, std::string in_id, int in_reg, bool declaration);

	//Creating a new scope
	void make_scope(std::string in_id, std::string in_scope_type, int mem_needed);

	//Exiting the scope
	void exit_scope();

	void exit_function_scope();

	int find_variable(std::string in_id);

	std::ostream& get_stream();

	std::string make_label(std::string base);

	void flush_parameters();

	void insert_global(std::string in_type, std::string in_id, int in_reg);

	void insert_param_id(unsigned int param_num, std::string id);

	std::string get_param_id(unsigned int param_num);

	std::string insert_break();

	std::string get_break();

	int get_current_func();

private:

	std::vector<symbol_vector*> global_variables;

//TODO: Fix, not very nice structure
	std::vector<std::string> parameters_ids;

	//Global Symbol table
	std::vector<scope_symbol_table*> symbol_table;

	unsigned int current_scope_depth; //What the depth of the current scope is

	std::ostream &stream;

	int makeNameUnq;

	int stack_mem;

	int break_number;

	int function_num;
	
};


#endif