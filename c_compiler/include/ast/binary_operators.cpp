
#include "binary_operators.hpp"

ast_binary_operators::~ast_binary_operators() {
	delete left;
	delete right;
}

const ast_base_expression* ast_binary_operators::get_left() const{
	return left;
}

const ast_base_expression* ast_binary_operators::get_right() const{
	return right;
}

ast_binary_operators::ast_binary_operators(const ast_base_expression *_left, const ast_base_expression *_right)
    : left(_left), right(_right) {}




ast_less_comp::ast_less_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
    : ast_binary_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_less_comp::xmlprint() const {
	
}

void ast_less_comp::prettyprint(std::ostream &stream) const {
	stream << "Doing a less comparison: " << std::endl;
	stream << "\t Left expr: ";
	get_left()->prettyprint(stream); 
	stream << std::endl;
	stream << "\t Right expr: ";
	get_right()->prettyprint(stream);
	stream << std::endl;
}

void ast_less_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

        context->get_stream() << "\tslt $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;

        registers->erase_reg(temp_reg);
        registers->erase_reg(temp_reg_2);

        if (debug_mode) {
           context->get_stream() << "#Ending add! " << std::endl;
        }
}

int ast_less_comp::constant_fold() const {
    if (get_left()->constant_fold() < get_right()->constant_fold()){
        return 1;
    }
    else {
        return 0;
    }
}


void ast_less_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}



ast_less_equal_comp::ast_less_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
    : ast_binary_operators(_left, _right) { }


void ast_less_equal_comp::xmlprint() const {
	
}

void ast_less_equal_comp::prettyprint(std::ostream &stream) const {
	stream << "Doing a less equal comparison: " << std::endl;
	stream << "\t Left expr: ";
	get_left()->prettyprint(stream); 
	stream << std::endl;
	stream << "\t Right expr: ";
	get_right()->prettyprint(stream);
	stream << std::endl;
}

void ast_less_equal_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

    int temp_reg_3 = registers->get_free_reg();
    registers->write_reg(temp_reg_3, std::string("temp"));
    context->get_stream() << "\tslt $" << temp_reg_3 << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;

    int temp_reg_4 = registers->get_free_reg();
    registers->write_reg(temp_reg_4, std::string("temp"));
    context->get_stream() << "\txor $" << temp_reg_4 << ", $"<< temp_reg_2 << ", $" << temp_reg << std::endl;
    context->get_stream() << "\tsltiu $" << temp_reg_4 << ", $"<< temp_reg_4 << ", 1" << std::endl;


    context->get_stream() << "\tor $" << dest_reg << ", $"<< temp_reg_3 << ", $" << temp_reg_4 << std::endl;

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
    registers->erase_reg(temp_reg_3);
    registers->erase_reg(temp_reg_4);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }    
}

int ast_less_equal_comp::constant_fold() const {
    if (get_left()->constant_fold() <= get_right()->constant_fold()){
        return 1;
    }
    else {
        return 0;
    }
}

void ast_less_equal_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}




ast_greater_comp::ast_greater_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_binary_operators(_left, _right) { }

void ast_greater_comp::xmlprint() const {
	
}

void ast_greater_comp::prettyprint(std::ostream &stream) const {
	stream << "Doing a greater comparison: " << std::endl;
	stream << "\t Left expr: ";
	get_left()->prettyprint(stream); 
	stream << std::endl;
	stream << "\t Right expr: ";
	get_right()->prettyprint(stream);
	stream << std::endl;
}

void ast_greater_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

    context->get_stream() << "\tslt $" << dest_reg << ", $"<< temp_reg_2 << ", $" << temp_reg << std::endl;

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }    
}

int ast_greater_comp::constant_fold() const {
    if (get_left()->constant_fold() > get_right()->constant_fold()){
        return 1;
    }
    else {
        return 0;
    }
}

void ast_greater_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}



ast_greater_equal_comp::ast_greater_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
    : ast_binary_operators(_left, _right) { }

void ast_greater_equal_comp::xmlprint() const {
	
}

void ast_greater_equal_comp::prettyprint(std::ostream &stream) const {
	stream << "Doing a greater equal comparison: " << std::endl;
	stream << "\t Left expr: ";
	get_left()->prettyprint(stream); 
	stream << std::endl;
	stream << "\t Right expr: ";
	get_right()->prettyprint(stream);
	stream << std::endl;
}

void ast_greater_equal_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

    context->get_stream() << "\tslt $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;
    context->get_stream() << "\txori $" << dest_reg << ", $"<< dest_reg << ", 1" << std::endl;


    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }    
}

int ast_greater_equal_comp::constant_fold() const {
    if (get_left()->constant_fold() >= get_right()->constant_fold()){
        return 1;
    }
    else {
        return 0;
    }
}

void ast_greater_equal_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}





ast_equal_comp::ast_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_binary_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_equal_comp::xmlprint() const {
	
}

void ast_equal_comp::prettyprint(std::ostream &stream) const {
	stream << "Doing an equal comparison: " << std::endl;
	stream << "\t Left expr: ";
	get_left()->prettyprint(stream); 
	stream << std::endl;
	stream << "\t Right expr: ";
	get_right()->prettyprint(stream);
	stream << std::endl;
}

void ast_equal_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

    context->get_stream() << "\txor $" << dest_reg << ", $"<< temp_reg_2 << ", $" << temp_reg << std::endl;
    context->get_stream() << "\tsltiu $" << dest_reg << ", $"<< dest_reg << ", 1" << std::endl;

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }    
}

int ast_equal_comp::constant_fold() const {
    if (get_left()->constant_fold() == get_right()->constant_fold()){
        return 1;
    }
    else {
        return 0;
    }
}

void ast_equal_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}





ast_not_equal_comp::ast_not_equal_comp(const ast_base_expression *_left, const ast_base_expression *_right) 
: ast_binary_operators(_left, _right) { }
//~ast_if_else_statement() {}

void ast_not_equal_comp::xmlprint() const {
	
}

void ast_not_equal_comp::prettyprint(std::ostream &stream) const {
	stream << "Doing a not equal comparison: " << std::endl;
	stream << "\t Left expr: ";
	get_left()->prettyprint(stream); 
	stream << std::endl;
	stream << "\t Right expr: ";
	get_right()->prettyprint(stream);
	stream << std::endl;
}

void ast_not_equal_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

    int temp_reg_3 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));

    context->get_stream() << "\tslt $" << dest_reg << ", $"<< temp_reg << ", $" << temp_reg_2 << std::endl;
    context->get_stream() << "\tslt $" << temp_reg_3 << ", $"<< temp_reg_2 << ", $" << temp_reg << std::endl;
    context->get_stream() << "\txor $" << dest_reg << ", $" << dest_reg << ", $" << temp_reg_3 << std::endl;


    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
    registers->erase_reg(temp_reg_3);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }    
}

int ast_not_equal_comp::constant_fold() const {
    if (get_left()->constant_fold() != get_right()->constant_fold()){
        return 1;
    }
    else {
        return 0;
    }
}

void ast_not_equal_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}
