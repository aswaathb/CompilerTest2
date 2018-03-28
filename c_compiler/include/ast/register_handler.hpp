#ifndef REGISTER_HANDLER_HPP
#define REGISTER_HANDLER_HPP

#include <vector>
#include <string>


struct register_type {
	int reg_number;
	std::string reg_value;
};

struct stack_type {
	int function_num;
	int mem_number;
	std::string mem_value;
};

class mips_registers {

public:
	mips_registers(int total_memory);

//Only for debugging purposes
	void get_not_free();

//HACK!
	void reallocate(int current_func);

	int get_free_mem();

	int get_free_reg();

	bool write_mem(int reg, std::string val, int in_func);

	bool write_reg(int reg, std::string val);

	int get_value(int reg);

	void erase_reg(unsigned int reg) ;

	void erase_mem(unsigned int mem) ;

	int get_allocated_mem();

	void add_stack_mem(unsigned int in_mem);

private:
	std::vector<register_type> registers;
	std::vector<stack_type> stack;
	unsigned int stack_mem;
	unsigned int stack_num;

//HACK! Stack memory to avoid...
	std::vector<unsigned int> function_stack_mem;

};


#endif