
#include "logical_expr.hpp"


ast_logical_expressions::~ast_logical_expressions() {
    delete left;
	delete right;
}




ast_or_comp::ast_or_comp(const ast_base_expression *_left, const ast_base_expression *_right){
    left = _left;
    right = _right;
}

void ast_or_comp::xmlprint() const {
	
}

void ast_or_comp::prettyprint(std::ostream &stream) const{
	stream << "Or comparison: " <<std::endl
			<< "\t Left: ";
	left->prettyprint(stream);
	stream << "\t Right: ";
	right->prettyprint(stream);

	stream << std::endl;
}

void ast_or_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (debug_mode) {
       context->get_stream() << "#Adding! " << std::endl;
       context->get_stream() << "#at dest reg: " << dest_reg << std::endl; 
    }

    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    left->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    right->generate_assembly(context, registers, temp_reg_2);

    int temp_reg_3 = registers->get_free_reg();
    registers->write_reg(temp_reg_3, std::string("temp"));

    context->get_stream() << "\tsltu $" << dest_reg << ", $0, $"<< temp_reg << std::endl;
    context->get_stream() << "\tsltu $" << temp_reg_3 << ", $0, $"<< temp_reg_2 << std::endl;

    context->get_stream() << "\tor $" << dest_reg << ", $" << dest_reg << ", $" << temp_reg_3 << std::endl;
    //sltiu dest_reg 0 temp_reg

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
    registers->erase_reg(temp_reg_3);

    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }
}

int ast_or_comp::constant_fold() const {
    return left->constant_fold() || right->constant_fold();
}

void ast_or_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 12;
}





ast_and_comp::ast_and_comp(const ast_base_expression *_left, const ast_base_expression *_right){
    left = _left;
    right = _right;
}

void ast_and_comp::xmlprint() const {
	
}

void ast_and_comp::prettyprint(std::ostream &stream) const{
	stream << "And comparison: " <<std::endl
			<< "\t Left: ";
	left->prettyprint(stream);
	stream << "\t Right: ";
	right->prettyprint(stream);

	stream << std::endl;
}

void ast_and_comp::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (debug_mode) {
       context->get_stream() << "#Adding! " << std::endl;
       context->get_stream() << "#at dest reg: " << dest_reg << std::endl; 
    }

    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    left->generate_assembly(context, registers, temp_reg);

    int temp_reg_2 = registers->get_free_reg();
    registers->write_reg(temp_reg_2, std::string("temp"));
    right->generate_assembly(context, registers, temp_reg_2);

    int temp_reg_3 = registers->get_free_reg();
    registers->write_reg(temp_reg_3, std::string("temp"));

    context->get_stream() << "\tsltu $" << dest_reg << ", $0, $"<< temp_reg << std::endl;
    context->get_stream() << "\tsltu $" << temp_reg_3 << ", $0, $"<< temp_reg_2 << std::endl;

    context->get_stream() << "\tand $" << dest_reg << ", $" << dest_reg << ", $" << temp_reg_3 << std::endl;
    //sltiu dest_reg 0 temp_reg

    registers->erase_reg(temp_reg);
    registers->erase_reg(temp_reg_2);
    registers->erase_reg(temp_reg_3);


    if (debug_mode) {
       context->get_stream() << "#Ending add! " << std::endl;
    }

}

int ast_and_comp::constant_fold() const {
    return left->constant_fold() && right->constant_fold();
}

void ast_and_comp::allocate_memory(int& allocated_mem) const {
    allocated_mem += 12;
}
