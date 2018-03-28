#include "tokens.hpp"

ast_identifier::ast_identifier(std::string in_ID) {
	ID = in_ID;
}

void ast_identifier::xmlprint() const {
	std::cout << ID;
}

void ast_identifier::prettyprint(std::ostream &stream) const {
	stream << ID;
}

std::string ast_identifier::get_id() {
	return ID;
}

void ast_identifier::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
      int value = context->find_variable(ID);

      if (debug_mode) {
        context->get_stream() << "#This is an identifier with ID: " << ID << std::endl;;
        context->get_stream() << "#Assigning to reg: " << dest_reg << std::endl << std::endl;
      }

      if (value == -1) {
        context->get_stream() << "VARIABLE NOT DEFINED WITHIN SCOPE" << std::endl;
      	exit(EXIT_FAILURE);
      }
      else if (value == -2) {
        //value = registers->get_free();

        context->get_stream() << "\tmove $" << dest_reg << ", $2" << std::endl;

        context->get_stream() << "\t#-2 global variable: new value " << value << std::endl;
      }
      else {
        context->get_stream() << "\tlw $" << dest_reg << ", " << value*4 << "($fp)\t# Moving value from destination register where variable is stored" << std::endl;

        registers->write_mem(dest_reg, std::to_string(value), context->get_current_func());
      }
}

void ast_identifier::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}


ast_number::ast_number(int in_num) {
   num = in_num;
}
	

void ast_number::xmlprint() const{
	std::cout << num;
}

void ast_number::prettyprint(std::ostream &stream) const {
	stream << num;
}

std::string ast_number::get_id() {
    return std::to_string(num);
}

void ast_number::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (debug_mode) {
      context->get_stream() << "#This is a number with value: " << num << std::endl;;
      context->get_stream() << "#Assigning to reg: " << dest_reg << std::endl << std::endl;
      }

	if (num > 65536) {
        context->get_stream() << "\tli $" << dest_reg << ", "<<65536 << "\t# Decimal, because number too big:" << 65536 << std::endl;
        context->get_stream() << "\tori $" << dest_reg << ", $"<< dest_reg << ", " << num - 65536 << "\t# Xoring the difference" << 65536 << std::endl;
    }
    else {
        context->get_stream() << "\tli $" << dest_reg << ", "<< num << "\t# Decimal:" << num << std::endl;
    }

    registers->write_reg(dest_reg, std::to_string(num));

}

void ast_number::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}



ast_char::ast_char(char in_char) {
  my_char = in_char;
  my_char_int = my_char;
}

void ast_char::xmlprint() const{
}

void ast_char::prettyprint(std::ostream &stream) const {
  stream << my_char;
}

std::string ast_char::get_id() {
    return std::to_string(my_char_int);
}

void ast_char::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (debug_mode) {
      context->get_stream() << "#This is a char" << my_char << " with value: " << my_char_int << std::endl;;
      context->get_stream() << "#Assigning to reg: " << dest_reg << std::endl << std::endl;
      }

  if (my_char_int > 65536) {
        context->get_stream() << "\tli $" << dest_reg << ", "<<65536 << "\t# Decimal, because number too big:" << 65536 << std::endl;
        context->get_stream() << "\tori $" << dest_reg << ", $"<< dest_reg << ", " << my_char_int - 65536 << "\t# Xoring the difference" << 65536 << std::endl;
    }
    else {
        context->get_stream() << "\tli $" << dest_reg << ", "<< my_char_int << "\t# Char:" << my_char_int << " --> " << my_char << std::endl;
    }

    registers->write_reg(dest_reg, std::to_string(my_char_int));
}

void ast_char::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}



ast_type::ast_type(std::string in_type) {
 Type = in_type;
}

void ast_type::xmlprint() const{
	std::cout << Type;
}

void ast_type::prettyprint(std::ostream &stream) const {
	stream << Type;
}

std::string ast_type::get_type() {
	return Type;
}

void ast_type::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
        
}

void ast_type::allocate_memory(int& allocated_mem) const {
    ;
}




ast_string::ast_string(std::string in_str) {
	Str = in_str;
}

void ast_string::xmlprint() const{
  	//std::cout << op;
}

void ast_string::prettyprint(std::ostream &stream) const {
	stream << Str;
}

void ast_string::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
        
}

void ast_string::allocate_memory(int& allocated_mem) const {
    ;
}

