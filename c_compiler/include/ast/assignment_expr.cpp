#include "assignment_expr.hpp"

bool save_math_op;

ast_assignment_expression::~ast_assignment_expression() {
    delete left;
    delete right;
}


ast_assign_equal::ast_assign_equal(ast_base_expression *_left, ast_base_expression *_right)  {
    left = _left;
    right = _right;
}

void ast_assign_equal::xmlprint() const {
	
}

std::string ast_assign_equal::get_id() const{
    return left->get_id();
}

void ast_assign_equal::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
        save_math_op = true;

        if (debug_mode)
            context->get_stream() << "#This is assign equals. Left ID: " << left->get_id() << std::endl;
        //If ID is not already in there
        int temp_mem;

        int reg_value = context->find_variable(left->get_id());
        int temp_reg = registers->get_free_reg();
        if (reg_value == -1) {
            temp_mem = registers->get_free_mem();
            //CHANGED TEMP REG HERE
            registers->write_mem(temp_reg, std::to_string(temp_mem), context->get_current_func());
        }
        else if (reg_value != -1 && reg_value != -2){
            temp_mem = reg_value;
        }
        if (right != NULL)
            right->generate_assembly(context, registers, temp_reg);

        if (reg_value == -2) {
            context->get_stream() << "\t#Could not find declaration, assuming global variable" << std::endl;
            
            context->get_stream() << "\tlui $2,%hi(" << left->get_id() << ")" << std::endl;
            context->get_stream() << "\tsw  $" << temp_reg << ",%lo(" << left->get_id() << ")($2)"<< std::endl;
            
        }
        else {
            context->get_stream() << "\tsw $" << temp_reg << ", " << temp_mem*4 << "($fp)" << std::endl;
            std::string id = left->get_id();
            context->insert_symbols(std::string("Int"), id, temp_mem, false);
            registers->erase_reg(temp_reg);
            if (debug_mode)
                context->get_stream() << "#Using temp reg: " << temp_reg << std::endl;
            //registers->erase(temp_reg_1);
            if (debug_mode)
                context->get_stream() << "#Ending assign equals." << std::endl;
        }
        save_math_op = false;
}


void ast_assign_equal::prettyprint(std::ostream &stream) const{
    stream << "Performing an assignment expression: " << std::endl
            << "\t With left expression:" << std::endl;
    left->prettyprint(stream);
    stream << "\t With right expression:" <<std::endl;
    right->prettyprint(stream);
    stream << std::endl;
    stream << std::endl;
}

void ast_assign_equal::allocate_memory(int& allocated_mem) const {
    allocated_mem += 4;
}

int ast_assign_equal::constant_fold() const {
    return right->constant_fold();
}





ast_array_initialiser::ast_array_initialiser(std::vector<ast_base_expression*> in_init)
    : init_list (in_init) { }

ast_array_initialiser::ast_array_initialiser(ast_base_expression* in_list){ 
    init_list.push_back(in_list);
}

void ast_array_initialiser::xmlprint() const {
    
}

void ast_array_initialiser::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    ;
}

std::string ast_array_initialiser::get_id() const{
    return "array initaliser id";
}

void ast_array_initialiser::prettyprint(std::ostream &stream) const{
    stream  << "#Initialising an array with the values: " << std::endl;
    for (unsigned int i = 0; i < init_list.size(); ++i)
    {
        if (init_list.at(i) != NULL) {
            stream << "number " << i << ":"; 
            init_list.at(i)->prettyprint(stream);
            stream << std::endl; 
        }
    }
}

void ast_array_initialiser::allocate_memory(int& allocated_mem) const {
    for (unsigned int i = 0; i < init_list.size(); i++) {
        allocated_mem += 4;
    }
}

int ast_array_initialiser::constant_fold() const {
    std::cerr << "Array not supported as global variables." << std::endl;
    return 0;
}




ast_size_of_expr::ast_size_of_expr(ast_base_expression* in_expr) : expr(in_expr), type(NULL) {}

ast_size_of_expr::ast_size_of_expr(ast_type* in_type) : expr(NULL), type(in_type) { }

void ast_size_of_expr::xmlprint() const {
    
}

void ast_size_of_expr::generate_assembly(ast_context* context, mips_registers* registers, int& dest_reg) const {
    if (expr!=NULL)
        expr->generate_assembly(context, registers, dest_reg);
    
    context->get_stream() << "li\t$" << dest_reg << ",\t4\t#Sizeof does not consider pointers and arrays" << std::endl;
}

void ast_size_of_expr::prettyprint(std::ostream &stream) const{
    stream  << "Size of: " << std::endl;
}

void ast_size_of_expr::allocate_memory(int& allocated_mem) const {
    ;
}

int ast_size_of_expr::constant_fold() const {
    std::cerr << "Size of is not a valid const fold" << std::endl;
    return 0;
}