#include "IFELSE_statement.hpp"


ast_if_else_statement::ast_if_else_statement(ast_base_expression* in_binary_comparison){
    binary_comparison = in_binary_comparison;
    if_expressions = NULL;
    else_expressions = NULL;
}

void ast_if_else_statement::push_back_if(ast_base_statement* in_expr) {
    if_expressions = in_expr;
}

void ast_if_else_statement::push_back_else(ast_base_statement* in_expr) {
    else_expressions = in_expr;
}

void ast_if_else_statement::xmlprint() const {
    std::cout << "<Scope>" << std::endl;

    if (if_expressions != NULL) {
        std::cout << "<Scope>" << std::endl;
        if_expressions->xmlprint();
        std::cout << "</Scope>" << std::endl;
    }

    if (else_expressions != NULL) {
        std::cout << "<Scope>" << std::endl;
        else_expressions->xmlprint();
        std::cout << "</Scope>" << std::endl;
    }
    std::cout << "</Scope>" << std::endl;

}


void ast_if_else_statement::prettyprint(std::ostream &stream) const {
    stream << "If statement:" << std::endl;
    stream << "Comparison: ";
    binary_comparison->prettyprint(stream);

    if (if_expressions != NULL) {
        stream << "\t If:" << std::endl;
        if_expressions->prettyprint(stream);
        stream << std::endl;
    }

    if (else_expressions != NULL) {
        stream << "\t Else:" << std::endl;
        else_expressions->prettyprint(stream);
        stream << std::endl;
    }
    stream << std::endl;
}

void ast_if_else_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
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

std::string ast_if_else_statement::statement_type() const {
    return "";
}

void ast_if_else_statement::allocate_memory(int& allocated_mem) const {
    binary_comparison->allocate_memory(allocated_mem);

    if (if_expressions != NULL) {
        if_expressions->allocate_memory(allocated_mem);
    }
    if (else_expressions != NULL) {
        else_expressions->allocate_memory(allocated_mem);
    }
}