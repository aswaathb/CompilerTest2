
#include "math_operators.hpp"


ast_math_operators::~ast_math_operators()
{
    delete left;
    delete right;
}

const ast_base_expression* ast_math_operators::get_left() const {
    return left;
}
const ast_base_expression* ast_math_operators::get_right() const {
    return right;
}

const ast_base_expression *left;
const ast_base_expression *right;


ast_math_operators::ast_math_operators(const ast_base_expression *_left, const ast_base_expression *_right)
    : left(_left), right(_right) {}




ast_add_operator::ast_add_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }

void ast_add_operator::xmlprint() const {
	
}

void ast_add_operator::prettyprint(std::ostream &stream) const {
    stream << "Maths Add: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_add_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (debug_mode) {
       context->get_stream() << "#Adding! " << std::endl;
       context->get_stream() << "#at dest reg: " << dest_reg << std::endl; 
    }

    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tadd $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }
}

int ast_add_operator::constant_fold() const {
    return get_left()->constant_fold() + get_right()->constant_fold();
}

void ast_add_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}





ast_subtract_operator::ast_subtract_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_subtract_operator::xmlprint() const {
	
}

void ast_subtract_operator::prettyprint(std::ostream &stream) const {
    stream << "Maths Sub: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_subtract_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    if (debug_mode) {
       context->get_stream() << "#Subtracting! " << std::endl;
       context->get_stream() << "#at dest reg: " << dest_reg << std::endl; 
    }

    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tsub $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;
    
    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending sub! " << std::endl;
    }

}

int ast_subtract_operator::constant_fold() const {
    return get_left()->constant_fold() - get_right()->constant_fold();
}

void ast_subtract_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}





ast_multiply_operator::ast_multiply_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }

void ast_multiply_operator::xmlprint() const {
	
}

void ast_multiply_operator::prettyprint(std::ostream &stream) const {
    stream << "Maths Mul: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_multiply_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tmul $" << dest_reg << ", $" << temp_reg << ", $" << temp_reg_2  << std::endl;
    //GCC seems to put it in the stack first
    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    if (debug_mode) {
       context->get_stream() << "#Ending mul! " << std::endl;
    }

    try {
        int temp_1 = std::stoi(get_left()->get_id());
        int temp_2 = std::stoi(get_right()->get_id());
        int addition = temp_1 * temp_2;

        registers->write_reg(dest_reg, std::to_string(addition));

    }
    catch (...) {
        ;
    }

}

int ast_multiply_operator::constant_fold() const {
    return get_left()->constant_fold() * get_right()->constant_fold();
}

void ast_multiply_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;

}




ast_divide_operator::ast_divide_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }

void ast_divide_operator::xmlprint() const {
	
}

void ast_divide_operator::prettyprint(std::ostream &stream) const {
    stream << "Maths Div: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_divide_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tdiv $0" << ", $" << temp_reg << ", $" << temp_reg_2   << std::endl;
    context->get_stream() << "\tmflo $" << dest_reg                         << std::endl;

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
    registers->erase_reg(0);

    if (debug_mode) {
       context->get_stream() << "#Ending div! " << std::endl;
    }
}

int ast_divide_operator::constant_fold() const {
    return get_left()->constant_fold() / get_right()->constant_fold();
}

void ast_divide_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}





ast_bitwise_and_operator::ast_bitwise_and_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }

void ast_bitwise_and_operator::xmlprint() const {
    
}

void ast_bitwise_and_operator::prettyprint(std::ostream &stream) const {
    stream << "Bitwise AND: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_bitwise_and_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tand $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending bitwise and! " << std::endl;
    }
}

int ast_bitwise_and_operator::constant_fold() const {
    return get_left()->constant_fold() & get_right()->constant_fold();
}

void ast_bitwise_and_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}





ast_bitwise_or_operator::ast_bitwise_or_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_bitwise_or_operator::xmlprint() const {
    
}

void ast_bitwise_or_operator::prettyprint(std::ostream &stream) const {
    stream << "Bitwise OR: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_bitwise_or_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tor $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending bitwise or! " << std::endl;
    }

}

int ast_bitwise_or_operator::constant_fold() const {
    return get_left()->constant_fold() | get_right()->constant_fold();
}

void ast_bitwise_or_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}





ast_bitwise_xor_operator::ast_bitwise_xor_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_bitwise_xor_operator::xmlprint() const {
    
}

void ast_bitwise_xor_operator::prettyprint(std::ostream &stream) const {
    stream << "Bitwise XOR: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_bitwise_xor_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\txor $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending bitwise xor! " << std::endl;
    }
}

int ast_bitwise_xor_operator::constant_fold() const {
    return get_left()->constant_fold() ^ get_right()->constant_fold();
}

void ast_bitwise_xor_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}







ast_bitwise_modulo_operator::ast_bitwise_modulo_operator(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }

void ast_bitwise_modulo_operator::xmlprint() const {
    
}

void ast_bitwise_modulo_operator::prettyprint(std::ostream &stream) const {
    stream << "Bitwise modulo: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_bitwise_modulo_operator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tdiv $0" << ", $" << temp_reg << ", $" << temp_reg_2   << std::endl;
    context->get_stream() << "\tmfhi $" << dest_reg                         << std::endl;
    
    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending bitwise modulo! " << std::endl;
    }

}

int ast_bitwise_modulo_operator::constant_fold() const {
    return get_left()->constant_fold() % get_right()->constant_fold();
}

void ast_bitwise_modulo_operator::allocate_memory(int& allocated_mem) const {
    allocated_mem += 16;
}





ast_left_shift_bit::ast_left_shift_bit(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_left_shift_bit::xmlprint() const {
    
}


void ast_left_shift_bit::prettyprint(std::ostream &stream) const {
    stream << "Left shift: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_left_shift_bit::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);
    
    context->get_stream() << "\tsll $" << dest_reg << ", $" << temp_reg << ", $" << temp_reg_2 << std::endl;
    
    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    //But I free it up straight away??
    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
}

int ast_left_shift_bit::constant_fold() const {
    return get_left()->constant_fold() << get_right()->constant_fold();
}

void ast_left_shift_bit::allocate_memory(int& allocated_mem) const {
    allocated_mem += 8;
}






ast_right_shift_bit::ast_right_shift_bit(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_math_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_right_shift_bit::xmlprint() const {
    
}


void ast_right_shift_bit::prettyprint(std::ostream &stream) const {
    stream << "Right Shift: " << std::endl;
    stream << "\t Left expression: ";
    get_left()->prettyprint(stream);
    stream << "\t Right expr: ";
    get_right()->prettyprint(stream);
    stream << std::endl;
}

void ast_right_shift_bit::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    get_left()->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    get_right()->generate_assembly(context, registers, temp_reg_2);

    context->get_stream() << "\tsra $" << dest_reg << ", $" << temp_reg << ", $" << temp_reg_2 << std::endl;

    if (save_math_op) {
        int new_mem = registers->get_free_mem();
        context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
        registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    }

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
}

int ast_right_shift_bit::constant_fold() const{
    return get_left()->constant_fold() >> get_right()->constant_fold();
}

void ast_right_shift_bit::allocate_memory(int& allocated_mem) const {
    allocated_mem += 8;
}


