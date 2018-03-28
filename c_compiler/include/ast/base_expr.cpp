
#include "base_expr.hpp"

std::string ast_base_expression::get_id() const { 
    return "";
}

ast_expression::ast_expression() { }

void ast_expression::add_new(ast_base_expression* in_expr) {
	all_expr.push_back(in_expr);
}

void ast_expression::xmlprint() const{

}

void ast_expression::prettyprint(std::ostream &stream) const {
    for (unsigned int i = 0; i < all_expr.size(); ++i){
    	if (all_expr[i] != NULL)
    		all_expr[i]->prettyprint(stream);
    	}

}

void ast_expression::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
	for (unsigned int i = 0; i < all_expr.size(); ++i){

        if (all_expr[i] != NULL)
	      	all_expr[i]->generate_assembly(context, registers, dest_reg);
    
        if (debug_mode) {
            context->get_stream() << "#ast_expression:" << std::endl;
            context->get_stream() << "#Dest Reg $" << dest_reg << std::endl;
        }

	}
}

void ast_expression::allocate_memory(int& allocated_mem) const {
    for (unsigned int i = 0; i < all_expr.size(); ++i){
        allocated_mem += 4;
    }
}

int ast_expression::constant_fold() const {
    return all_expr.at(0)->constant_fold();
}


//HACK
ast_expression_number::ast_expression_number(ast_number* in_num) {
	num = in_num;
}
	

void ast_expression_number::xmlprint() const{
	num->xmlprint();
}

void ast_expression_number::prettyprint(std::ostream &stream) const{
	num->prettyprint(stream);
}

void ast_expression_number::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
   	num->generate_assembly(context, registers, dest_reg);
}

std::string ast_expression_number::get_id() const{
    return num->get_id();
}

void ast_expression_number::allocate_memory(int& allocated_mem) const {
    num->allocate_memory(allocated_mem);
}

int ast_expression_number::constant_fold() const {
    try{
         return stoi(num->get_id());   
    }
    catch (...) {
        std::cerr << "Failed to get number value..." << std::endl;
    }
    return 0;
}



//HACK
ast_expression_char::ast_expression_char(ast_char* in_num) {
    num = in_num;
}
    

void ast_expression_char::xmlprint() const{
    num->xmlprint();
}

void ast_expression_char::prettyprint(std::ostream &stream) const{
    num->prettyprint(stream);
}

void ast_expression_char::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    num->generate_assembly(context, registers, dest_reg);
}

std::string ast_expression_char::get_id() const{
    return num->get_id();
}

void ast_expression_char::allocate_memory(int& allocated_mem) const {
    num->allocate_memory(allocated_mem);
}

int ast_expression_char::constant_fold() const {
    try{
         return stoi(num->get_id());   
    }
    catch (...) {
        std::cerr << "Failed to get number value..." << std::endl;
    }
    return 0;
}



ast_expression_identifier::ast_expression_identifier(ast_identifier* in_ID) {
	ID = in_ID;
}

void ast_expression_identifier::xmlprint() const {
	ID->xmlprint();
}

void ast_expression_identifier::prettyprint(std::ostream &stream) const{
	ID->prettyprint(stream);
}

void ast_expression_identifier::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
   	ID->generate_assembly(context, registers, dest_reg);
}

std::string ast_expression_identifier::get_id() const {
    return ID->get_id();
}

void ast_expression_identifier::allocate_memory(int& allocated_mem) const {
    ID->allocate_memory(allocated_mem);
}

int ast_expression_identifier::constant_fold() const {
    std::cerr << "Trying to constant fold a variable!" << std::endl;
    return 0;
}



ast_expression_string::ast_expression_string(ast_string* in_str) {
	my_str = in_str;
}

void ast_expression_string::xmlprint() const {
	my_str->xmlprint();
}

void ast_expression_string::prettyprint(std::ostream &stream) const{
	my_str->prettyprint(stream);
}

void ast_expression_string::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
   	my_str->generate_assembly(context, registers, dest_reg);
    
}

void ast_expression_string::allocate_memory(int& allocated_mem) const {
    my_str->allocate_memory(allocated_mem);
}

int ast_expression_string::constant_fold() const {
    std::cerr << "Trying to constant fold a variable!" << std::endl;
    return 0;
}


//HACK --> Arrays can only take integers
ast_expression_array::ast_expression_array(ast_base_expression* in_id, ast_base_expression* in_expr)
    : id(in_id), expr(in_expr) { }

void ast_expression_array::xmlprint() const {
}

std::string ast_expression_array::get_id() const {
    return std::string("$" + id->get_id() + "_" + std::to_string(expr->constant_fold()) + "_$");
}

void ast_expression_array::prettyprint(std::ostream &stream) const{
    stream << "Calling array: ";    
    id->prettyprint(stream);
    stream << std::endl << "With value: ";
    expr->prettyprint(stream);
}

void ast_expression_array::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    std::string new_id = ("$" + id->get_id() + "_" + std::to_string(expr->constant_fold()) + "_$");
    int value = context->find_variable(new_id);
    if (debug_mode) {
      context->get_stream() << "#This is an identifier with new_id: " << new_id << std::endl;;
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

void ast_expression_array::allocate_memory(int& allocated_mem) const {
    allocated_mem += expr->constant_fold();
}

int ast_expression_array::constant_fold() const {
    std::cerr << "Trying to constant fold a variable!" << std::endl;
    return 0;
}




ast_constant_expression::ast_constant_expression(ast_base_expression* in_binary_comparison, ast_base_expression* in_expr_1, ast_base_expression* in_expr_2){
	binary_comparison = in_binary_comparison;
	if_expressions = in_expr_1;
	else_expressions = in_expr_2;
}

void ast_constant_expression::xmlprint() const {
}

void ast_constant_expression::prettyprint(std::ostream &stream) const{
	stream << "Conditional expression (if equivalent):" << std::endl
			<< "\t Comparison: ";
	binary_comparison->prettyprint(stream);
	stream << "\t Take if true: ";
	if_expressions->prettyprint(stream);
	stream << "\t Take if false: ";
	else_expressions->prettyprint(stream);
}

void ast_constant_expression::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    std::string bottom_if = context->make_label("bottom_if");
    std::string bottom_else = context->make_label("bottom_else");
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));
    binary_comparison->generate_assembly(context, registers, temp_reg);
    context->get_stream() << "\tbeq $" << temp_reg << ", $0, " << bottom_if << std::endl;
    context->get_stream() << "\tnop" << std::endl;
    if (if_expressions != NULL) {
        if_expressions->generate_assembly(context, registers, dest_reg);
    }
    else {
        context->get_stream() << std::endl;
    }
    
    context->get_stream() << "\tj " << bottom_else << std::endl;
    context->get_stream() << "\tnop" << std::endl;
    
    context->get_stream() << bottom_if << ":\t" << std::endl;;
    if (else_expressions != NULL) {
        else_expressions->generate_assembly(context, registers, dest_reg);
    }
    else {
        context->get_stream() << std::endl;
    }
    std::cout << bottom_else << ":\t" << std::endl;
    registers->erase_reg(temp_reg);
}

void ast_constant_expression::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}

int ast_constant_expression::constant_fold() const {
    if (binary_comparison->constant_fold() > 0) {
        if (if_expressions != NULL) {
            return if_expressions->constant_fold();
        }
    }
    else {
        if (else_expressions != NULL) {
            return else_expressions->constant_fold();
        }
    }
    return 0;
}
