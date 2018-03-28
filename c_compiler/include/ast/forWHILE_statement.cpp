#include "forWHILE_statement.hpp"


ast_loops::~ast_loops() {}



ast_for_statement::ast_for_statement(ast_base_expression* in_condition, ast_base_expression* in_bin_op, ast_base_statement* stat) {
    first_condition = in_condition;
    bin_op = in_bin_op;
    base_expr = NULL;
    statement = stat;
}

ast_for_statement::ast_for_statement(ast_base_expression* in_condition, ast_base_expression* in_bin_op, ast_base_expression* in_base_expr, ast_base_statement* stat) {
    first_condition = in_condition;
    bin_op = in_bin_op;
    base_expr = in_base_expr;
    statement = stat;
}

void ast_for_statement::xmlprint() const {
    if (first_condition != NULL) {
        std::cout << "<Scope>" << std::endl;
        first_condition->xmlprint();

        if (statement != NULL)
            statement->xmlprint();

        std::cout << "</Scope>" << std::endl;
    }
    else {
        std::cout << "<Scope>" << std::endl;
        if (statement != NULL)
            statement->xmlprint();

        std::cout << "</Scope>" << std::endl;   
    }
}


void ast_for_statement::prettyprint(std::ostream &stream) const {
    if (first_condition != NULL) {
        stream << "For loop: " << std::endl;

        stream << "\t Declaration: ";
        first_condition->prettyprint(stream);

    }
    
    stream << " | Condition: ";
    bin_op->prettyprint(stream);

    if (base_expr !=NULL) {
        stream << " | Increment/Decrement: ";
        base_expr->prettyprint(stream);
    }

    if (statement != NULL) {
        stream << " | Statements: ";
        statement->prettyprint(stream);
    }

    stream << std::endl;
}


void ast_for_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    first_condition->generate_assembly(context, registers, dest_reg);

    std::string top_while = context->make_label("top_while");
    std::string done = context->make_label("Done");
    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));

    std::cout << top_while << ":\t" << std::endl;

    bin_op->generate_assembly(context, registers, temp_reg);

    context->get_stream() << "\tbeq $"  << temp_reg     << ", $0, " << done << std::endl;
    context->get_stream() << "\tnop"    << std::endl;

    if (statement != NULL)
        statement->generate_assembly(context, registers, dest_reg);


    //ToDO: implement defualt --> i++
    if (base_expr != NULL)
        base_expr->generate_assembly(context, registers, dest_reg);


    context->get_stream() << "\tj " << top_while << std::endl;
    context->get_stream() << "\tnop" << std::endl;

    context->get_stream() << done << ":\t" << std::endl;

    context->get_stream() << context->insert_break() << ":" << std::endl;

    registers->erase_reg(temp_reg);
}

std::string ast_for_statement::statement_type() const {
    return "";
}

void ast_for_statement::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;

    first_condition->allocate_memory(allocated_mem);

    bin_op->allocate_memory(allocated_mem);

    if (base_expr != NULL)
        base_expr->allocate_memory(allocated_mem);

    if (statement != NULL)
        statement->allocate_memory(allocated_mem);
}







ast_while_statement::ast_while_statement(ast_base_expression* in_comparison, ast_base_statement* in_stat, bool in_do_while) {
    statement = in_stat;
    comparison = in_comparison;
    do_while = in_do_while;
}

void ast_while_statement::xmlprint() const {
    std::cout << "<Scope>" << std::endl;

    if (statement != NULL)
        statement->xmlprint();

    std::cout << "</Scope>" << std::endl;
}


void ast_while_statement::prettyprint(std::ostream &stream) const {
    if (!do_while)
        stream << "While Loop: ";
    else
        stream << "Do While Loop: ";
    
    stream << "\t Conditions: ";
    comparison->prettyprint(stream);
    stream << " | Statements: ";
    statement->prettyprint(stream);
    stream << std::endl;
}

void ast_while_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    std::string top_while = context->make_label("top_while");
    std::string done = context->make_label("Done");

    int temp_reg = registers->get_free_reg();
    registers->write_reg(temp_reg, std::string("temp"));

    if (do_while == false) {
        std::cout << top_while << ":\t" << std::endl;

        comparison->generate_assembly(context, registers, temp_reg);

        context->get_stream() << "\tbeq $" << temp_reg << ", $0, " << done << std::endl;
        context->get_stream() << "\tnop" << std::endl;


        if (statement != NULL)
            statement->generate_assembly(context, registers, dest_reg);
    }
    else{
        std::cout << top_while << ":\t" << std::endl;

        if (statement != NULL)
            statement->generate_assembly(context, registers, dest_reg);
        
        comparison->generate_assembly(context, registers, temp_reg);

        context->get_stream() << "\tbeq $" << temp_reg << ", $0, " << done << std::endl;
        context->get_stream() << "\tnop" << std::endl;
    }
    
    context->get_stream() << "\tj " << top_while << std::endl;
    context->get_stream() << "\tnop" << std::endl;


    std::cout << done << ":\t" << std::endl;
    context->get_stream() << context->insert_break() << ":"<< std::endl;


    registers->erase_reg(temp_reg);

}

std::string ast_while_statement::statement_type() const {
    return "";
}

void ast_while_statement::allocate_memory(int& allocated_mem) const {
    //allocated_mem += 4;

    comparison->allocate_memory(allocated_mem);

    if (statement != NULL)
        statement->allocate_memory(allocated_mem);

}

