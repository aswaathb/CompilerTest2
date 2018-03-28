
#include "function_params.hpp"

ast_function_parameters::ast_function_parameters(ast_type* in_type, ast_declarator* in_ID) {
    ID = in_ID;
    Type = in_type;
}

//~ast_function_parameters() {}

void ast_function_parameters::xmlprint() const {
	
    std::cout << "<Parameter id=\"";
    if (ID != NULL)
        ID->xmlprint();
    std::cout << "\" /> ";
}

void ast_function_parameters::prettyprint(std::ostream &stream) const {
    stream << "Parameter Type = ";
    Type->prettyprint(stream);
    stream << " id=\"";
    ID->prettyprint(stream);
    stream << "\" ";
}

void ast_function_parameters::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    ID->generate_assembly(context, registers, dest_reg);

    //std::cout << "My func ID: " << ID->get_id() << std::endl;
    
}

std::string ast_function_parameters::get_id() {

    if (ID != NULL)
        return ID->get_id();
    else
        return "";
}

void ast_function_parameters::allocate_memory(int& allocated_mem) const {
    //allocated_mem += 4;
    ID->allocate_memory(allocated_mem);
}




ast_function_declarator::ast_function_declarator(ast_identifier* in_ID, std::vector<ast_function_parameters*> in_parameters) {
    ID = in_ID;
    all_parameters = in_parameters;
}

ast_function_declarator::ast_function_declarator(ast_identifier* in_ID) {
    ID = in_ID;
}

void ast_function_declarator::xmlprint() const{
    if (ID != NULL)
        ID->xmlprint();
}

void ast_function_declarator::prettyprint(std::ostream &stream) const {
    stream << "Function variable: ";
    if (ID != NULL)
        ID->prettyprint(stream);
    stream << "With parameters: " << std::endl;
    for (unsigned int i =0; i< all_parameters.size(); i++) {
        all_parameters[i]->prettyprint(stream);
        stream << " ";
    }
}

void ast_function_declarator::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (debug_mode) {
        context->get_stream() << "#function Declaration: " << std::endl;
        context->get_stream() << "#at dest reg: " << dest_reg << std::endl;
    }

    //Saving the appropriate parameters
    //Using parameter registers: $a0 - $a3 i.e. 4 - 7
    if ((all_parameters.size() > 0) && (all_parameters.size() <= 4)) {
        context->flush_parameters();
        
        for (unsigned int i = 0; i < all_parameters.size(); i++) {

            int value_mem = context->find_variable(ID->get_id());

            if (value_mem == -1) {
                context->get_stream() << "FUNCTION CALL PARAMETER DOES NOT EXIST" << std::endl;
                exit(EXIT_FAILURE);
            }
            else if (value_mem == -2) {
                context->get_stream() << "FUNCTION CALL PARAMETER DOES NOT EXIST" << std::endl;
                exit(EXIT_FAILURE);
            }

            //int var_reg = registers->get_free();
            //registers->write(var_reg, all_parameters[i]->get_id());
            
            if (debug_mode) {
                context->get_stream() << "#Calling func ID: " << all_parameters[i]->get_id() << std::endl;
                context->get_stream() << "#Storing this variable: " << i << std::endl;
            }

            //context->insert_parameters("int", all_parameters[i]->get_id(), i);
            int temp_reg = registers->get_free_reg();

            context->get_stream() << "lw $" << temp_reg << ", " << value_mem << "($fp)" << std::endl;

            context->get_stream() << "move $a" << i << ", $"<< temp_reg << std::endl;

            registers->erase_reg(temp_reg);

            //all_parameters[i]->get_id()->generate_assembly(context, registers, dest_reg);
        }
    }

    if (debug_mode) {
        context->get_stream() << "#Ending variable declaration" << std::endl;
    }
    
}

std::string ast_function_declarator::get_id() const {
    return "";
}

void ast_function_declarator::allocate_memory(int& allocated_mem) const {
    if ((all_parameters.size() > 0) && (all_parameters.size() <= 4)) {
        for (unsigned int i = 0; i < all_parameters.size(); i++) {
            all_parameters[i]->allocate_memory(allocated_mem);
        }
    }
}
