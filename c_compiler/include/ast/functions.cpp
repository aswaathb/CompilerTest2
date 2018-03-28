#include "functions.hpp"

ast_function::ast_function(ast_type* in_return_type, ast_identifier* in_id, std::vector<ast_function_parameters*> in_params, ast_compound_statement* in_stat) {
    ast_parameters = in_params;
    statements = in_stat;
    return_type = in_return_type;
    ID = in_id;
}

ast_function::ast_function(ast_type* in_return_type, ast_identifier* in_id, ast_compound_statement* in_stat) {
    statements = in_stat;
    return_type = in_return_type;
    ID = in_id;
}
//~ast_function() { }

void ast_function::xmlprint() const {
    std::cout << "<Function id=\"";
    ID->xmlprint();
    std::cout << "\">" << std::endl;

    for (unsigned int i =0; i < ast_parameters.size(); i++) {
        if (ast_parameters[i] != NULL) {
            ast_parameters[i]->xmlprint();
        }
    }
    
    std::cout << std::endl << "<Scope>" << std::endl;
    
    if (statements != NULL)
        statements->xmlprint();

    std::cout << "</Scope>" << std::endl;
    
    std::cout << "</Function>" << std::endl;
}


void ast_function::prettyprint(std::ostream &stream) const {

    stream << "Function id=\"";
    ID->prettyprint(stream);
    stream << "\" ";

    stream << " | Type: ";
    return_type->prettyprint(stream);

    stream << " | Parameters: " << std::endl;

    for (unsigned int i =0; i < ast_parameters.size(); i++) {
        ast_parameters[i]->prettyprint(stream);
        stream << " ";
    }
    stream << "Statements: " << std::endl;
    statements->prettyprint(stream);
}


void ast_function::allocate_memory(int& allocated_mem) const {
    for (unsigned int i =0; i < ast_parameters.size(); i++) {
        if (ast_parameters[i] != NULL) {
            ast_parameters[i]->allocate_memory(allocated_mem);
        }
    }

    if (statements != NULL)
        statements->allocate_memory(allocated_mem);
}


void ast_function::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {        
    context->get_stream()   <<      "\t.globl " << ID->get_id()                <<std::endl
                                    <<      "\t.set\tnomips16"                          <<std::endl
                                    <<      "\t.set\tnomicromips"                       <<std::endl
                                    <<      "\t.ent\t" << ID->get_id()                  <<std::endl
                                    <<      "\t.type\t" << ID->get_id()<<", @function"  <<std::endl
                                    <<ID->get_id() << ":"                               <<std::endl;


    int mem_needed = 4;
    allocate_memory(mem_needed);

    context->make_scope(ID->get_id(), std::string("function"), mem_needed*2 + 4);

    /*Get global variable
    if (ID->get_id() == "main") {
     for (unsigned int i = 0; i < load_dec.size(); i++) {
         load_dec.at(i).dec->generate_assembly(context, registers, load_dec.at(i).reg_num);
         
         context->get_stream() << "sw $" << load_dec.at(i).reg_num << ", " << load_dec.at(i).temp_mem*4 << "($fp)" << std::endl;

         context->get_stream() << "\tlui $2,%hi(" << load_dec.at(i).ID << ")" << std::endl;
         context->get_stream() << "\tsw  $" << load_dec.at(i).reg_num << ",%lo(" << load_dec.at(i).ID << ")($2)"<< std::endl;
         registers->erase_reg(load_dec.at(i).reg_num); 

     }   
    }*/

    //Reading parameter and saving it to temporary register/ stack
    //TODO: only works for < 4 parameters right now
    if ((ast_parameters.size() > 0) && (ast_parameters.size() <= 4)) {
        for (unsigned int i = 0; i < ast_parameters.size(); i++) {

            if (debug_mode)
                context->get_stream() << "#In function defintion: parameter id: " << ast_parameters.at(i)->get_id() << std::endl;

            int new_mem = registers->get_free_mem();

            context->insert_symbols("int", ast_parameters.at(i)->get_id(), new_mem, true);

            //context->get_stream() << "\tmove $" << new_mem << ", $a"<< i << std::endl;
            context->get_stream() << "\tsw $a" << i << ", " << new_mem*4 << "($fp)"  << std::endl;

            registers->write_mem(new_mem, "temp", context->get_current_func());

            //Binding each variable to each ID for access in function call
            context->insert_param_id(i, ast_parameters.at(i)->get_id());
            //int var_reg = registers->get_free();
            //registers->write(var_reg, ast_parameters[i]->get_id());

            //ast_parameters[i]->get_id()->generate_assembly(context, registers, dest_reg);                
        }
    }


    if (statements != NULL)
        statements->generate_assembly(context, registers, dest_reg);
    
    context->exit_function_scope();

    context->get_stream()   << std::endl
                            << "\t.set\tmacro"                                      << std::endl
                            << "\t.set\treorder"                                    << std::endl
                            << "\t.end\t"<<ID->get_id()                             << std::endl
                            << "\t.size\t"<<ID->get_id()<<", "<<".-"<<ID->get_id()  << std::endl
                            << "\t.align\t2"                                        << std::endl 
                                                                                     << std::endl;

}





ast_function_call::ast_function_call(ast_identifier* in_ID, std::vector<ast_base_expression*> in_args_list) {
    ID = in_ID;
    args_list = in_args_list;

}

ast_function_call::ast_function_call(ast_identifier* in_ID) {
    ID = in_ID;

}

void ast_function_call::xmlprint() const {
    //for (int i = 0; i < args_list.size(); ++i)
    //{
    //    args_list[i]->xmlprint();
    //}
}

void ast_function_call::prettyprint(std::ostream &stream) const {
    stream << "Function call:" << std::endl;
    stream << "ID: ";
    ID->prettyprint(stream);

    for (unsigned int i = 0; i < args_list.size(); i++) {
        args_list[i]->prettyprint(stream);
        stream << " ";
    }
    stream << std::endl;
}

void ast_function_call::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    bool temp_save_math_op = save_math_op;
    save_math_op = false;
    
    //Save all the 'Save' registers


    int old_a0_mem = registers->get_free_mem();
    registers->write_mem(old_a0_mem, std::string("temp"), context->get_current_func());
    int old_a1_mem = registers->get_free_mem();
    registers->write_mem(old_a1_mem, std::string("temp"), context->get_current_func());
    int old_a2_mem = registers->get_free_mem();
    registers->write_mem(old_a2_mem, std::string("temp"), context->get_current_func());
    int old_a3_mem = registers->get_free_mem();
    registers->write_mem(old_a3_mem, std::string("temp"), context->get_current_func());

    if ((args_list.size() > 0) && (args_list.size() <= 4)) {

        for (unsigned int i = 0; i < args_list.size(); i++) {
            if (i == 0){
                context->get_stream() << "\tsw $a0" << ", " << old_a0_mem*4 << "($fp)"  << std::endl;
            }
            else if (i == 1) {
                context->get_stream() << "\tsw $a1" << ", " << old_a1_mem*4 << "($fp)"  << std::endl;
            }
            else if (i == 2) {
                context->get_stream() << "\tsw $a2" << ", " << old_a2_mem*4 << "($fp)"  << std::endl;
            }
            else if (i == 3) {
                context->get_stream() << "\tsw $a3" << ", " << old_a3_mem*4 << "($fp)"  << std::endl;
            }

            int temp_reg = registers->get_free_reg();
            registers->write_reg(temp_reg, std::string("temp"));
            args_list.at(i)->generate_assembly(context, registers, temp_reg);
            
            if (debug_mode) {
                context->get_stream() << "\t#Calling func call: " << args_list[i]->get_id() << std::endl;
                context->get_stream() << "\t#Storing this variable: " << i << std::endl;
                context->get_stream() << "\t#Dest_reg: " <<dest_reg << std::endl;

            }

            //context->insert_parameters("int", args_list[i]->get_id(), i);
            context->get_stream() << "\tmove $a" << i << ", $"<< temp_reg << std::endl;

            //registers->erase_reg(temp_reg);

            //args_list[i]->get_id()->generate_assembly(context, registers, dest_reg);
        }
    }

    context->get_stream() << "\t.option pic0 " << std::endl;
    context->get_stream() << "\tjal " << ID->get_id() << std::endl;
    context->get_stream() << "\tnop" << std::endl;
    context->get_stream() << "\t.option pic2 " << std::endl;

    /*for (int i = 0; i < func_call_store.size(); i++) {
    //    context->get_stream() << "lw $" << func_call_store.at(i).reg << "," << func_call_store.at(i).mem*4 << "($fp) #THIS ONE!" << std::endl;
    }*/     
    registers->reallocate(context->get_current_func());

    //Setting the integer to the return
    
    context->get_stream() << "\tmove $" << dest_reg << ", $2" << std::endl;
    int new_mem = registers->get_free_mem();
    context->get_stream() << "\tsw $" << dest_reg << ", " << new_mem*4 << "($fp)" << std::endl;
    registers->write_mem(dest_reg, std::to_string(new_mem), context->get_current_func());
    
    //Redeclare variables
    if ((args_list.size() > 0) && (args_list.size() <= 4)) {
        for (unsigned int i = 0; i < args_list.size(); i++) {
            if (i == 0)
                context->get_stream() << "\tlw $a0, " << old_a0_mem*4 << "($fp)"<< std::endl;
            else if (i == 1)
                context->get_stream() << "\tlw $a1, " << old_a1_mem*4 << "($fp)"<< std::endl;
            else if (i == 2)
                context->get_stream() << "\tlw $a2, " << old_a2_mem*4 << "($fp)"<< std::endl;
            else if (i == 3)
                context->get_stream() << "\tlw $a3, " << old_a3_mem*4 << "($fp)"<< std::endl;
        }           
    }

    registers->erase_mem(old_a0_mem);
    registers->erase_mem(old_a1_mem);
    registers->erase_mem(old_a2_mem);
    registers->erase_mem(old_a3_mem);

    save_math_op = temp_save_math_op;
}

int ast_function_call::constant_fold() const {
    std::cerr << "Trying to constant fold a function!" << std::endl;
    return 0;
}

void ast_function_call::allocate_memory(int& allocated_mem) const {
    for (unsigned int i = 0; i < args_list.size(); i++) {
        if (args_list[i] != NULL) {
            args_list[i]->allocate_memory(allocated_mem);
        }
    }
    
}
