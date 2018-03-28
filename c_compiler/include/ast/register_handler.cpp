#include "register_handler.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

mips_registers::mips_registers(int total_memory) {
	for (int i =0; i < 32; i++) {
		register_type temp;
		temp.reg_number = i;

		registers.push_back(temp);
	}

	stack_mem = (unsigned)total_memory*2 + 8;
	stack_num = stack_mem/4;

	for (unsigned int i =0; i < stack_num; i++) {
		stack_type temp;
		temp.mem_number = i;

		stack.push_back(temp);
	}
}

//Only for debugging purposes
void mips_registers::get_not_free() {
	for (int i = 8; i <= 25; ++i)
	{
		if (registers[i].reg_value != "") {
			std::cout << "#Register " << i << ": " << "is not free" << std::endl;
			std::cout << "#It has the value: " << registers[i].reg_value << std::endl << std::endl;
		}
	}
}

//HACK!
void mips_registers::reallocate(int current_func) {
	//Dont need to do this with stack??

	if (stack.size() > 0) {
		for (unsigned int i = stack.size()-1; i >0 ; i--) {
			if (stack[i].mem_value != "" && stack[i].mem_value != "temp" && stack[i].mem_number > 4 && current_func == stack[i].function_num) {
				try {
					if (std::stoi(stack[i].mem_value)*4 !=0)
						std::cout << "\tlw $" << stack[i].mem_number << ", " << std::stoi(stack[i].mem_value)*4 << "($fp)" << std::endl;
				}
				catch (...){
					;
				}
			}
		}
	}

	for (unsigned int i = 4; i <= 25; ++i)
	{
		if (registers[i].reg_value != "" && registers[i].reg_value != "temp") {
			std::cout << "\tli $" << i << ", " << registers[i].reg_value << std::endl;
		}
	}
}

int mips_registers::get_free_mem() {

	for (unsigned int i =2; i < stack.size(); i++) {
		
		for (unsigned int n =0; n < function_stack_mem.size(); n++) {
			//std::cout << "#Stack mem:" << function_stack_mem[n] << std::endl;
			if (i == function_stack_mem[n] - 2) {
				i+=3;
				break;
			}
			
		}

		if (stack[i].mem_value == "") {
			return i;
		}
	}


	////First check for an empty register
	//for (int i =8; i <= 25; i++) {
	//	if (registers[i].reg_value == "") {
	//		return i;
	//	}
	//}

	//If not available, check that register will not be used again
	//When exiting scope set all registers used in there to temporary
	std::cout << "Out of stack memory!";
	exit(EXIT_FAILURE);
}

int mips_registers::get_free_reg() {
	//Check for empty registers of the temporary registers -> following convention
	for (int i =8; i <= 25; i++) {
		if (registers[i].reg_value == "") {
			return i;
		}
	}

	//If not available, check that register will not be used again
	//When exiting scope set all registers used in there to temporary
	std::cout << "Out of registers!";
	exit(EXIT_FAILURE);
}

bool mips_registers::write_mem(int reg, std::string val, int in_func) {
	if ((unsigned)reg < stack.size()) {
		stack[reg].mem_value = val;
		stack[reg].function_num = in_func;
		return true;
	}
	return false;

	//if ((reg > 1) && (reg <=25)) {
	//	registers[reg].reg_value = val;
	//	return true;
	//}
	//
	//else
	//	return false;
}

bool mips_registers::write_reg(int reg, std::string val) {
	if ((reg > 1) && (reg <=25)) {
		registers[reg].reg_value = val;
		return true;
	}
	
	else
		return false;
}

int mips_registers::get_value(int reg) {
	try{
		return std::stoi(stack[reg].mem_value)*4;
	}
	catch(std::exception& e){
		std::cout << "Failed to get value of reg: " << reg << std::endl;
		exit(EXIT_FAILURE);
	}

}


void mips_registers::erase_reg(unsigned int reg) {
	if (reg <= registers.size())
		registers[reg].reg_value = "";

	//std::cout << "li $" << reg << ", 0 \t# Resetting register to 0" << std::endl;
}

void mips_registers::erase_mem(unsigned int mem) {
	if (mem <= stack.size())
		stack[mem].mem_value = "";
}

int mips_registers::get_allocated_mem() {
	return stack_mem;
}

void mips_registers::add_stack_mem(unsigned int in_mem){
	function_stack_mem.push_back(((in_mem)/4));
}
