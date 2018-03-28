
#include "compound_statement.hpp"



ast_statement_list::ast_statement_list(){
}

void ast_statement_list::add_new(ast_base_statement* in_stat) {
    all_statements.push_back(in_stat);
}


void ast_statement_list::xmlprint() const {
    for (unsigned int i =0; i < all_statements.size(); i++) {
      if (all_statements[i] != NULL)
        all_statements[i]->xmlprint();
    }
}

void ast_statement_list::prettyprint(std::ostream &stream) const {
    for (unsigned int i =0; i < all_statements.size(); i++) {
      if (all_statements[i] != NULL)
        all_statements[i]->prettyprint(stream);
    }
}


void ast_statement_list::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
        for (unsigned int i =0; i < all_statements.size(); i++) {

            if (all_statements[i] != NULL)
                all_statements[i]->generate_assembly(context, registers, dest_reg);

        }
}

std::string ast_statement_list::statement_type() const {
    return "";
}

void ast_statement_list::allocate_memory(int& allocated_mem) const {
    for (unsigned int i =0; i < all_statements.size(); i++) {
        if (all_statements[i] != NULL)
            all_statements[i]->allocate_memory(allocated_mem);

    }
} 




ast_compound_statement::ast_compound_statement(ast_statement_list* in_stat){
    all_statements = in_stat;
    empty_function = false;
}

ast_compound_statement::ast_compound_statement(){
    empty_function = true;
}


void ast_compound_statement::xmlprint() const {
    if (!empty_function && all_statements != NULL) {
        all_statements->xmlprint();
    }
}

void ast_compound_statement::prettyprint(std::ostream &stream) const {
    if (!empty_function && all_statements != NULL) {
        all_statements->prettyprint(stream);
    }
}

void ast_compound_statement::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
        context->make_scope(std::string("Compound_Statement"), std::string("compound_statement"), 0);

        if (!empty_function && all_statements != NULL) {
            all_statements->generate_assembly(context, registers, dest_reg);
        }

        context->exit_scope();
}

std::string ast_compound_statement::statement_type() const {
    return "";
}

void ast_compound_statement::allocate_memory(int& allocated_mem) const {
    if (!empty_function && all_statements != NULL) {
        all_statements->allocate_memory(allocated_mem);
    }
}

