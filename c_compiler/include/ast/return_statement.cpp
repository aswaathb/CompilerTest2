#include "return_statement.hpp"


ast_return_statement::ast_return_statement(ast_base_expression* in_id) 
{
	id = in_id;
}

void ast_return_statement::xmlprint() const {
	//if (id != NULL)
	//	id->xmlprint();
}

void ast_return_statement::prettyprint(std::ostream &stream) const {
    stream << "Returning ";
    if (id != NULL){
        id->prettyprint(stream);
    }
    stream << std::endl;
}

void ast_return_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    save_math_op = true;
    
    if (debug_mode) {
        context->get_stream() << "#Return Statement! " << std::endl;
        context->get_stream() << "#ID: " << id << std::endl;
        context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
    }

    if (id != NULL){
        id->generate_assembly(context, registers, dest_reg);
    }

    if (debug_mode) {
        context->get_stream() << "#Ending return statement" << std::endl;
    }
    
    context->exit_subroutine();
    
    save_math_op = false;

    //context->get_stream() << "\t" << "j $31" << std::endl;
    //context->get_stream() << "\tnop" << std::endl;
}

std::string ast_return_statement::statement_type() const {
    return "";
}

void ast_return_statement::allocate_memory(int& allocated_mem) const {
    id->allocate_memory(allocated_mem);
}





ast_break_statement::ast_break_statement() { }

void ast_break_statement::xmlprint() const {
    //if (id != NULL)
    //  id->xmlprint();
}

void ast_break_statement::prettyprint(std::ostream &stream) const {
    stream << "Breaking ";
}

void ast_break_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    context->get_stream() << "b " << context->get_break() << std::endl;
    context->get_stream() << "nop" << std::endl;
    
}

std::string ast_break_statement::statement_type() const {
    return "break_statement";
}

void ast_break_statement::allocate_memory(int& allocated_mem) const {
    ;
}





ast_expression_statement::ast_expression_statement(ast_base_expression* in_id) 
{
	id = in_id;
}

void ast_expression_statement::xmlprint() const {
	//if (id != NULL) {
	//	id->xmlprint();
	//}
}

void ast_expression_statement::prettyprint(std::ostream &stream) const {
    if (id!=NULL)
        id->prettyprint(stream);
}

void ast_expression_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const{
    //int temp_reg = registers->get_free();
    //registers->write(temp_reg, std::string("temp"));
    if (debug_mode) {
       context->get_stream() << "#Expression Statement! " << std::endl;
       context->get_stream() << "#at dest reg: " << dest_reg << std::endl; 
    }

    if (id != NULL)
        id->generate_assembly(context, registers, dest_reg);


    if (debug_mode) {
       context->get_stream() << "#Ending Expression Statement! " << std::endl;
    }
    
    //context->get_stream() << "move $" << dest_reg << ", $" << temp_reg << std::endl;
    //registers->erase(temp_reg);
}

std::string ast_expression_statement::statement_type() const {
    return "";
}

void ast_expression_statement::allocate_memory(int& allocated_mem) const {
    if (id != NULL)
        id->allocate_memory(allocated_mem);
}
