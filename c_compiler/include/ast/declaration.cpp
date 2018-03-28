
#include "declaration.hpp"


ast_declarator::~ast_declarator() {}

std::string ast_declarator::statement_type() const {
    return "";
}



ast_variable_declarator::ast_variable_declarator(ast_identifier* in_ID) {
    ID = in_ID;
}

void ast_variable_declarator::xmlprint() const{
    if (ID != NULL)
        ID->xmlprint();
}

void ast_variable_declarator::prettyprint(std::ostream &stream) const {
    stream << "Variable: ";
    if (ID != NULL)
        ID->prettyprint(stream);
}

void ast_variable_declarator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {

    //TODO: need to figure out a way to do all of them

    if (debug_mode) {
        context->get_stream() << "#Variable Declaration: " << std::endl;
        context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
    }


    if (ID != NULL)
        ID->generate_assembly(context, registers, dest_reg);

    if (debug_mode) {
        context->get_stream() << "#Ending variable declaration" << std::endl;
    }

    //context->get_stream() << "move $" << dest_reg << ", $" << temp_reg << std::endl;

    //registers->erase_reg(temp_reg);
}

std::string ast_variable_declarator::get_id() const {
    return ID->get_id();
}

std::string ast_variable_declarator::statement_type() const {
    return "";
}

void ast_variable_declarator::allocate_memory(int& allocated_mem) const {
    if (ID != NULL)
        ID->allocate_memory(allocated_mem);
}







ast_array_declarator::ast_array_declarator(ast_identifier* in_ID, ast_base_expression* in_expr)
    : inside_expr (in_expr), ID(in_ID) { }

void ast_array_declarator::xmlprint() const{
    ;
}

void ast_array_declarator::prettyprint(std::ostream &stream) const {
    stream << " Array identifier: ";
    ID->prettyprint(stream);
    stream << "Value: ";
    if (inside_expr != NULL)
        inside_expr->prettyprint(stream);
    stream << std::endl;
}

void ast_array_declarator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {

    if (debug_mode) {
        context->get_stream() << "#Array Declaration: " << std::endl;
        context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
    }

        
    int count = inside_expr->constant_fold();

    try {

        for (int i = 0; i <= count; ++i) {
            std::string temp_str = "$" + ID->get_id() + "_" + std::to_string(i) + "_$";

            int temp_mem = registers->get_free_mem();

            registers->write_mem(dest_reg, std::to_string(temp_mem), context->get_current_func());
            
            context->insert_symbols("int", temp_str, temp_mem, true);
        }


    }
    catch (...) {

    }
    

    if (debug_mode) {
        context->get_stream() << "#Ending variable declaration" << std::endl;
    }
}

std::string ast_array_declarator::get_id() const {
    return "$" + ID->get_id() + "_" + inside_expr->get_id() + "_$";
}

std::string ast_array_declarator::statement_type() const {
    return "";
}

void ast_array_declarator::allocate_memory(int& allocated_mem) const {
    if (ID != NULL)
        ID->allocate_memory(allocated_mem);
}






ast_initialisers_declarator::ast_initialisers_declarator(ast_declarator* in_dec, ast_base_expression* in_equal_expr) {
    declarator = in_dec;
    equal_expression = in_equal_expr;
}

void ast_initialisers_declarator::xmlprint() const{
    std::cout << "<Variable id=\"";
    if (declarator != NULL)
        declarator->xmlprint();
    std::cout <<"\" /> ";

}

void ast_initialisers_declarator::prettyprint(std::ostream &stream) const {
    stream << "declarator: ";
    if (declarator != NULL)
        declarator->prettyprint(stream);

    stream << std::endl;
    stream << "Equal to: ";

    if (equal_expression != NULL)
        equal_expression->prettyprint(stream);
}

void ast_initialisers_declarator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    //First generate equal expression assembly:
    //Put the answer of equal expression in a temporary register 
    
    //int temp_reg = registers->get_free();
    //registers->write(dest_reg, std::string("temp"));
    if (debug_mode) {
        context->get_stream() << "#Initialisers Declaration: " << std::endl;
        context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
    }

    if (equal_expression != NULL)
        equal_expression->generate_assembly(context, registers, dest_reg);

    
    if (debug_mode) {
        context->get_stream() << "#Ending initialisers declarator: " << std::endl;
    }

    //context->get_stream() << "move $" << dest_reg << ", $" << temp_reg << std::endl;

    //registers->erase_reg(temp_reg);
}

std::string ast_initialisers_declarator::get_id() const {
    return declarator->get_id();
}

std::string ast_initialisers_declarator::statement_type() const {
    return "";
}

void ast_initialisers_declarator::allocate_memory(int& allocated_mem) const {
    if (equal_expression != NULL)
        equal_expression->allocate_memory(allocated_mem);
}

int ast_initialisers_declarator::constant_fold() const {
    return equal_expression->constant_fold();
}







ast_declaration::ast_declaration(ast_type* in_Type) {
    Type = in_Type;
}

ast_declaration::ast_declaration(ast_type* in_Type, std::vector<ast_initialisers_declarator*> in_dec) {
    Type = in_Type;
    dec_list = in_dec;
}


void ast_declaration::xmlprint() const{
    for (unsigned int i =0; i < dec_list.size(); i++) {
        if (dec_list[i] != NULL)
            dec_list[i]->xmlprint();
    }
    std::cout << std::endl;
}


void ast_declaration::prettyprint(std::ostream &stream) const {
    for (unsigned int i =0; i < dec_list.size(); i++) {
        if (dec_list[i] != NULL)
            dec_list[i]->prettyprint(stream);
    }
    stream << std::endl;
} 


void ast_declaration::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {            
    for (unsigned int i =0; i < dec_list.size(); i++) {

        if ((dec_list[i] != NULL) && (Type != NULL)) {
            int temp_reg = registers->get_free_reg();
            registers->write_reg(temp_reg, std::string("temp"));

            //Put the answer of equal expression in a temporary register
            if (debug_mode) {
                context->get_stream() << "#Declaration: " << std::endl;
                context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
                context->get_stream() << "#at temp reg: " << temp_reg << std::endl;
            }

            
            dec_list[i]->generate_assembly(context, registers, temp_reg);
            //Get the value of the  register and put it as a symbol in context
            
                
            if (debug_mode) {
                context->get_stream() << "#Ending initialisers declarator: " << std::endl;
            }
            
            int temp_mem = registers->get_free_mem();
            context->get_stream() << "\tsw $" << temp_reg << ", " << temp_mem*4 << "($fp)" << std::endl;
            registers->write_mem(temp_mem, std::string("temp"), context->get_current_func());
            
            context->insert_symbols(Type->get_type(), dec_list[i]->get_id(), temp_mem, true);

            //Free up the temporary register -->it is stored in registers in basic tokens
            registers->erase_reg(temp_reg);            

        }
    }
    context->get_stream() << std::endl;
}

std::string ast_declaration::statement_type() const {
    return "";
}

ast_type* ast_declaration::return_type() {
    return Type;
}

void ast_declaration::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
    for (unsigned int i =0; i < dec_list.size(); i++) {
        if ((dec_list[i] != NULL) && (Type != NULL))
            allocated_mem += 4;
    }
}

std::vector<ast_initialisers_declarator*>* ast_declaration::return_dec_list() {
    return &dec_list;
}






ast_global_declaration::ast_global_declaration(ast_declaration* in_decl) {
    decl = in_decl;
    Type = decl->return_type();
    dec_list = decl->return_dec_list();
}

//~ast_declaration() {}

void ast_global_declaration::xmlprint() const{
    decl->xmlprint();
}


void ast_global_declaration::prettyprint(std::ostream &stream) const {
    stream << "This is a global declaration. Printing same stuff as normal declaration." << std::endl;
    decl->prettyprint(stream);
} 

void ast_global_declaration::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    for (unsigned int i =0; i < dec_list->size(); i++) {
        if ((dec_list->at(i) != NULL) && (Type != NULL) && (dec_list->at(i)->get_id() != "")) {

            int temp_reg = registers->get_free_reg();

            registers->write_reg(temp_reg, std::string("temp"));
            
            int answer = constant_fold(dec_list->at(i));
            //Put the answer of equal expression in a temporary register

            int temp_mem = registers->get_free_mem();
            //context->get_stream() << "sw $" << temp_reg << ", " << temp_mem*4 << "($fp)" << std::endl;
            registers->write_mem(temp_mem, std::string("temp"), context->get_current_func());
            
            context->insert_global(Type->get_type(), dec_list->at(i)->get_id(), temp_mem); 

            context->get_stream() << "\t.globl\t" << dec_list->at(i)->get_id()                      << std::endl
                                  << "\t.data"                                                      << std::endl
                                  << "\t.align\t2"                                                  << std::endl
                                  << "\t.type\t" << dec_list->at(i)->get_id() << ", " << "@object"  << std::endl
                                  << dec_list->at(i)->get_id() << ":"                               << std::endl
                                  << "\t.word\t" << answer                                          << std::endl
                                  << "\t.text\t"                                                    << std::endl
                                  << "\t.align\t2"                                                  << std::endl;
            
            //context->get_stream() << "\tlui $2,%hi(" << dec_list->at(i)->get_id() << ")" << std::endl;

            //context->get_stream() << "\tsw  $" << temp_reg << ",%lo(" << dec_list->at(i)->get_id() << ")($2)"<< std::endl;

            //registers->erase_reg(temp_reg);            

            declaration_template temp;
            temp.reg_num = temp_reg;
            temp.ID = dec_list->at(i)->get_id();
            temp.dec = dec_list->at(i);
            temp.temp_mem = temp_mem;

            load_dec.push_back(temp);

            if (debug_mode) {
                context->get_stream() << "#Temp mem: " << registers->get_value(temp_mem-1) << std::endl;
                context->get_stream() << "#ID: " << dec_list->at(i)->get_id() << std::endl;
                context->get_stream() << "#Global Declaration: " << std::endl;
                context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
                context->get_stream() << "#at temp reg: " << temp_reg << std::endl;
                
                int value = context->find_variable(dec_list->at(i)->get_id());
                context->get_stream() << "#Value: " << value << std::endl;

                if ((value != -1) && (value != -2))
                    context->get_stream() << "#Temp mem " << registers->get_value(value) << std::endl;
            }
            registers->erase_reg(temp_reg);
        }
    }   
    context->get_stream() << std::endl;
}

void ast_global_declaration::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
    for (unsigned int i =0; i < dec_list->size(); i++) {
        if ((dec_list->at(i) != NULL) && (Type != NULL))
            allocated_mem += 4;
    }
}

std::string ast_global_declaration::statement_type() const {
    return "";
}

int ast_global_declaration::constant_fold(ast_initialisers_declarator* in_dec) const{
    return in_dec->constant_fold();
}